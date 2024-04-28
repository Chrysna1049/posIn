#include "storage.h"
#include <QVariant>
#include <QDebug>
#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QFile>

storage::storage() {
}
storage::storage(const storage& orig){

}
storage::~storage() {
}

bool checkConfigFileExists(const QString& configFilePath) {
    QFile file(configFilePath);
    return file.exists();
}

int storage::initialize(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString fileConfig = appDirPath +"/config.ini";
    if (!checkConfigFileExists(fileConfig)) {
        qDebug() << "Config file not found at" << fileConfig;
        QMessageBox::critical(nullptr, "Error", "File konfigurasi tidak ditemukan." + fileConfig);

        return -1;
    }
    QSettings settings(fileConfig, QSettings::IniFormat);

    QString hostName = settings.value("Database/HostName").toString();
    QString databaseName = settings.value("Database/DatabaseName").toString();
    QString userName = settings.value("Database/UserName").toString();
    QString password = settings.value("Database/Password").toString();

    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
    if (!db.open()) {
         qDebug() << "Error: Could not open database:" << db.lastError().text();
        isInitialize = false;
        return -1;
    }
    isInitialize = true;
    return 0;
}

int storage::save_transasction_data(QString uuid, QString data_plat, QString time_in, QString time_out, QString ticket, QString jenis_kendaraan, QString jenis_parkir){
    if(isInitialize){
        QSqlQuery query;
        query.prepare("INSERT INTO transaction (data_uuid, data_plat_kendaraan, data_datetime_in, data_datetime_out, data_ticket, data_jenis_kendaraan, data_jenis_parkir) VALUE (:uuid, :plat_kendaraan, :time_in, :time_out, :ticket, :j_kendaraan, :j_parkir)");
        query.bindValue(":uuid",uuid);
        query.bindValue(":plat_kendaraan", data_plat);
        query.bindValue(":time_in", time_in);
        query.bindValue(":time_out", time_out);
        query.bindValue(":ticket", ticket);
        query.bindValue(":j_kendaraan", jenis_kendaraan);
        query.bindValue(":j_parkir", jenis_parkir);

        if(!query.exec()){
             qDebug() << "Error: " << query.lastError().text();
            return -1;
        }
    }else{
        qDebug() << "Error: ";
        return -2;
    }
    return 0;
}

bool storage::canContinueTransaction(QString &plat_kendaraan){
    QString result;
    if(isInitialize){
        QSqlQuery query;
        query.prepare("SELECT data_datetime_out FROM transaction WHERE data_plat_kendaraan = :plat_kendaraan ORDER BY data_datetime_out DESC LIMIT 1");
        query.bindValue(":plat_kendaraan", plat_kendaraan);
        if (query.exec()) {
            if (query.next()) {
                result = query.value(0).toString();
                if(result.isEmpty()){
                    return false;
                }else{
                    return true;
                }
            } else {
                return true;
            }
         } else {
             qDebug() << "Error executing query:" << query.lastError().text();
             return false;
         }
        return true;
    }
}

