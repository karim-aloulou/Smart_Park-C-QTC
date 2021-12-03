#ifndef WINDOW_H
#define WINDOW_H
#include "service/mainwindow.h"
#include "reservation/mainwindow1.h"
#include "visiteur/mainwindow2.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Window *ui;
   MainWindow *service;
   MainWindow1 *reservation;
    MainWindow2 *visiteur;
};
#endif // WINDOW_H
