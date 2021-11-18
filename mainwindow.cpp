#include "mainwindow.h"
#include "ui_mainwindow.h"
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999,this));
    ui->tableView->setModel(P->afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Ajouter:
void MainWindow::on_pushButton_clicked()
{

           int numtel =ui->lineEdit_Num->text().toInt();
           int CIN =ui->lineEdit_CIN->text().toInt();
           QString nom=ui->lineEdit_Nom->text();
           QString prenom=ui->lineEdit_Prenom->text();
           QString adresse=ui->lineEdit_Adresse->text();
           QString grade=ui->lineEdit_Grade->text();
           QString Email=ui->lineEdit_mail->text();
           QString date=ui->lineEdit_Date->text();
           personelles P (numtel, CIN,nom, prenom,adresse,Email,grade,date );
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
 void MainWindow::on_pushButton_2_clicked()
{
            int numtel =ui->lineEdit_Num->text().toInt();
            int CIN=ui->lineEdit_CIN->text().toInt();
            QString nom=ui->lineEdit_Nom->text();
            QString prenom=ui->lineEdit_Prenom->text();
            QString adresse=ui->lineEdit_Adresse->text();
            QString grade=ui->lineEdit_Grade->text();
            QString Email=ui->lineEdit_mail->text();
            QString date=ui->lineEdit_Date->text();

             personelles P(numtel, CIN,nom, prenom,adresse,Email,grade,date );
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

//supprimer


void MainWindow::on_delete_2_clicked()
{ personelles P;

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










void MainWindow::on_PDF_clicked()
{

        QString strStream;

                   QTextStream out(&strStream);
                   const int rowCount = ui->tableView->model()->rowCount();
                   const int columnCount = ui->tableView->model()->columnCount();
                   out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg("strTitle")
                       <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                       //     "<align='right'> " << datefich << "</align>"
                       "<center> <H1>Liste RH </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
                   // headers
                   out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                   for (int column = 0; column < columnCount; column++)

                       if (!ui->tableView->isColumnHidden(column))

                           out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

                   out << "</tr></thead>\n";
                   // data table

                   for (int row = 0; row < rowCount; row++)
                   {
                       out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                       for (int column = 0; column < columnCount; column++)
                       {
                           if (!ui->tableView->isColumnHidden(column))
                           {
                               QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table> </center>\n"

                       "</body>\n"

                       "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");

                   if (QFileInfo(fileName).suffix().isEmpty())

                   {

                       fileName.append(".pdf");

                   }

}
