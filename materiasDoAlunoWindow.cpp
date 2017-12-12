#include "materiasDoAlunoWindow.h"
#include "ui_materiasDoAlunoWindow.h"

materiasDoAlunoWindow::materiasDoAlunoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiasDoAlunoWindow)
{
    ui->setupUi(this);
    ui->tableWidgetDados->setColumnWidth(1,408);//tamanho da Grid
}

materiasDoAlunoWindow::~materiasDoAlunoWindow()
{
    std::remove("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/temp.csv"); //**************************Mudar caminho********************
    delete ui;
}

void materiasDoAlunoWindow::on_pushButtonBuscar_clicked()
{
    try{
        long matricula = ui->lineEditMatricula->text().toLong();

        TP2::Estudante file1("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/MatriculaCodigoDisciplina.csv"); //**************************Mudar caminho********************
        std::vector<QString> vetor = file1.listarCodigos(matricula);

        TP2::Estudante file2("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/CodigoDisciplinaCH.csv"); //**************************Mudar caminho********************
        std::list<TP2::CodigoDisciplinaCH>* lista = file2.codigoDisciplinaCH(vetor);

        TP2::Estudante file3("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/MatriculaNome.csv"); //**************************Mudar caminho********************
        TP2::MatriculaNome nome = file3.nome(matricula);

        ui->tableWidgetDados->setColumnWidth(1,391);//tamanho da Grid

        ui->tableWidgetDados->setRowCount(0);
        ui->labelNome->setText(nome.getNome());
        //Montando a Grid
        while(!lista->empty()){
            QTableWidgetItem *itemCodigo = new QTableWidgetItem(lista->front().getCodigo());
            QTableWidgetItem *itemDisciplina = new QTableWidgetItem(lista->front().getDisciplina());
            QTableWidgetItem *itemCH = new QTableWidgetItem(QString::number(lista->front().getCargaHoraria()));
            int linha = ui->tableWidgetDados->rowCount();
            ui->tableWidgetDados->insertRow(linha);
            itemCodigo->setTextAlignment(Qt::AlignCenter);
            itemCH->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetDados->setItem(linha,0,itemCodigo);
            ui->tableWidgetDados->setItem(linha,1,itemDisciplina);
            ui->tableWidgetDados->setItem(linha,2,itemCH);
            lista->pop_front();
        }
        delete lista;
    }catch(QString &erro){
        QMessageBox::information(this,"Erro",erro);
    }catch(...){
        QMessageBox::information(this,"Erro","Erro na listagem");
    }
}

void materiasDoAlunoWindow::on_pushButtonVoltar_clicked()
{
    this->close();
}
