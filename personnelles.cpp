#include "personnelles.h"


personelles::personelles (int numtel, int CIN, QString nom, QString prenom,QString adresse,QString Email,QString grade,QString date)
{
    this-> nom=nom;
    this->prenom =prenom;
    this->numtel =numtel;
    this->CIN =CIN;
    this->date=date;
    this->Email=Email;
    this->adresse=adresse;
    this->grade=grade;
}



bool personelles::ajouter()
{
QSqlQuery query;
QString res = QString::number(numtel);
QString c= QString::number(CIN);

query.prepare("INSERT into PERSONNELLES (CIN, NOM, PRENOM, ADDRESSE,DATEN,NUMEROTLF ,EMAIL,GRADE)" "values(:CIN, :nom, :prenom,  :adresse, :date, :numtel, :Email,:grade )");
//creation des variables liées
query.bindValue(":CIN",c);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":date",date);
query.bindValue(":numtel",res);
query.bindValue(":Email",Email);
query.bindValue(":grade",grade);


return query.exec();

}


 QSqlQueryModel * personelles::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from PERSONNELLES");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("grade"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("numtel"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("Email"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("adresse"));

     return model;

 }
bool personelles:: supprimer(int CIN)
{
QSqlQuery query;
QString c=QString::number(CIN);
query.prepare("Delete from PERSONNELLES where CIN= :CIN");
query.bindValue(":CIN",c);
return query.exec();
}



bool personelles:: modiffier(){
    QSqlQuery query;
      query.prepare( "UPDATE PERSONNELLES SET CIN=:CIN, NOM=:nom,PRENOM=:prenom , ADDRESSE=:adresse , DATEN=:date  ,NUMEROTLF=:numtel, EMAIL=:Email ,  GRADE=:grade WHERE CIN=:CIN;");
      query.bindValue(":CIN", CIN);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":grade", grade);
      query.bindValue(":date", date);
      query.bindValue(":numtel", numtel);
      query.bindValue(":Email", Email);
      query.bindValue(":adresse", adresse);




   return query.exec();

}


QSqlQueryModel * personelles::recherche(QString a)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PERSONNELLES WHERE ( CIN LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR PRENOM LIKE '%"+a+"%'OR ADDRESSE LIKE '%"+a+"%' OR DATEN LIKE '%"+a+"%' OR NUMEROTLF LIKE '%"+a+"%'OR EMAIL '%"+a+"%'OR GRADE LIKE '%"+a+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("grade"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));



return model;
}

