#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <QString>


class Exception: public std::exception
{
private:
    QString error;

public:
    Exception(QString e)
        : error(e)
    {}
    Exception () { error = ""; }


    QString whatError() const noexcept
    {
        return error;
    }
};


#endif // EXCEPTION_H
