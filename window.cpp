#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}


void Window::on_pushButton_clicked()
{
    service = new MainWindow(this);
           service ->show();
}

void Window::on_pushButton_3_clicked()
{
    reservation = new MainWindow1(this);
          reservation ->show();
}


void Window::on_pushButton_2_clicked()
{
    visiteur = new MainWindow2(this);
         visiteur ->show();
}
