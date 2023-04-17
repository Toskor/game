#include "sqlitedb.h"

SQLiteDB::SQLiteDB()
{
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("rus_words.sqlite");

    dbase.open();

    q = QSqlQuery( dbase );
    q.exec( "SELECT COUNT(*) FROM rus_words" );

    if ( q.next() )
        numberOfRecords = q.value(0).toInt();

    else
    {
        dbase.close();
        throw (Exception ("БД не открыта") );
    }


}

QString SQLiteDB::getTarget()
{
    QString target = "";

    srand( time(0) );
    int id = rand() % numberOfRecords + 1;

    QString request = "SELECT * FROM rus_words WHERE id=";
    request += QString::number(id);

    q.exec( request );

    q.next();
    target = q.value(1).toString();

    return target;
}

bool SQLiteDB::checkWord(QString word)
{
    QString request = "SELECT EXISTS (SELECT * FROM rus_words where words = \'";
    request += word + "\')";

    q.exec( request );
    q.next();

    return q.value(0).toBool();
}
