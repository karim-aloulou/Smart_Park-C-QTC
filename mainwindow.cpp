#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QMessageBox>

#include "smtp.h"
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList type,etat;
        type<<"Restaurant"<<"Cafés"<<"bar";
        ui->type_s->addItems(type );
        etat<<"Complet"<<"libre";
        ui->etat_S->addItems(etat );
        ui->tab_s->setModel(s.afficher_SERVICES());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_clicked()
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


void MainWindow::on_Supprimer_clicked()
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
                             QObject::tr("Ajouter non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_Modifier_clicked()
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

void MainWindow::on_tab_s_clicked(const QModelIndex &index)
{
    int id=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toInt();
    QString vel=QString::number(id);
    ui->lD->setText(vel);
    QString date = ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),5)).toString();
    QString montant=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toString();


}

void MainWindow::on_tab_s_doubleClicked(const QModelIndex &index)
{
    int ID=ui->tab_s->model()->data(ui->tab_s->model()->index(ui->tab_s->currentIndex().row(),0)).toInt();
    QString res=QString::number(ID);
    ui->supp->setText(res);
    //ui->rech->setText(res);


}



void MainWindow::on_tri_clicked()
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

void MainWindow::on_Recherche_clicked()
{
    SERVICES s;
   ui->tab_s->setModel(s.rechercher(ui->rech->text()));

}

void   MainWindow::on_sendMail_clicked()
{
    Smtp* smtp = new Smtp("smartpark21.22@gmail.com","esprit21","smtp.gmail.com",465);
      QString object=ui->objet->text();
        QString message=ui->textEdit->toPlainText();
        QString adresse=ui->envoi->text();

                    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                    smtp->sendMail("smartpark21.22@gmail.com",adresse,object,message);

}

void MainWindow:: on_stat_clicked()
{
    SERVICES s;
   //s.stat();
}
void MainWindow:: on_PDF_clicked()
{
    QString strStream;
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

