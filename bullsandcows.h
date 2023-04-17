#ifndef BULLSANDCOWS_H
#define BULLSANDCOWS_H

#include <vector>
#include <QTextStream>
#include <QTextCodec>
#include "sqlitedb.h"
#include "idatabase.h"

class BullsAndCows
{
public:
    BullsAndCows();
    void game();

private:
    IDataBase *database;
    QTextStream cout{ stdout };
    QTextStream cin{ stdin };

};

#endif // BULLSANDCOWS_H
