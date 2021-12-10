#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include "personnelles.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QTextCursor>
//#include "email.h"
#include"qrcode.h"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999,this));
    ui->tableView->setModel(P.afficher());
}

MainWindow4::~MainWindow4()
{
    delete ui;
}
//Ajouter:
void MainWindow4::on_pushButton_clicked()
{

           int numtel =ui->lineEdit_Num->text().toInt();
           QString CIN =ui->lineEdit_CIN->text();
           QString nom=ui->lineEdit_Nom->text();
           QString prenom=ui->lineEdit_Prenom->text();
           QString adresse=ui->lineEdit_Adresse->text();
           QString grade=ui->lineEdit_Grade->text();
           QString Email=ui->lineEdit_mail->text();
           QString date=ui->lineEdit_Date->text();
           personnelles P (CIN , nom , prenom , date , numtel , Email , adresse , grade );
           bool test=P.ajouter();
           if (test)
           { //refresh(actualiser)
               ui->tableView->setModel(P.afficher());
               QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajouter effectué.\n" "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else //si requete non executée
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Ajouter non effectuée.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

//Modifier:
 void MainWindow4::on_pushButton_2_clicked()
{
            int numtel =ui->lineEdit_Num->text().toInt();
            QString CIN=ui->lineEdit_CIN->text();
            QString nom=ui->lineEdit_Nom->text();
            QString prenom=ui->lineEdit_Prenom->text();
            QString adresse=ui->lineEdit_Adresse->text();
            QString grade=ui->lineEdit_Grade->text();
            QString Email=ui->lineEdit_mail->text();
            QString date=ui->lineEdit_Date->text();

              personnelles P(CIN , nom , prenom , date , numtel , Email , adresse , grade );
                   bool test=P.modiffier();
                    if(test)
                    {
                        ui->tableView->setModel(P.afficher());
                        QMessageBox::information(nullptr, QObject::tr(" OK"),QObject::tr("Modification  effectué.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                    }
                     else
                    {

                        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Modification non effectuée.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                    }
}

// supprimer


void MainWindow4::on_delete_2_clicked()
{ personnelles P;

        int cin=ui->lineEditSUPP->text().toInt() ;
        bool test = P.supprimer(cin) ;
        if(test)
    {//refresh(actualiser)
            ui->tableView->setModel(P.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression  effectuée.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else
          QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Suppression non effectuée.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }


// mailing
/*void MainWindow4::on_pushButton_4_clicked()
{
    Smtp* smtp = new Smtp("emna.machhout@esprit.tn","201JMT3638","smtp.gmail.com",465);

                    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                    smtp->sendMail("emna.machhout@esprit.tn",ui->lineEdit_mail->text(),ui->subject_2->text(),ui->lineEdit_3->text());

}*/
// recherche
void MainWindow4::on_pushButton_3_clicked()
{

    QString C=ui->lineEdit->text();
   //     QString nom=ui->lineEdit->text();
   //     QString prenom=ui->lineEdit->text();

        ui->tableView->setModel(P.recherche(C));

}
// tri
void MainWindow4::on_pushButton_5_clicked()
{
    ui->tableView->setModel(P.trie(0));
}


void MainWindow4::on_pushButton_8_clicked()
{

            ui->tableView->setModel(P.trie_age(0));


}
void MainWindow4::on_pushButton_7_clicked()
{
    ui->tableView->setModel(P.trie_nom(0));
}



// QR code
void MainWindow4::on_pushButton_6_clicked()
{

 personnelles P ;

     if(ui->tableView->currentIndex().row()==-1)
                QMessageBox::information(nullptr, QObject::tr("QR"),
                                         QObject::tr("Veuillez Choisir un personnel du Tableau.\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);
            else
            {



     /*    QString cin = ui->cin->text();
            QString nom = ui->nom->text();
            QString prenom = ui->prenom->text();*/

         P.setCIN(ui-> lineEdit_CIN ->text());
         P.setNom(ui->lineEdit_Nom ->text());
         P.setgrade(ui->lineEdit_Grade->text());
         P.setadresse(ui->lineEdit_Adresse ->text());
         P.setPrenom(ui->lineEdit_Prenom ->text());

        ;





                                QString  rawQr = "cin: %1Nom: %2Prenom:%3Age:%4 Salaire:%5";
                                 rawQr = rawQr.arg(P.getCIN()).arg(P.getnom()).arg(P.getprenom()).arg(P.getgrade()).arg(P.getadresse());
                                   QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);
                // const QrCode qr = QrCode::encodeText(std::to_string(cin).c_str(), QrCode::Ecc::LOW);
                                   QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                                      for (int y = 0; y < qr.getSize(); y++) {
                                          for (int x = 0; x < qr.getSize(); x++) {
                                              int color = qr.getModule(x, y);  // 0 for white, 1 for black

                                              // You need to modify this part
                                              if(color==0)
                                                  im.setPixel(x, y,qRgb(254, 254, 254));
                                              else
                                                  im.setPixel(x, y,qRgb(0, 0, 0));
                                          }
                                      }
                                      im=im.scaled(200,200);
                                      ui->label_13->setPixmap(QPixmap::fromImage(im));
}
}



