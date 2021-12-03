#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include "reservation.h"
#include"mailing1.h"
namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:


    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_btn_afficher_clicked();

   // void on_tri_date_clicked();

   // void on_tri_date_activated(const QString &arg1);

    void on_tri_date_ASC_clicked();

    void on_tri_date_DESC_clicked();

    void on_tri_heure_ASC_clicked();

    void on_tri_heure_DESC_clicked();

  //  void on_tri_type_clicked();

    void on_pb_stat_clicked();

    void on_mailing_clicked();

private:
    Ui::MainWindow1 *ui;
    Reservation R;
    //mailing *mailling;
};

#endif // MAINWINDOW1_H
