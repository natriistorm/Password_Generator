#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "passwordgenerator.h"
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int number = ui->numberPass->value();
    int length = ui->lenPass->value();
    QString filename = "./" + ui->lineEdit->text();
    QFile file(filename);
    PasswordGenerator new_passowrds = PasswordGenerator(number, length, file);
    ui->statusbar->showMessage("Пароли сгенерированы");
}


void MainWindow::on_numberPass_valueChanged(int arg1) {
    if (arg1 <= 0) {
        ui->statusbar->showMessage("Количество паролей не может быть равно 0");
    }
}


void MainWindow::on_lenPass_valueChanged(int arg1) {
    if (arg1 <= 0) {
        ui->statusbar->showMessage("Длина паролей не может быть равно 0");
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 == "") {
        ui->statusbar->showMessage("Некорректное имя файла");
    }
}
