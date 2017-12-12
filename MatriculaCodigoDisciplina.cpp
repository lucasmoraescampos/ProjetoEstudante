#include "MatriculaCodigoDisciplina.h"

namespace TP2{

MatriculaCodigoDisciplina::MatriculaCodigoDisciplina():
    matricula(0),
    codigo("")
{

}

void MatriculaCodigoDisciplina::montarObjeto(QString &str){
    try {
        QStringList strList = str.split(',');
        QStringList end = str.split("");
        this->matricula = strList[0].toLong();
        int i = 1;
        while(i < strList.size()){
            this->codigo.push_back(strList[i]);
            i++;
        }
        this->codigo.push_back(end[0]);

    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

}
