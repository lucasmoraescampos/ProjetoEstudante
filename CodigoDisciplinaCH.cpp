#include "CodigoDisciplinaCH.h"

namespace TP2{

CodigoDisciplinaCH::CodigoDisciplinaCH():
    codigo(""),
    disciplina(""),
    cargaHoraria(0)
{
}

void CodigoDisciplinaCH::montarObjeto(QString &str){
    try {
        QStringList strList = str.split(';');
        if(strList.length() != 3) throw ;
        this->codigo = strList[0];
        this->disciplina = strList[1];
        this->cargaHoraria = strList[2].toInt();

    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

}

