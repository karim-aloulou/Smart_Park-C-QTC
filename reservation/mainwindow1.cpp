#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "reservation.h"

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

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_reservation->setModel(R.afficher());
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("SELECT ID_V FROM VISITEURS");
    ui->comboBox_id->setModel(model);
    qDebug()<<(model->rowCount());
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();

    QString date=ui->date->text();
    QString heure=ui->heure->text();
     QString type_parking=ui->type_parking->text();
  QString id_v=ui->comboBox_id->currentText();
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

    void MainWindow1::on_modifier_clicked()
    {

      Reservation R;
      int id = ui->le_id_3->text().toInt();
       QString date= ui->date_2->text();
       QString heure= ui->heure_3->text();
       QString TYPE_PARKING=ui->type_parking_2->text();
      QString id_v = ui->combobox_id->currentText();
       bool test=R.modifier(id,date,heure,TYPE_PARKING,id_v);
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


void MainWindow1::on_supprimer_clicked()
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



void MainWindow1::on_btn_afficher_clicked()
{
    ui->tab_reservation->setModel((R.afficher()));
}



void MainWindow1::on_tri_date_ASC_clicked()
{
    ui->tab_reservation->setModel(R.trierReservationParDATE_ASC());
}

void MainWindow1::on_tri_date_DESC_clicked()
{
     ui->tab_reservation->setModel(R.trierReservationParDATE_DESC());
}

void MainWindow1::on_tri_heure_ASC_clicked()
{
     ui->tab_reservation->setModel(R.trierReservationParHEURE_asc());
}

void MainWindow1::on_tri_heure_DESC_clicked()
{
    ui->tab_reservation->setModel(R.trierReservationParHEURE_DESC());
}




void MainWindow1::on_pb_stat_clicked()
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

/*void MainWindow1::on_mailing_clicked()
{
    mailling = new mailing(this);
    mailling ->show();
}
*/
