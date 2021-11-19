#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnelles.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_delete_2_clicked();


    void on_PDF_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
   personelles *P;

};

#endif // MAINWINDOW_H
