#ifndef INTERFACE_H
#define INTERFACE_H
#include<QString>
#include<QStringList>

namespace TP2{

class Interface
{
public:
    virtual void montarObjeto(QString &str) = 0;
};

}
#endif // INTERFACE_H
