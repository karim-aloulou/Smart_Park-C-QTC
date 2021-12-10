#include "window.h"
#include "ui_window.h"
#include"ui_mainwindow.h"

//*************************************** emna kh **************************

#include "reservation.h"
#include "mailing1.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include<QSqlQueryModel>

#include<QComboBox>
#include<QTextBrowser>
#include<QSqlQuery>
#include <QDebug>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QFile>
//************************************************** saleh****************************
#include <QStringList>
#include <QMessageBox>
#include "services.h"
#include "smtp.h"
#include <QPrinter>
#include <QPrintDialog>
//****************************************karim**************************************
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
#include<QPrintDialog>
#include<QPrinter>
//#include"src/SmtpMime"
//*******************************************************************
Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    //emnakh
   // ui->setupUi(this);
    ui->stackedWidget ->setCurrentIndex(8);

      ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
      ui->tab_reservation->setModel(R.afficher());
      QSqlQueryModel *model=new QSqlQueryModel;
      model->setQuery("SELECT ID_V FROM VISITEUR");
      ui->comboBox_id->setModel(model);
      qDebug()<<(model->rowCount());
      //saleh
     // ui->setupUi(this);
      QStringList type,etat;
          type<<"Restaurant"<<"Cafés"<<"bar";
          ui->type_s->addItems(type );
          etat<<"Complet"<<"libre";
          ui->etat_S->addItems(etat );
          ui->tab_s->setModel(s.afficher_SERVICES());
          //karim
         // ui->setupUi(this);
          ui->le_email->setMaxLength(50);
          ui->le_id_v->setValidator( new QIntValidator(0, 99999999, this));
          ui->le_tel->setValidator( new QIntValidator(20000000, 99999999, this));
          ui->tab_visiteur->setModel(V.afficher());
}

Window::~Window()
{
    delete ui;
}


void Window::on_pushButton_clicked()
{
ui->stackedWidget ->setCurrentIndex(1);

}

void Window::on_pushButton_2_clicked()
{
  ui->stackedWidget ->setCurrentIndex(2);
}

void Window::on_pushButton_3_clicked()
{
    ui->stackedWidget ->setCurrentIndex(4);
}

void Window::on_pushButton_4_clicked()
{
   ui->stackedWidget ->setCurrentIndex(3);
}


void Window::on_pushButton_5_clicked()
{
  ui->stackedWidget ->setCurrentIndex(6);
}

void Window::on_Cancel_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

//karim
void Window::on_Cancel_2_clicked()
{
     ui->stackedWidget ->setCurrentIndex(0);
}


//emna
void Window::on_Cancel_3_clicked()
{
     ui->stackedWidget ->setCurrentIndex(0);
}

void Window::on_Cancel_4_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}



void Window::on_pushButton_15_clicked()
{
    ui->stackedWidget ->setCurrentIndex(4);
}

/*void Window::on_mailing_clicked()
{
    ui->stackedWidget ->setCurrentIndex(5);
}
*/
void Window::on_pushButton_24_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void Window::on_pb_rech_5_clicked()
{
      ui->stackedWidget ->setCurrentIndex(0);
}
//*******************************************************************emna kh****************************************

void Window::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();

    QString date=ui->date->text();
    QString heure=ui->heure->text();
     QString type_parking=ui->type_parking->text();
 int id_v=ui->comboBox_id->currentText().toInt();
    Reservation R (id ,  date, heure, type_parking,id_v);
    bool test = R.ajouter();

        QMessageBox msgBox;
        if(test)
        {
            ui->tab_reservation->setModel(R.afficher());
           msgBox.setText("ajout  avec succes.");
            msgBox.exec();
            // Création d'un objet QFile
               QFile file("C:/Users/21694/Desktop/gestion places parking/Qt.txt");
               // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
               if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                   return;
               // Création d'un objet QTextStream à partir de notre objet QFile
               QTextStream flux(&file);
               // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
               flux.setCodec("UTF-8");
               // Écriture des différentes lignes dans le fichier

               flux <<"id:" <<ui->le_id->text().toInt()<<" , "<<"date:"<< ui->date->text() <<" , "<<"heure:" << ui->heure->text()<<" , "<< "type_parking:" << ui->type_parking->text()<<"id_v:" << ui->comboBox_id->currentText()<<" Added."<<endl ;
               file.close();

        }
        else
        {
            msgBox.setText("echec d'ajout");
            msgBox.exec();
        }

}


