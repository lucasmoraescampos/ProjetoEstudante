#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alunosDaMateriaWindow.h>
#include <materiasDoAlunoWindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_commandLinkButtonAlunosDaMateria_clicked();

    void on_commandLinkButtonDiciplinasDoAluno_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
