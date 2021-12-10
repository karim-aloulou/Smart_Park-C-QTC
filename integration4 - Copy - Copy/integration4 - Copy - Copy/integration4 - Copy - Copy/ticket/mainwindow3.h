#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include "ticket.h"
#include "notification.h"
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>

namespace Ui {
class MainWindow3;
}
class QSystemTrayIcon ;

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pb_rech_clicked();


    void on_cb_tri_activated(const QString &arg1);

    void on_pb_imprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pbpdf_clicked();

private:
    Ui::MainWindow3 *ui;
    tickets tempticket;
    QSystemTrayIcon *mysystem;

};

#endif // MAINWINDOW3_H
