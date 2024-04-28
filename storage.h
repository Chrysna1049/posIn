#ifndef STORAGE_H
#define STORAGE_H
// #include<qt5/QtSql/QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class storage
{
public:
    storage();
    storage(const storage& orig);
    ~storage();

    int  initialize();
    int save_transasction_data(QString uuid, QString data_plat, QString time_in, QString time_out, QString ticket, QString jenis_kendaraan, QString jenis_parkir);
    bool canContinueTransaction(QString &plat_kendaraan);
private:
    bool isInitialize = false;

};

#endif // STORAGE_H
