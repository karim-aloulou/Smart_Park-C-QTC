#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H
#include "personnelles.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE

namespace Ui {class MainWindow4;}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = nullptr);
    ~MainWindow4();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_delete_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_calendarWidget_activated(const QDate &date);

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow4 *ui;
   personnelles P;

};

#endif // MAINWINDOW4_H
