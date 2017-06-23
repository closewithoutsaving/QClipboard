#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_Clear_clicked();

    void on_pushButton_Copy_clicked();

    void on_pushButton_Paste_clicked();

    void clipboard_changed();

    void on_pushRemoveLast_clicked();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    QString tmp;
};

#endif // MAINWINDOW_H
