#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <QString>
#include <QSqlQueryModel>

class Reservation
{
public:
    Reservation();
     Reservation(int, QString,QString, QString,QString);
     int getid();


       QString getdate();
       QString getheure();
     QString gettype_parking();
   QString getid_v();
     void setid(int);

     void setdate( QString);
     void setheure( QString);
     void settype_parking(QString);
     void setid_v(QString);
     bool ajouter();
     QSqlQueryModel* afficher();
         bool modifier(int id ,QString date,QString heure,QString t,QString id_v);
         bool supprimer(int);
          QSqlQueryModel* trierReservationParDATE_ASC();
          QSqlQueryModel * trierReservationParDATE_DESC();
          QSqlQueryModel * trierReservationParHEURE_asc();
          QSqlQueryModel * trierReservationParHEURE_DESC();

private:
    int id;
    QString id_v;
     QString date,heure;
    QString type_parking;
};

#endif // RESERVATION_H
