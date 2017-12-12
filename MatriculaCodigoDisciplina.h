#ifndef MATRICULACODIGODISCIPLINA_H
#define MATRICULACODIGODISCIPLINA_H
#include "Interface.h"

namespace TP2{

class MatriculaCodigoDisciplina : public Interface
{
private:
    long matricula;
    QStringList codigo;
public:
    MatriculaCodigoDisciplina();
    long getMatricula()const{return this->matricula;}
    QStringList getCodigo()const{return this->codigo;}
    void setMatricula(){this->matricula = matricula;}
    void montarObjeto(QString &str);
};

}
#endif // MATRICULACODIGODISCIPLINA_H
