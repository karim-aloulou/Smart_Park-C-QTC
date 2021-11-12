#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"visiteur.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include <QComboBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
ui->le_tel->setValidator( new QIntValidator(20000000, 99999999, this));
ui->tab_visiteur->setModel(V.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    bool verif=false,verif1=false;
   QString etat= ui->le_etat->currentText();
    int id = ui->le_id->text().toInt();
      int tel = ui->le_tel->text().toInt();
      if (tel<20000000)
      {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                             QObject::tr("Numero de téléhpone non valide.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
      int age=ui->le_age->text().toInt();
      if (age>80)
      {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                             QObject::tr("Risque de sécurité: Personne très agée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}

   QString nom=ui->le_nom->text();
   QString email=ui->le_email->text();
   for ( int i=0;i<email.length();i++)
   {if (email[i]==" ")
   verif1=true;}
   for ( int i=0;i<email.length();i++)
   {if (email[i]=="@")
   verif=true;}
   if((verif==false)||(verif1==true))
   {{QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                           QObject::tr("Adresse mail non valide\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}}
   QString prenom=ui->le_prenom->text();
   Visiteur V(id,nom,prenom,age,tel,email,etat);
   bool test=V.ajouter();
   if (test) {ui->tab_visiteur->setModel(V.afficher());
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Ajout effectue.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                   QObject::tr("Ajout non effectue.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void MainWindow::on_pb_supprimer_clicked()
{
    Visiteur V1;V1.setid(ui->le_id_supprimer->text().toInt());
    bool test=V1.supprimer(V1.getid());
    QMessageBox msgBox;
    if (test)
       { msgBox.setText(("Suppression avec Succes"));
    ui->tab_visiteur->setModel(V.afficher());}
    else
         msgBox.setText(("Echec de Suppression"));
    msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{

    bool test,verif=false,verif1=false;
    int id = ui->modifier_id ->text().toInt();
    QString etat= ui->le_etat_2->currentText();
    int tel = ui->modifier_tel ->text().toInt();
    QString nom=ui->modifier_nom->text();
    QString prenom=ui->modifier_prenom->text();
    QString email=ui->modifier_email->text();
    for ( int i=0;i<email.length();i++)
    {if (email[i]==" ")
    verif1=true;}
    for ( int i=0;i<email.length();i++)
    {if (email[i]=="@")
    verif=true;}
    if((verif==false)||(verif1==true))
    {{QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                            QObject::tr("Adresse mail non valide\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}}
    if (tel<20000000)
    {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                           QObject::tr("Numero de téléhpone non valide.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}
    int age=ui->le_age->text().toInt();
    if (age>80)
    {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                           QObject::tr("Risque de sécurité: Personne très agée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}
       test=V.modifier(id,tel,nom,prenom,email,etat);
          if (test)
          {
                  ui->tab_visiteur->setModel(V.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}


void MainWindow::on_tri_croissant_clicked()
{
    ui->tab_visiteur->setModel(V.tricroissant());
}

void MainWindow::on_tri_decroissant_clicked()
{
     ui->tab_visiteur->setModel(V.trideccroissant());
}



void MainWindow::on_combo_box_crit_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
               QSqlQuery   *query= new QSqlQuery();
       if(ui->combo_box_crit->currentText()=="client_fidele"
               ){
           query->prepare("SELECT * FROM VISITEUR WHERE ETAT LIKE'"+arg1+"%'");//
   query->exec();
       model->setQuery(*query);
   ui->tab_visiteur->setModel(model);


       }
       else {
           if(ui->combo_box_crit->currentText()=="handicape"){
               query->prepare("SELECT * FROM VISITEUR WHERE ETAT LIKE'"+arg1+"%'");//+tri
       query->exec();
           model->setQuery(*query);
       ui->tab_visiteur->setModel(model);
           }
           if(ui->combo_box_crit->currentText()=="OK"){
               query->prepare("SELECT * FROM VISITEUR WHERE ETAT LIKE'"+arg1+"%'");//+tri
       query->exec();
           model->setQuery(*query);
       ui->tab_visiteur->setModel(model);
           }
           else{
               if(ui->combo_box_crit->currentText()=="enfant_inaccompagne")
                   query->prepare("SELECT * FROM VISITEUR WHERE ETAT LIKE'"+arg1+"%'");//+tri
           query->exec();
               model->setQuery(*query);
           ui->tab_visiteur->setModel(model);
               }

           }
}

