#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "services.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_tab_s_clicked(const QModelIndex &index);
    void on_tab_s_doubleClicked(const QModelIndex &index);
    void on_tri_clicked();
    void on_Recherche_clicked();
    void on_stat_clicked();
    void on_PDF_clicked();
    void on_sendMail_clicked();
    void mailSent();

private:
    Ui::MainWindow *ui;
    SERVICES s;
};

#endif // MAINWINDOW_H
