#ifndef MATERIASDOALUNOWINDOW_H
#define MATERIASDOALUNOWINDOW_H

#include <QDialog>
#include "Estudante.h"

namespace Ui {
class materiasDoAlunoWindow;
}

class materiasDoAlunoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit materiasDoAlunoWindow(QWidget *parent = 0);
    ~materiasDoAlunoWindow();

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::materiasDoAlunoWindow *ui;
};

#endif // MATERIASDOALUNOWINDOW_H
