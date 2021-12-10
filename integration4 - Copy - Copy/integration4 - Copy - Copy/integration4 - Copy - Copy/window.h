#ifndef WINDOW_H
#define WINDOW_H
/*#include "service/mainwindow.h"
#include "reservation/mainwindow1.h"
#include "visiteur/mainwindow2.h"
#include "ticket/mainwindow3.h"
#include "personnelles/mainwindow4.h"*/
#include"reservation.h"
#include "mailing1.h"
#include "services.h"
#include "visiteur.h"
#include "smtp.h"
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
    //****************************** window.h************************************
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_Cancel_clicked();

    void on_pushButton_4_clicked();

    void on_Cancel_2_clicked();

    void on_pushButton_6_clicked();

    void on_Cancel_3_clicked();

    void on_Cancel_4_clicked();

    void on_mailing_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_24_clicked();

    void on_pb_rech_5_clicked();


    void on_ajouter_clicked();

    void on_btn_afficher_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_tri_date_ASC_clicked();

    void on_tri_date_DESC_clicked();

    void on_tri_heure_ASC_clicked();

    void on_tri_heure_DESC_clicked();

    void on_pb_stat_clicked();



    void on_Ajouter_clicked();

    void on_Modifier_clicked();

   void on_Supprimer1_clicked();

    void on_Recherche_clicked();

    void on_tri_clicked();

    void on_PDF_clicked();

    void on_stat_clicked();

    void on_sendMail_clicked();




    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_sendBtn_clicked();

    void on_generer_pdf_clicked();

    void on_imprimer_clicked();

    void on_tri_croissant_clicked();

    void on_tri_decroissant_clicked();

    void on_combo_box_crit_activated(const QString &arg1);

    void on_recherche_id_v_cursorPositionChanged(int arg1, int arg2);

    void on_recherche_tel_cursorPositionChanged(int arg1, int arg2);

    void on_tab_s_clicked(const QModelIndex &index);

    void on_tab_s_doubleClicked(const QModelIndex &index);



    void on_pushButton_25_clicked();

    void on_recherche_id_v_textEdited(const QString &arg1);

    void on_recherche_tel_textEdited(const QString &arg1);

    void on_pushButton_login_clicked();

private:
    Ui::Window *ui;
  /* MainWindow *service;
   MainWindow1 *reservation;
    MainWindow2 *visiteur;
      MainWindow3 *ticket;
       MainWindow4 *personnelles;
       */
    Reservation R;
     mailing *mailling;
     SERVICES s;
   Visiteur V;
};
#endif // WINDOW_H
