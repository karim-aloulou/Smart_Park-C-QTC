#include "mainwindow3.h"
#include "ui_mainwindow3.h"

#include "notification.h"
#include <QMessageBox>
#include "ticket.h"
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QDebug>
#include <QSqlQuery>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QPixmap>
#include <QSystemTrayIcon>

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempticket.afficher_tickets());
    ui->lineEdit_code->setValidator(new QIntValidator(0,999999,this));
    mysystem = new QSystemTrayIcon(this);
    mysystem ->setIcon(QIcon(":/logo.png"));
    mysystem ->setVisible(true);

}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_pushButton_ajouter_clicked()
{ notification n;
    int code=ui->lineEdit_code->text().toInt();
        QString numero=ui->lineEdit_numero->text();
        QString prix=ui->lineEdit_prix->text();
        QString date=ui->dateEdit->date().toString();
        QString type=ui->lineEdit_type->text();

            tickets c(code,numero,prix,date,type);
            bool test=c.ajouter_tickets();
            if(test)
            {
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un ticket"));
                ui->tableView->setModel(tempticket.afficher_tickets());
                QMessageBox::information(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
                QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow3::on_pushButton_8_clicked()
{ notification n;
    int code=ui->lineEdit_code->text().toInt();
        QString numero=ui->lineEdit_numero->text();
        QString prix=ui->lineEdit_prix->text();
        QString date=ui->dateEdit->date().toString();
        QString type=ui->lineEdit_type->text();

            tickets c(code,numero,prix,date,type);
            bool test=c.modifier_tickets(code);
            if(test)
            {n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un ticket"));
                ui->tableView->setModel(tempticket.afficher_tickets());
                QMessageBox::information(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Modification avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
                QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow3::on_pushButton_9_clicked()
{notification n;
    int id=ui->lineEdit_code->text().toUInt();
           bool test=tempticket.supprimer_tickets(id);
           if(test)
           {n.show();
               mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un ticket"));
               ui->tableView->setModel(tempticket.afficher_tickets());
               QMessageBox::information(nullptr, QObject::tr("Supprimer"),
               QObject::tr("Suppression avec succée"), QMessageBox::Ok);
              // hide();
           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
               QObject::tr("Suppression echoués"), QMessageBox::Ok);
           }
}

void MainWindow3::on_pb_rech_clicked()
{

    QString valeur = ui->cb_rech->currentText();
    QString val=ui->le_rech->text();
    if(valeur=="code")
    {ui->tableView->setModel(tempticket.afficher_recherche(val));}
    else if(valeur=="numero")
    {
        ui->tableView->setModel(tempticket.afficher_recherche2(val));
    }
    else if(valeur=="dates")
    {
        ui->tableView->setModel(tempticket.afficher_recherche3(val));
    }

    }










void MainWindow3::on_cb_tri_activated(const QString &arg1)
{
    QString val=ui->cb_tri->currentText();
    ui->tableView->setModel(tempticket.afficher_choix(val));
}

void MainWindow3::on_pb_imprimer_clicked()
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
            "<center> <H1>Liste Des tickets </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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


        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);

}

void MainWindow3::on_tableView_activated(const QModelIndex &index)
{
    tickets c;
            QString code=ui->tableView->model()->data(index).toString();
              QSqlQuery query;

              query.prepare("select * from TICKETS where code LIKE '"+code+"%' or numero LIKE '"+code+"%' or prix LIKE '"+code+"%'");
              if(query.exec())
              {
                while(query.next())
                {
                    ui->lineEdit_code->setText(query.value(0).toString());
                    ui->lineEdit_numero->setText(query.value(1).toString());
                    ui->lineEdit_prix->setText(query.value(2).toString());
                    ui->lineEdit_type->setText(query.value(4).toString());

              }
              }
                else
                {


                  QMessageBox::critical(nullptr, QObject::tr("error"),
                              QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
              }

}

void MainWindow3::on_pbpdf_clicked()
{
    QPdfWriter pdf("C:/Users/elgay/OneDrive/Bureau/Atelier_Connexion/pdfticket.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"LISTE DES TICKETS");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         //
                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/elgay/OneDrive/Bureau/Atelier_Connexion/logo.jpg"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"CODE ");
                          painter.drawText(1600,3300,"NUM ");
                          painter.drawText(3000,3300,"PRIX");
                          painter.drawText(4200,3300,"DATE");
                          painter.drawText(5300,3300,"TYPE");


                          QSqlQuery query;
                          query.prepare("select * from TICKETS");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1600,i,query.value(1).toString());
                              painter.drawText(3000,i,query.value(2).toString());
                              painter.drawText(4200,i,query.value(3).toString());
                              painter.drawText(5300,i,query.value(4).toString());


                             i = i + 500;
                          }
                          QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}
