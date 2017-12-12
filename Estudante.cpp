#include "Estudante.h"

namespace TP2{

Estudante::Estudante(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}

bool operator < (TP2::MatriculaNome &p1, TP2::MatriculaNome &p2)
{
    if (p1.getNome() < p2.getNome())
        return true;
    else return false;
}

bool operator < (TP2::CodigoDisciplinaCH &p1, TP2::CodigoDisciplinaCH &p2)
{
    if (p1.getDisciplina() < p2.getDisciplina())
        return true;
    else return false;
}

std::vector<long> Estudante::listarMatriculas(QString codigo)
{
    try{
        this->verificarCodigos(codigo);
        std::ifstream arquivoDisciplinas;
        arquivoDisciplinas.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoDisciplinas.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::vector<long> matriculas;
        std::string linha;
        getline(arquivoDisciplinas, linha);
        while(!arquivoDisciplinas.eof()){
            TP2::MatriculaCodigoDisciplina objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            int i = 0;
            while(i < objeto.getCodigo().size()-1){
                if(objeto.getCodigo().at(i) == codigo){
                    matriculas.push_back(objeto.getMatricula());
                    break;
                }
                i++;
            }
            getline(arquivoDisciplinas,linha);
        }
        arquivoDisciplinas.close();
        return matriculas;
    } catch (QString &erro) {
        throw(erro);
    }
}

std::list<TP2::MatriculaNome> *Estudante::matriculasNome(std::vector<long> matriculas)
{
    try{
        std::ifstream arquivoDisciplinas;
        arquivoDisciplinas.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoDisciplinas.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::list<TP2::MatriculaNome>* lista = new std::list<TP2::MatriculaNome>();
        std::list<TP2::MatriculaNome>* clone = new std::list<TP2::MatriculaNome>();
        std::string linha;
        getline(arquivoDisciplinas, linha);
        while(!arquivoDisciplinas.eof()){
            TP2::MatriculaNome objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            int i = 0;
            while(i < matriculas.size()){
                if(matriculas[i] == objeto.getMatricula()){
                    lista->push_back(objeto);
                    clone->push_back(objeto);
                }
                i++;
            }
            getline(arquivoDisciplinas,linha);
        }
        arquivoDisciplinas.close();
        lista->sort();
        clone->sort();

        std::ofstream arquivo;
        arquivo.open("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/temp.csv");  //**************************Mudar caminho********************
        if(!arquivo.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
        }
        arquivo<<desmontarObjeto1(clone).toStdString();
        arquivo.close();

        delete clone;
        return lista;
    }catch (QString &erro){
        throw(erro);
    }
}

TP2::CodigoDisciplinaCH Estudante::disciplinaCH(QString codigo)
{
    try{
        std::ifstream arquivoDisciplinas;
        arquivoDisciplinas.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoDisciplinas.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::string linha;
        getline(arquivoDisciplinas, linha);
        while(!arquivoDisciplinas.eof()){
            TP2::CodigoDisciplinaCH objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            if(objeto.getCodigo() == codigo){
                arquivoDisciplinas.close();
                return objeto;
            }
            getline(arquivoDisciplinas,linha);
        }
    }catch (QString &erro){
        throw(erro);
    }
}

void Estudante::verificarCodigos(QString codigo)
{
    try{
        if(codigo == "")
            throw QString("Informe o Codigo!");
        std::stack<QString> pilha;
        std::ifstream arquivoCodigos;
        arquivoCodigos.open("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/CodigoDisciplinaCH.csv");  //**************************Mudar caminho********************
        std::string linha;
        getline(arquivoCodigos,linha);
        while(!arquivoCodigos.eof()){
            TP2::CodigoDisciplinaCH objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            pilha.push(objeto.getCodigo());
            getline(arquivoCodigos,linha);
        }
        bool aux = false;
        while(!pilha.empty()){
            if(codigo == pilha.top()){
                aux = true;
                break;
            }
            pilha.pop();
        }
        if(aux == false)
            throw QString("Codigo Inexistente!");
        arquivoCodigos.close();
    }catch (QString &erro){
        throw(erro);
    }
}

std::vector<QString> Estudante::listarCodigos(long matricula)
{
    try{
        std::ifstream arquivoCodigos;
        arquivoCodigos.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoCodigos.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::vector<QString> codigos;
        std::string linha;
        getline(arquivoCodigos, linha);
        while(!arquivoCodigos.eof()){
            TP2::MatriculaCodigoDisciplina objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            if(objeto.getMatricula() == matricula){
                int i = 0;
                while(i < objeto.getCodigo().size()){
                    if(objeto.getCodigo().at(i) != "")
                        codigos.push_back(objeto.getCodigo().at(i));
                    i++;
                }
                break;
            }
            getline(arquivoCodigos,linha);
        }
        arquivoCodigos.close();
        return codigos;
    } catch (QString &erro) {
        throw(erro);
    }
}

std::list<TP2::CodigoDisciplinaCH>* Estudante::codigoDisciplinaCH(std::vector<QString> codigos)
{
    try{
        std::ifstream arquivoDisciplinas;
        arquivoDisciplinas.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoDisciplinas.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::string linha;
        std::list<TP2::CodigoDisciplinaCH>* lista = new std::list<TP2::CodigoDisciplinaCH>();
        std::list<TP2::CodigoDisciplinaCH>* clone = new std::list<TP2::CodigoDisciplinaCH>();
        getline(arquivoDisciplinas, linha);
        while(!arquivoDisciplinas.eof()){
            TP2::CodigoDisciplinaCH objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            int i = 0;
            while(i < codigos.size()){
                if(objeto.getCodigo() == codigos[i]){
                    lista->push_back(objeto);
                    clone->push_back(objeto);
                    break;
                }
                i++;
            }
            getline(arquivoDisciplinas,linha);
        }
        arquivoDisciplinas.close();
        lista->sort();
        clone->sort();

        std::ofstream arquivo;
        arquivo.open("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/temp.csv"); //**************************Mudar caminho********************
        if(!arquivo.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir"); //**************************Mudar caminho********************
        }
        arquivo<<desmontarObjeto2(clone).toStdString();
        arquivo.close();

        delete clone;
        return lista;
    }catch (QString &erro){
        throw(erro);
    }
}

TP2::MatriculaNome Estudante::nome(long matricula)
{
    try{
        this->verificarMatriculas(matricula);
        std::ifstream arquivoNome;
        arquivoNome.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoNome.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        std::string linha;
        getline(arquivoNome, linha);
        while(!arquivoNome.eof()){
            TP2::MatriculaNome objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            if(objeto.getMatricula() == matricula){
                arquivoNome.close();
                return objeto;
            }
            getline(arquivoNome,linha);
        }
    }catch (QString &erro){
        throw(erro);
    }
}

void Estudante::verificarMatriculas(long matricula)
{
    try{
        std::stack<long> pilha;
        std::ifstream arquivoMat;
        arquivoMat.open("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/MatriculaNome.csv"); //**************************Mudar caminho********************
        std::string linha;
        getline(arquivoMat,linha);
        while(!arquivoMat.eof()){
            TP2::MatriculaNome objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarObjeto(str);
            pilha.push(objeto.getMatricula());
            getline(arquivoMat,linha);
        }
        bool aux = false;
        while(!pilha.empty()){
            if(matricula == pilha.top()){
                aux = true;
                break;
            }
            pilha.pop();
        }
        if(aux == false)
            throw QString("Matricula Inexistente!");
        arquivoMat.close();
    }catch (QString &erro){
        throw(erro);
    }
}

QString Estudante::desmontarObjeto1(std::list<MatriculaNome> *lista)const{
    QString saida = "";
    while(!lista->empty()){
        TP2::MatriculaNome objeto = lista->front();
        saida += QString::number(objeto.getMatricula());
        saida += ";";
        saida += objeto.getNome();
        saida += "\n";
        lista->pop_front();
    }
    return saida;
}

QString Estudante::desmontarObjeto2(std::list<CodigoDisciplinaCH> *lista)const{
    QString saida = "";
    while(!lista->empty()){
        TP2::CodigoDisciplinaCH objeto = lista->front();
        saida += objeto.getCodigo();
        saida += ";";
        saida += objeto.getDisciplina();
        saida += ";";
        saida += QString::number(objeto.getCargaHoraria());
        saida += "\n";
        lista->pop_front();
    }
    return saida;
}

}
