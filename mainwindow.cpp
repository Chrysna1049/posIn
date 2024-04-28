#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *ev) {
    QWidget::showEvent(ev);
    QMetaObject::invokeMethod(this, "afterWindowShown", Qt::ConnectionType::DirectConnection);
}

void MainWindow::afterWindowShown(){
    if((database = new storage()) != nullptr){
        if(database->initialize() == 0){
            // QMessageBox::information(this, "Initialize database", "Berhasil init database");
        }else{
            QMessageBox::critical(nullptr, "Error", "Database tidak ditemukan atau gagal diinisialisasi");
            QCoreApplication::exit(-1);
            return;
        }
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setDateTime()));
    timer->start(1000);
    setListKendaraan();
    setListParkir();
    showFullscreenWindows();
    setIcon();
    start_camera();
}

void MainWindow::start_camera(){
    auto availableDevices = QCamera::availableDevices();
    if (availableDevices.isEmpty()) {
        qDebug() << "No camera available";
        return;
    }
    for(const QCameraInfo &infor : QCameraInfo::availableCameras()){
        qDebug() << "Camera info" << infor.description();
    }
    camera = new QCamera(availableDevices.at(0), this);
    camera->setViewfinder(ui->widget_camera);
    camera->start();
}

void MainWindow::setListKendaraan(){
    QFile file(":/data/config/list_kendaraan");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Tidak bisa membuka file /data/config/list_kendaraan");
        return;
    }

    QTextStream in(&file);
    ui->List_Kendaraan->clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty()) {
            ui->List_Kendaraan->addItem(line);
        }
    }
    file.close();
}

void MainWindow::setListParkir(){
    QFile file (":/data/config/list_parkir");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Tidak bisa membuka file :/data/config/list_parkir");
        return;
    }
    QTextStream in(&file);
    ui->list_parkir->clear();
    while(!in.atEnd()){
        QString line = in.readLine();
        if(!line.isEmpty()){
            ui->list_parkir->addItem(line);
        }
    }
}

void MainWindow::setDateTime(){
    ui->date_time_label->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy HH:mm:ss"));
}

void MainWindow::keyPressEvent(QKeyEvent *event)  {
    int key  = event->key();
    QString Textkey = QKeySequence(key).toString();
    if (key == Qt::Key_F1) {
        QString No_Kendaraan = ui->input_plat->text();
        QString Jenis_kendaraan = ui->List_Kendaraan->currentText();
        QString Jenis_parkir = ui->list_parkir->currentText();

        No_Kendaraan = No_Kendaraan.toUpper();
        No_Kendaraan = No_Kendaraan.remove("");

        if(No_Kendaraan.isEmpty()){
            QMessageBox::warning(this, "WARNING", "No Kendaraan Belum Dimasukkan");
        }else{
            bool data_out = database->canContinueTransaction(No_Kendaraan);
            if(data_out){
                QString ticket = GenerateTicket();
                QString uuid  = GenerateUUID();
                QDateTime now = QDateTime::currentDateTime();
                QString datetime_in = now.toString("yyyy-MM-dd HH:mm:ss");
                int rv = database->save_transasction_data(uuid, No_Kendaraan, datetime_in, "", ticket, Jenis_kendaraan, Jenis_parkir);
                QString rv_string = QString::number(rv);
                if(rv == 0){
                    ui->label_plat->setText(No_Kendaraan);
                    QPrinter printer;
                    QPrintPreviewDialog previewDialog(&printer, this);
                    connect(&previewDialog, &QPrintPreviewDialog::paintRequested, this, [&](){
                        creatstruck(&printer, No_Kendaraan, ticket, datetime_in);
                    });
                    previewDialog.exec();
                }else{
                      QMessageBox::warning(this, "WARNING", "Transaksi Gagal Disimpan" + rv_string);
                }
            }else{
                QMessageBox::warning(this, "WARNING", "Kendaraan Belum Keluar dari Parkiran");
            }
        }
    }
    if(key == Qt::Key_F2){
        ui->List_Kendaraan->showPopup();
    }
    if(key == Qt::Key_F3){
        ui->input_plat->setFocus();
    }
    if(key == Qt::Key_F4){
        ui->list_parkir->showPopup();
    }
    if(key == Qt::Key_F5){
        ui->input_plat->clear();
        ui->label_plat->clear();
    }
    if (event->key() == Qt::Key_Escape && event->modifiers() & Qt::AltModifier ) {
        QApplication::quit();
    }
}

void MainWindow::showFullscreenWindows(){
    ui->input_plat->setPlaceholderText("Masukkan No Kendaraan");
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();
    setCursor(Qt::BlankCursor);
}

void MainWindow::setIcon(){
    QPixmap logoParkee(":/data/img/logo.png");
    int targetWidth = 680;
    int targetHeight = 100;

    QPixmap scaledlogoparkee = logoParkee.scaled(targetWidth,targetHeight);
    ui->logo_parkee->setPixmap(scaledlogoparkee);
}

QString MainWindow::GenerateTicket(){
    QString ticket;
    QRandomGenerator *generator = QRandomGenerator::global();

    for (int i = 0; i < 10; ++i) {
        int randomNumber = generator->bounded(0, 10);
        ticket += QString::number(randomNumber);
    }
    return ticket;
}

QString MainWindow::GenerateUUID(){
    QUuid uuid = QUuid::createUuid();
    return uuid.toString(QUuid::WithoutBraces);
}

void MainWindow::creatstruck(QPrinter *printer, const QString plat, const QString ticket, const QString time_in){
    QPainter painter(printer);
    QFont font("Courier", 10);
    painter.setFont(font);

    int paperWidth = 1000;
    int y = 100;

    QFontMetrics metrics(font);

    int xCenter = (paperWidth - metrics.width("Parking Ticket")) / 2;
    painter.drawText(xCenter, y, "Parking Ticket");
    y += 50;

    xCenter = (paperWidth - metrics.width("PM 1 - Parkee")) / 2;
    painter.drawText(xCenter, y, "PM 1 - Parkee");
    y += 50;

    xCenter = (paperWidth - metrics.width("No. Ticket : " + ticket)) / 2;
    painter.drawText(xCenter, y, "No. Ticket : " + ticket);
    y += 50;

    xCenter = (paperWidth - metrics.width("Waktu Masuk : " + time_in)) / 2;
    painter.drawText(xCenter, y, "Waktu Masuk : " + time_in);
    y += 50;

    QPixmap barcode = creatBarcode(ticket);
    int barcodeX = (paperWidth - barcode.width()) / 2;
    painter.drawPixmap(barcodeX, 300, barcode);
    y += 150;

    xCenter = (paperWidth - metrics.width("Jangan meninggalkan ticket & barang berharga")) / 2;
    painter.drawText(xCenter, y, "Jangan meninggalkan ticket & barang berharga");

    painter.end();
}

QPixmap MainWindow::creatBarcode(const QString &ticket){
    QTemporaryFile tempFile;
    tempFile.open();
    QString tempFileName = tempFile.fileName() + ".png";
    QProcess proces;
    proces.start("zint", {"-o", tempFileName, "-b", "20", "-d", ticket});
    proces.waitForFinished();
    QPixmap barcode;
    barcode.load(tempFileName);
    return barcode;

}
