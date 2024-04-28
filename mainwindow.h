#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QFile>
#include <QPixmap>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>
#include <QStringBuilder>
#include <QString>
#include <QUuid>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QTemporaryFile>
#include <QFontMetrics>
#include <QFont>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setListKendaraan();
    void setListParkir();
    void showFullscreenWindows();
    void setIcon();
    QString GenerateTicket();
    QString GenerateUUID();
    void creatstruck(QPrinter *printer, const QString plat, const QString ticket, const QString time_in);
    QPixmap creatBarcode(const QString &ticket);

protected:
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *ev);

private slots:
    void setDateTime();
    void afterWindowShown();

private:
    void start_camera();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer_route;
    QCamera *camera;
    storage *database;
};
#endif // MAINWINDOW_H
