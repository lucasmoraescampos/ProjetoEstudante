#include "MatriculaNome.h"

namespace TP2{

MatriculaNome::MatriculaNome():
    matricula(0),
    nome("")
{

}

void MatriculaNome::montarObjeto(QString &str){
    try {
        QStringList strList = str.split(';');
        if(strList.length() != 2) throw ;
        this->matricula = strList[0].toLong();
        this->nome = strList.at(1);
    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

}
