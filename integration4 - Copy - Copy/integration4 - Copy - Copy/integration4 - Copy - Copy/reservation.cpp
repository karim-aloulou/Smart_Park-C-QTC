#include "reservation.h"
#include<iostream>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Reservation::Reservation()
{
id=0; date=" / / "; heure= " : "; type_parking="";id_v=0;
}
Reservation::Reservation(int id, QString date ,QString heure, QString type_parking,int id_v)
{
    this->id=id;

    this->date=date;
     this->heure=heure;
     this->type_parking=type_parking;
      this->id_v=id_v;}
 int Reservation::getid(){return id;}

 QString Reservation:: getdate(){return date;}
   QString Reservation:: getheure(){return heure;}
 QString Reservation:: gettype_parking(){return type_parking;}
 int Reservation::getid_v(){return id_v;}
 void Reservation ::setid(int id){this->id=id;}

 void Reservation:: setdate( QString date){this->date=date;}
 void Reservation:: setheure( QString heure){this->heure=heure;}
 void Reservation:: settype_parking(QString type_parking){this->type_parking=type_parking;}
 void Reservation ::setid_v(int id_v){this->id_v=id_v;}



 bool Reservation::ajouter()
{

  QSqlQuery query;
  QString id_string=QString::number(id);
  QString id_v_s=QString::number(id_v);
        query.prepare("INSERT INTO RESERVATION (ID, DATE_R,HEURE,TYPE_PARKING,ID_V) "
                      "VALUES(:id, :date,:heure,:type_parking,:id_v)");
        query.bindValue(":id", id_string);

        query.bindValue(":date", date);
        query.bindValue(":heure", heure);
        query.bindValue(":type_parking", type_parking);
        query.bindValue(":id_v", id_v_s);
        return query.exec();

}
QSqlQueryModel* Reservation::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM reservation");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEURE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_R"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_PARKING"));
        return model;
}
bool Reservation::modifier(int id ,QString D,QString H,QString t )
{
QSqlQuery query;

 QString res=QString::number(id);
 QString res1=QString::number(id_v);
 query.prepare("UPDATE RESERVATION SET  DATE_R = :date ,HEURE= :heure ,TYPE_PARKING = :TYPE_PARKING  where ID= :id ");
 query.bindValue(":id",res);
 query.bindValue(":date", D);
 query.bindValue(":heure", H);

query.bindValue(":TYPE_PARKING", t);

//query.bindValue(":id_v",id_v);


return    query.exec();
}

bool Reservation::supprimer(int id)
{

    QSqlQuery query;
          query.prepare("Delete from RESERVATION where id=:id");

          query.bindValue(0, id);
          return query.exec();
}
//Trie Par DATEasc
QSqlQueryModel * Reservation::trierReservationParDATE_ASC()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM RESERVATION order by DATE_R ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par Date desc
QSqlQueryModel * Reservation::trierReservationParDATE_DESC()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM RESERVATION order by DATE_R DESC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par Heure asc
QSqlQueryModel * Reservation::trierReservationParHEURE_asc()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM RESERVATION order by HEURE ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}
//trier par heure desc
QSqlQueryModel * Reservation::trierReservationParHEURE_DESC()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM RESERVATION order by HEURE DESC");
           q->exec();
           model->setQuery(*q);
           return model;
}
