#include "services.h"


SERVICES::SERVICES()
{
     HEURE_O="";
     HEURE_F="";
     TYPE_SERVICE="";
     ID_SERVICE="";
     ETAT="";
}
SERVICES::SERVICES(QString ID,QString T,QString E,QString o,QString f) {
    ID_SERVICE=ID;
    TYPE_SERVICE=T;
    ETAT=E;
    HEURE_O=o;
    HEURE_F=f;
}
void SERVICES::setID_SERVICE(QString ID_SERVICE){this->ID_SERVICE=ID_SERVICE; }
bool SERVICES::ajouter_SERVICES() {
    QSqlQuery qry;

    qry.prepare("insert into SERVICES (ID_SERVICE,TYPE_SERVICE,ETAT,HEURE_O,HEURE_F)" "values(:ID_SERVICE,:TYPE_SERVICE,:ETAT,:HEURE_O,:HEURE_F)" );
    qry.bindValue(":ID_SERVICE",ID_SERVICE);
    qry.bindValue(":ETAT",ETAT);
    qry.bindValue(":TYPE_SERVICE",TYPE_SERVICE);
    qry.bindValue(":HEURE_O",HEURE_O);
    qry.bindValue(":HEURE_F",HEURE_F);
 return qry.exec();
 qry.prepare("insert into FAIRE (ID_SERVICE)" "values(:ID_SERVICE)" );
 qry.bindValue(":ID_SERVICE",ID_SERVICE);
 return qry.exec();
 qry.prepare("insert into ENTRETENIR (ID_SERVICE)" "values(:ID_SERVICE)" );
 qry.bindValue(":ID_SERVICE",ID_SERVICE);
 return qry.exec();



}
QSqlQueryModel  *SERVICES::afficher_SERVICES(){
    QSqlQueryModel  *modal=new QSqlQueryModel();
    modal->setQuery("select * from SERVICES");
    modal->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_SERVICE"));
    modal->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
    modal->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));
    modal->setHeaderData(3,Qt::Horizontal, QObject::tr("HEURE_O"));
     modal->setHeaderData(4,Qt::Horizontal, QObject::tr("HEURE_F"));
    return modal;
}
bool SERVICES::supprimer_SERVICES(QString ID_SERVICE){

    QSqlQuery query;
    query.prepare("Delete from SERVICES where ID_SERVICE =:sel ");
    query.bindValue(":sel", ID_SERVICE);
    return query.exec();
    query.prepare("Delete from FAIRE where ID_SERVICE =:sel ");
    query.bindValue(":sel", ID_SERVICE);
    return query.exec();
    query.prepare("Delete from ENTRETENIR where ID_SERVICE = :sel ");
    query.bindValue(":sel", ID_SERVICE);
    return query.exec();

}

bool SERVICES::modifier()
{

    QSqlQuery query;


    query.prepare(" UPDATE SERVICES SET ID_SERVICE=:ID_SERVICE,TYPE_SERVICE=:TYPE_SERVICE,ETAT=:ETAT,HEURE_O=:HEURE_O,HEURE_F=:HEURE_F where ID_SERVICE=:ID_SERVICE " );
    query.bindValue(":ID_SERVICE", ID_SERVICE);
    query.bindValue(":TYPE_SERVICE",TYPE_SERVICE);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":HEURE_O", HEURE_O);
     query.bindValue(":HEURE_F", HEURE_F);

    return    query.exec();
    query.prepare(" UPDATE ENTRETENIR SET  SERVICES ID_SERVICE=:ID_SERVICE where ID_SERVICE=:ID_SERVICE " );
    query.bindValue(":ID_SERVICE", ID_SERVICE);
    return    query.exec();
    query.prepare(" UPDATE FAIRE SET  SERVICES ID_SERVICE=:ID_SERVICE where ID_SERVICE=:ID_SERVICE " );
    query.bindValue(":ID_SERVICE", ID_SERVICE);
    return    query.exec();


}
QSqlQueryModel *SERVICES:: tri()
{
    QSqlQueryModel  *model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM SERVICES  ORDER BY ID_SERVICE");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_SERVICE"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("HEURE_O"));
     model->setHeaderData(4,Qt::Horizontal, QObject::tr("HEURE_F"));
    return model;
}

QSqlQueryModel *SERVICES:: tri_t()
{
    QSqlQueryModel  *model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM SERVICES  ORDER BY TYPE_SERVICE");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_SERVICE"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("HEURE_O"));
     model->setHeaderData(4,Qt::Horizontal, QObject::tr("HEURE_F"));
    return model;
}

QSqlQueryModel *SERVICES:: tri_e()
{
    QSqlQueryModel  *model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM SERVICES  ORDER BY ETAT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_SERVICE"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("HEURE_O"));
     model->setHeaderData(4,Qt::Horizontal, QObject::tr("HEURE_F"));
    return model;
}

QSqlQueryModel * SERVICES::rechercher(QString searche)
{


    QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT *FROM SERVICES where ID_SERVICE like '%"+searche+"%' or TYPE_SERVICE like '%"+searche+"%' or ETAT like '%"+searche+"%'or HEURE_O like '%"+searche+"%'or HEURE_F like '%"+searche+"%' ");

model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_SERVICE"));
model->setHeaderData(1,Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(3,Qt::Horizontal, QObject::tr("HEURE_O"));
 model->setHeaderData(4,Qt::Horizontal, QObject::tr("HEURE_F"));

    return model;
}

/*void SERVICES::stat()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString achat ="Restaurant";
    QString rep ="Cafés";
    QString ach="bar";
                             model->setQuery("select * from SERVICES where SOURCE_FACTURE like '%"+achat+"%'");
                             float typ=model->rowCount();
                             model->setQuery("select * from SERVICES where SOURCE_FACTURE like '%"+rep+"%'");
                             float types=model->rowCount();
                             model->setQuery("select * from SERVICES where SOURCE_FACTURE like '%"+ach+"%'");
                             float typee=model->rowCount();
                             float total=typ+types+typee;
                             QString a=QString("Restaurant "+QString::number((typ*100)/total,'f',2)+"%" );
                             QString b=QString("Cafés"+QString::number((types*100)/total,'f',2)+"%" );
                             QString c=QString("bar"+QString::number((typee*100)/total,'f',2)+"%" );
                             QPieSeries *series = new QPieSeries();
                             series->append(a,typ);
                             series->append(b,types);
                             series->append(c,typee);
                     if (typ!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if ( types!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(typee!=0)
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
                             chart->setTitle("Pourcentage Par type achat : nbr achat "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();

    }*/
