#ifndef SQLITEDB_H
#define SQLITEDB_H


#include <QtSql>
#include <ctime>
#include "idatabase.h"
#include "exception.h"

class SQLiteDB : public IDataBase
{
public:
    SQLiteDB();
    QString getTarget() override;
    bool checkWord (QString word) override;

private:
    QSqlDatabase dbase;
    QSqlQuery q;
    int numberOfRecords;
};

#endif // SQLITEDB_H
