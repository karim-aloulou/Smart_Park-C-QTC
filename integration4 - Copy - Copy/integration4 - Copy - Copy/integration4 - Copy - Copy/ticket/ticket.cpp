#include "ticket.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

tickets::tickets()
{
code=0;
numero="";
prix="";
date="";
type="";

}
tickets::tickets(int c,QString n,QString p,QString d,QString l)
{
    code=c;
    numero=n;
    prix=p;
    date=d;
    type=l;

}
bool tickets::ajouter_tickets()
{
    QSqlQuery query;
    QString codes=QString::number(code);
    query.prepare("INSERT INTO tickets(CODE, NUMERO, PRIX, DATES, TYPE)"
                  "VALUES(:code, :numero, :prix, :date, :type)");

    query.bindValue(":code",codes);
    query.bindValue(":numero",numero);
    query.bindValue(":prix",prix);
    query.bindValue(":date",date);
    query.bindValue(":type",type);

    return query.exec();
}
QSqlQueryModel * tickets::afficher_tickets()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from tickets");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("code ticket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

 bool tickets::supprimer_tickets(int idc)
 {
     QSqlQuery query; //requete
     QString res=QString::number(idc);
     query.prepare("delete from tickets where CODE= :id");
     query.bindValue(":id",res);
     return query.exec();
 }

bool tickets::modifier_tickets(int idd)
 {
     QSqlQuery query;
     QString res=QString::number(idd);
     query.prepare("Update tickets set code = :id , numero = :numero , prix = :prix, dates = :dates , type = :type   where code = :id ");
     query.bindValue(":id", res);
     query.bindValue(":code",code);
     query.bindValue(":numero",numero);
     query.bindValue(":prix",prix);
     query.bindValue(":dates",date);
     query.bindValue(":type",type);
     return query.exec();
 }

QSqlQueryModel *tickets:: afficher_recherche(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM tickets where  CODE='"+ch+"' ");

    return model ;
}
QSqlQueryModel *tickets:: afficher_recherche2(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM tickets where  NUMERO='"+ch+"' ");

    return model ;
}
QSqlQueryModel *tickets:: afficher_recherche3(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM tickets where  DATES='"+ch+"' ");

    return model ;
}


QSqlQueryModel *tickets:: afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

     if(choix=="CODE CROISSANT")
    {
        model->setQuery("SELECT * FROM tickets  ORDER BY CODE  ;");
    }
    else if(choix=="CODE DECROISSANT")
    {
        model->setQuery("SELECT * FROM tickets  ORDER BY CODE DESC;");
    }
     else if(choix=="NUMERO CROISSANT")
     {
         model->setQuery("SELECT * FROM tickets ORDER BY NUMERO ASC;");
     }else if(choix=="NUMERO DECROISSANT")
     {
         model->setQuery("SELECT * FROM tickets ORDER BY NUMERO DESC;");
     }
    else if (choix=="choisir")
    {
        model->setQuery("SELECT * FROM tickets ");
    }


    return model;



}
