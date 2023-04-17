#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>

class IDataBase
{  

public:
    virtual QString getTarget() = 0;
    virtual bool checkWord (QString word) = 0;

};

#endif // IDATABASE_H