void Window::on_btn_afficher_clicked()
{
    ui->tab_reservation->setModel((R.afficher()));
}

void Window::on_modifier_clicked()
{
    Reservation R;
    int id = ui->le_id_3->text().toInt();
     QString date= ui->date_2->text();
     QString heure= ui->heure_3->text();
     QString TYPE_PARKING=ui->type_parking_2->text();
   //int id_v = ui->combobox_id->currentText().toInt;
   //  bool test=R.modifier(id,date,heure,TYPE_PARKING,id_v);
      bool test=R.modifier(id,date,heure,TYPE_PARKING);
      QMessageBox msgBox;
      if(test)
      {
         msgBox.setText("modification avec succes.");
          msgBox.exec();
          // Création d'un objet QFile
                     QFile file("C:/Users/21694/Desktop/estion places parking/Qt.txt");
                     // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
                     if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                         return;
                     // Création d'un objet QTextStream à partir de notre objet QFile
                     QTextStream flux(&file);
                     // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
                     flux.setCodec("UTF-8");
                     // Écriture des différentes lignes dans le fichier
                     flux <<"id:" <<ui->le_id_3->text().toInt()<<" , "<<"date:"<< ui->date_2->text() <<" , "<<"heure:" << ui->heure_3->text()<<" , "<< "type_parking:" << ui->type_parking_2->text()<<"id_v:" << ui->combobox_id->currentText()<<" modified."<<endl ;
                     file.close();
  }
      else
{
      msgBox.setText("echec de modification ");
      msgBox.exec();
  }

}

void Window::on_supprimer_clicked()
{
    Reservation R1; R1.setid(ui->le_id_supp->text().toInt());
    bool test=R1.supprimer(R1.getid());
    QMessageBox msgBox;
    if(test)
    {
       msgBox.setText("suppression avec succes.");
      ui->tab_reservation->setModel(R.afficher());
       msgBox.exec();
       // Création d'un objet QFile
               QFile file("C:/Users/21694/Desktop/estion places parking/Qt.txt");
               // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
               if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                   return;
               // Création d'un objet QTextStream à partir de notre objet QFile
               QTextStream flux(&file);
               // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
               flux.setCodec("UTF-8");
               // Écriture des différentes lignes dans le fichier
               flux <<"id:"<< ui->le_id_supp->text().toInt() << "          Deleted."<<endl ;

               file.close();
}
    else
{  msgBox.setText("echec de suppression");
        msgBox.exec();
}
}

void Window::on_tri_date_ASC_clicked()
{
    ui->tab_reservation->setModel(R.trierReservationParDATE_ASC());
}



void Window::on_tri_date_DESC_clicked()
{
    ui->tab_reservation->setModel(R.trierReservationParDATE_DESC());
}

void Window::on_tri_heure_ASC_clicked()
{
     ui->tab_reservation->setModel(R.trierReservationParHEURE_asc());
}

void Window::on_tri_heure_DESC_clicked()
{
     ui->tab_reservation->setModel(R.trierReservationParHEURE_DESC());
}

