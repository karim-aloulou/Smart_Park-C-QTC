#include "personnelles.h"


personnelles::personnelles()
{
CIN="",nom="";prenom=""; date=" / / ";numtel=0; Email= ""; adresse="";grade="";
}

personnelles:: personnelles( QString CIN, QString nom,QString prenom,QString date,int numtel,QString Email,QString adresse, QString grade)
{
this->CIN =CIN;
    this-> nom=nom;
    this->prenom =prenom;


    this->date=date;
     this->numtel =numtel;
    this->Email=Email;
    this->adresse=adresse;
    this->grade=grade;
}



bool personnelles::ajouter()
{
QSqlQuery query;
QString res = QString::number(numtel);
QString c ;

query.prepare("INSERT into PERSONNELLES (CIN, NOM, PRENOM, DATE_DE_NAISSANCE ,NUMERO_DE_TELEPHONE,EMAIL,ADRESSE  ,GRADE)" "values(:CIN, :nom, :prenom, :date, :numtel, :Email,:adresse ,:grade )");
//creation des variables liées
query.bindValue(":CIN",c);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":date",date);
query.bindValue(":numtel",res);
query.bindValue(":Email",Email);
query.bindValue(":adresse",adresse);
query.bindValue(":grade",grade);


return query.exec();

}


 QSqlQueryModel * personnelles::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from PERSONNELLES");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("numtel"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("Email"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("grade"));

     return model;

 }
bool personnelles:: supprimer(int CIN)
{
QSqlQuery query;
QString c=QString::number(CIN);
query.prepare("Delete from PERSONNELLES where CIN= :CIN");
query.bindValue(":CIN",c);
return query.exec();
}



bool personnelles:: modiffier(){
    QSqlQuery query;
      query.prepare( "UPDATE PERSONNELLES SET CIN=:CIN, NOM=:nom,PRENOM=:prenom , DATE_DE_NAISSANCE=:date, NUMERO_DE_TELEPHONE =:numtel , EMAIL=:Email , ADRESSE =:adresse, GRADE=:grade WHERE CIN=:CIN;");
      query.bindValue(":CIN", CIN);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":date", date);
      query.bindValue(":numtel", numtel);
      query.bindValue(":Email", Email);
      query.bindValue(":adresse", adresse);
      query.bindValue(":grade", grade);





   return query.exec();

}


QSqlQueryModel * personnelles::recherche(QString c)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * from PERSONNELLES where CIN like '%"+c+"%' OR NOM like '%"+c+"%' OR PRENOM like '%"+c+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("grade"));




return model;
}
QSqlQueryModel* personnelles::trie(QString index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        QString c ;
        model->setQuery("select *FROM PERSONNELLES  order BY CIN  ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("grade"));




    return model;
}
QSqlQueryModel* personnelles:: trie_age (QString index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        QString c ;
        model->setQuery("select *FROM PERSONNELLES  ORDER BY AGE  ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("age "));
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("grade"));




    return model;
}
QSqlQueryModel* personnelles::trie_nom(QString index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        QString c ;
        model->setQuery("select *FROM PERSONNELLES  ORDER BY NOM   ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("grade"));




    return model;
}
