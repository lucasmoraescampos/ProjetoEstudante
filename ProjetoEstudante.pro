#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T00:33:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoEstudante
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CodigoDisciplinaCH.cpp \
    MatriculaCodigoDisciplina.cpp \
    MatriculaNome.cpp \
    Estudante.cpp \
    alunosDaMateriaWindow.cpp \
    materiasDoAlunoWindow.cpp

HEADERS  += mainwindow.h \
    CodigoDisciplinaCH.h \
    MatriculaCodigoDisciplina.h \
    MatriculaNome.h \
    Estudante.h \
    alunosDaMateriaWindow.h \
    materiasDoAlunoWindow.h \
    Interface.h

FORMS    += mainwindow.ui \
    alunosDaMateriaWindow.ui \
    materiasDoAlunoWindow.ui

RESOURCES += \
    arquivos.qrc
