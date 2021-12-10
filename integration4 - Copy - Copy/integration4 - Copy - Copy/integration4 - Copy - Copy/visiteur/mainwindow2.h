#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include"visiteur.h"
#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();

    void on_tri_croissant_clicked();

    void on_tri_decroissant_clicked();


    void on_combo_box_crit_currentTextChanged(const QString &arg1);



    void on_recherche_id_v_textChanged(const QString &arg1);

    void on_recherche_tel_textEdited(const QString &arg1);

    void on_generer_pdf_clicked();

    void on_imprimer_clicked();



    void on_sendBtn_clicked();


private:
    Ui::MainWindow2 *ui;
    Visiteur V;
};

#endif // MAINWINDOW2_H