void Window::on_pb_stat_clicked()
{
    //QSqlQueryModel * model= new QSqlQueryModel();


    int i=0,j=0,k=0;
                        for (int var = 0; var < ui->tab_reservation->model()->rowCount(); ++var) {
                                if(ui->tab_reservation->model()->index(var,3).data().toString()=="parking 1 ")

                                    i++;


                                else if(ui->tab_reservation->model()->index(var,3).data().toString()=="parking 2")
                                {
                                    j++;
                                }
                                else
                                    k++;
                            }




                       float total1=i+j+k;

                       QString a1=QString("parking 1"+QString::number((i*100)/total1,'f',2)+"%" );
                       QString b1=QString("parking 2"+QString::number((k*100)/total1,'f',2)+"%" );
                       QString c1=QString("parking 3"+QString::number((j*100)/total1,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a1,i);
                       series->append(b1,k);
                       series->append(c1,j);
               if (i!=0)
               {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
               if ( k!=0)
               {
                        // Add label, explode and define brush for 2nd slice
                        QPieSlice *slice1 = series->slices().at(1);
                        //slice1->setExploded();
                        slice1->setLabelVisible();
               }
               if(j!=0)
               {
                        // Add labels to rest of slices
                        QPieSlice *slice2 = series->slices().at(2);
                        //slice1->setExploded();
                        slice2->setLabelVisible();
               }
                       // Create the chart widget
                       QChart *chart = new QChart();
                       // Add data to chart with title and hide legend
                       chart->addSeries(series);
                       chart->setTitle("Pourcentage Par type :Nombre Des parking "+ QString::number(total1));
                       chart->legend()->hide();
                       // Used to display the chart
                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
                       chartView->resize(1000,500);
                       chartView->show();




}

void Window::on_mailing_clicked()
{
    mailing* m = new mailing(this);
    m->show();
}

//****************************************************saleh*******************************************************
void Window::on_Ajouter_clicked()
{
    QString ID_SERVICE=ui->lD->text();
    QString  TYPE_SERVICE=ui->type_s->currentText();
    QString  ETAT=ui->etat_S->currentText();
     QString HEURE_O=ui->heure_s_O->text();
     QString HEURE_F=ui->heure_S_F->text();
     SERVICES s (ID_SERVICE,TYPE_SERVICE,ETAT,HEURE_O,HEURE_F);
bool test=s.ajouter_SERVICES();
if(test)
    {
    ui->tab_s->setModel(s.afficher_SERVICES());

}
else
    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Ajouter non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Window::on_Modifier_clicked()
{

    QString ID_SERVICE=ui->lD->text();
    QString  TYPE_SERVICE=ui->type_s->currentText();
    QString  ETAT=ui->etat_S->currentText();
     QString HEURE_O=ui->heure_s_O->text();
     QString HEURE_F=ui->heure_S_F->text();
     SERVICES s (ID_SERVICE,TYPE_SERVICE,ETAT,HEURE_O,HEURE_F);
bool test=s.modifier();
if(test)
    {
    ui->tab_s->setModel(s.afficher_SERVICES());

}
else
    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Ajouter non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void Window::on_Supprimer1_clicked()
{
    SERVICES s;
    s.setID_SERVICE(ui->supp->text());


     bool test=s.supprimer_SERVICES(s.get_ID_SERVICE());
     if(test)
         {
         ui->tab_s->setModel(s.afficher_SERVICES());

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("suppression non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}


void Window::on_Recherche_clicked()
{
    SERVICES s;
   ui->tab_s->setModel(s.rechercher(ui->rech->text()));

}

void Window::on_tri_clicked()
{

    SERVICES s;
    if(ui->radioButton->isChecked())
    {ui->tab_s->setModel(s.tri());}
    else if(ui->radioButton_2->isChecked())
    {ui->tab_s->setModel(s.tri_t());}
    else if(ui->radioButton_3->isChecked())
    {ui->tab_s->setModel(s.tri_e());}
    else if (ui->radioButton_4->isChecked())
    {ui->tab_s->setModel(s.tri());
    ui->tab_s->setModel(s.tri_t());
    ui->tab_s->setModel(s.tri_e());
}
}

void Window::on_PDF_clicked()
   {QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tab_s->model()->rowCount();
                         const int columnCount = ui->tab_s->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - SERVICES LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  SERVICES ******"+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tab_s->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tab_s->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_s->isColumnHidden(column)) {
                                     QString data =ui->tab_s->model()->data(ui->tab_s->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         //QTextDocument *document = new QTextDocument();
                         //document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                          //   document->print(&printer);
                         }

                        // delete document;
}



void Window::on_sendMail_clicked()
{
    Smtp* smtp = new Smtp("smartpark21.22@gmail.com","esprit21","smtp.gmail.com",465);
      QString object=ui->objet->text();
        QString message=ui->textEdit->toPlainText();
        QString adresse=ui->envoi->text();

                    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                    smtp->sendMail("smartpark21.22@gmail.com",adresse,object,message);
}


void Window::on_tab_s_clicked(const QModelIndex &index)
{
    int id=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toInt();
        QString vel=QString::number(id);
        ui->lD->setText(vel);
        QString date = ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),5)).toString();
        QString montant=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toString();
}

void Window::on_tab_s_doubleClicked(const QModelIndex &index)
{

    int ID=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toInt();
    QString res=QString::number(ID);
    ui->supp->setText(res);
    //ui->rech->setText(res);

}
//**********************************************************************karim********************************************************************
void Window::on_pb_ajouter_clicked()
{

    bool verif=false,verif1=false;
   QString etat= ui->le_etat->currentText();
    int id_v = ui->le_id_v->text().toInt();
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
   Visiteur V(id_v,nom,prenom,age,tel,email,etat);
   bool test=V.ajouter();
   if (test) {ui->tab_visiteur->setModel(V.afficher());

Notification n;
n.notification_ajouter();
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Ajout effectue.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                   QObject::tr("Ajout non effectue.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void Window::on_pb_modifier_clicked()
{
    bool test,verif=false,verif1=false;
    int id_v = ui->modifier_id_v ->text().toInt();
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
       test=V.modifier(id_v,tel,nom,prenom,email,etat);
          if (test)
          {Notification n;n.notification_modifier();
                  ui->tab_visiteur->setModel(V.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void Window::on_pb_supprimer_clicked()
{
    Visiteur V1;V1.setid_v(ui->le_id_v_supprimer->text().toInt());
    bool test=V1.supprimer();
    QMessageBox msgBox;
    if (test)
       {Notification n; n.notification_modifier(); msgBox.setText(("Suppression avec Succes"));
    ui->tab_visiteur->setModel(V.afficher());}
    else
         msgBox.setText(("Echec de Suppression"));
    msgBox.exec();
}

/*void Window::on_sendBtn_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("karim.aloulou@esprit.tn");
    smtp.setPassword("koukoU11");
    MimeMessage message;
    message.setSender(new EmailAddress("karim.aloulou@esprit.tn", "KARIM ALOULOU"));
    message.addRecipient(new EmailAddress("karim.aloulou@esprit.tn", "KARIM ALOULOU"));
    message.setSubject("SmtpClient for Qt - Demo");
    MimeText text;
    text.setText("Rebonjour,\nMerci Pour Votre Visite nous éspérons vous revoir très prochainement cher client.\n");
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}
*/
void Window::on_generer_pdf_clicked()
{
    Visiteur V1;V1.setid_v(ui->id_v_pdf->text().toInt());
    V1.genererPDFact();
}

void Window::on_imprimer_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("Impression d'Attestation");
    if (ui->tab_visiteur)

          {
              dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
          }

      if(dialog.exec()!=QDialog::Accepted)
      {
          return;
      }
}

void Window::on_tri_croissant_clicked()
{
    Notification n;

        ui->tab_visiteur->setModel(V.tricroissant());
}

void Window::on_tri_decroissant_clicked()
{
     ui->tab_visiteur->setModel(V.trideccroissant());
}

void Window::on_combo_box_crit_activated(const QString &arg1)
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






//karim
void Window::on_pushButton_25_clicked()
{
    mailing* m = new mailing(this);
    m->show();
}

void Window::on_recherche_id_v_textEdited(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
               QSqlQuery   *query= new QSqlQuery();
       if(ui->recherche_id_v->text()==arg1)
               {
           query->prepare("SELECT * FROM VISITEUR WHERE ID_V LIKE'"+arg1+"%'");
   query->exec();
       model->setQuery(*query);
   ui->tab_visiteur->setModel(model);


       }
}

void Window::on_recherche_tel_textEdited(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
               QSqlQuery   *query= new QSqlQuery();
       if(ui->recherche_tel->text()==arg1)
               {
           query->prepare("SELECT * FROM VISITEUR WHERE TEL LIKE'"+arg1+"%'");//
   query->exec();
       model->setQuery(*query);
   ui->tab_visiteur->setModel(model);


       }
}

void Window::on_pushButton_login_clicked()
{
        QString username = ui->lineEdit_login->text();
               QString password = ui->lineEdit_password->text();

               if (username == "admin" && password == "admin") {
                   QMessageBox::information(this, "Login", "Username and password are correct");
                   ui->stackedWidget ->setCurrentIndex(0);

               }
               else {
                   QMessageBox::warning(this, "Login", "Username and password are not correct");
               }
               ui->lineEdit_login->clear();
               ui->lineEdit_password->clear();

}
