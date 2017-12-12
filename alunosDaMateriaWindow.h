#ifndef ALUNOSDAMATERIAWINDOW_H
#define ALUNOSDAMATERIAWINDOW_H

#include <QDialog>
#include<Estudante.h>

namespace Ui {
class alunosDaMateriaWindow;
}

class alunosDaMateriaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit alunosDaMateriaWindow(QWidget *parent = 0);
    ~alunosDaMateriaWindow();

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::alunosDaMateriaWindow *ui;
};

#endif // ALUNOSDAMATERIAWINDOW_H
