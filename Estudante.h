#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include<QString>
#include <vector>
#include<list>
#include<stack>
#include "CodigoDisciplinaCH.h"
#include "MatriculaCodigoDisciplina.h"
#include "MatriculaNome.h"
#include<QMessageBox>
#include<fstream>

namespace TP2{

class Estudante
{
public:
    QString nomeDoArquivoNoDisco;
public:
    Estudante(QString nomeDoArquivoNoDisco);
    std::vector<long> listarMatriculas(QString codigo);
    std::list<TP2::MatriculaNome>* matriculasNome(std::vector<long> matriculas);
    void verificarCodigos(QString codigo);
    TP2::CodigoDisciplinaCH disciplinaCH(QString codigo);
    std::vector<QString> listarCodigos(long matricula);
    std::list<CodigoDisciplinaCH>* codigoDisciplinaCH(std::vector<QString> codigos);
    TP2::MatriculaNome nome(long matricula);
    void verificarMatriculas(long matricula);
    QString desmontarObjeto1(std::list<TP2::MatriculaNome>* lista)const;
    QString desmontarObjeto2(std::list<TP2::CodigoDisciplinaCH> *lista)const;

};

}
#endif // ESTUDANTE_H
