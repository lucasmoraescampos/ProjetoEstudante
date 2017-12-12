#include "alunosDaMateriaWindow.h"
#include "ui_alunosDaMateriaWindow.h"
#include <iostream>

alunosDaMateriaWindow::alunosDaMateriaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alunosDaMateriaWindow)
{
    ui->setupUi(this);
}

alunosDaMateriaWindow::~alunosDaMateriaWindow()
{
    std::remove("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/temp.csv"); //**************************Mudar caminho********************
    delete ui;
}

void alunosDaMateriaWindow::on_pushButtonBuscar_clicked()
{
    try{
        QString codigo = ui->lineEditCodigo->text();

        TP2::Estudante file1("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/MatriculaCodigoDisciplina.csv"); //**************************Mudar caminho********************
        std::vector<long> matriculas = file1.listarMatriculas(codigo);

        TP2::Estudante file2("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/MatriculaNome.csv"); //**************************Mudar caminho********************
        std::list<TP2::MatriculaNome>* lista = file2.matriculasNome(matriculas);

        TP2::Estudante file3("/home/charles/Trabalhos/ProjetoEstudante/Arquivos/CodigoDisciplinaCH.csv"); //**************************Mudar caminho********************
        TP2::CodigoDisciplinaCH disciplinaCH = file3.disciplinaCH(codigo);

        ui->labelDescricao->setText(disciplinaCH.getDisciplina());
        ui->labelCH->setText(QString::number(disciplinaCH.getCargaHoraria()));

        ui->tableWidgetDados->setRowCount(0);
        while(!lista->empty()){
            TP2::MatriculaNome objeto = lista->front();
            lista->pop_front();
            //Montando a grid
            QTableWidgetItem *itemMatricula = new QTableWidgetItem(QString::number(objeto.getMatricula()));
            QTableWidgetItem *itemNome = new QTableWidgetItem(objeto.getNome());
            int linha = ui->tableWidgetDados->rowCount();
            ui->tableWidgetDados->insertRow(linha);
            itemMatricula->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetDados->setItem(linha,0,itemMatricula);
            ui->tableWidgetDados->setItem(linha,1,itemNome);
        }
        delete lista;
    }catch(QString &erro){
        QMessageBox::information(this,"Erro",erro);
    }catch(...){
        QMessageBox::information(this,"Erro","Erro na listagem");
    }

}

void alunosDaMateriaWindow::on_pushButtonVoltar_clicked()
{
    this->close();
}
