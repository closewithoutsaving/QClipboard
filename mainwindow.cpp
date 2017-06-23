#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QClipboard"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QClipboard *clipboard = QApplication::clipboard();
    connect(clipboard, SIGNAL(dataChanged()), SLOT(clipboard_changed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_Copy_clicked()
{
    tmp = ui->lineEdit->text();
    clipboard->setText(tmp);
}

void MainWindow::on_pushButton_Paste_clicked()
{
    ui->lineEdit->setText(this->clipboard->text());
}

void MainWindow::clipboard_changed()
{
    ui->listWidget_ClipboardChanges->addItem(clipboard->text());
    qDebug() << clipboard->text();
}

void MainWindow::on_pushRemoveLast_clicked()
{

}
