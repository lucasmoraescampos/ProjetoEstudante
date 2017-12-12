#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButtonAlunosDaMateria_clicked()
{
    alunosDaMateriaWindow alunos;
    alunos.setModal(true);
    this->setVisible(false);
    alunos.exec();
    this->setVisible(true);
}

void MainWindow::on_commandLinkButtonDiciplinasDoAluno_clicked()
{
    materiasDoAlunoWindow materias;
    materias.setModal(true);
    this->setVisible(false);
    materias.exec();
    this->setVisible(true);
}
