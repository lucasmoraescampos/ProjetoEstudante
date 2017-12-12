#ifndef MATRICULANOME_H
#define MATRICULANOME_H
#include "Interface.h"

namespace TP2{

class MatriculaNome : public Interface
{
private:
    long matricula;
    QString nome;
public:
    MatriculaNome();
    long getMatricula()const{return this->matricula;}
    QString getNome()const{return this->nome;}
    void setMatricula(long matricula){this->matricula = matricula;}
    void setNome(QString nome){this->nome = nome;}
    void montarObjeto(QString &str);
};

}
#endif // MATRICULANOME_H
