#ifndef CODIGODISCIPLINACH_H
#define CODIGODISCIPLINACH_H
#include "Interface.h"

namespace TP2{

class CodigoDisciplinaCH : public Interface
{
private:
    QString codigo;
    QString disciplina;
    int cargaHoraria;
public:
    CodigoDisciplinaCH();
    QString getCodigo()const{return this->codigo;}
    QString getDisciplina()const{return this->disciplina;}
    int getCargaHoraria()const{return this->cargaHoraria;}
    void setCodigo(QString codigo){this->codigo = codigo;}
    void setDisciplina(QString disciplina){this->disciplina = disciplina;}
    void setCargaHoraria(int cH){this->cargaHoraria = cH;}
    void montarObjeto(QString &str);
};

}
#endif // CODIGODISCIPLINACH_H
