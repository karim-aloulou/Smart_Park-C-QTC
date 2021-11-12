#include "visiteur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<qobject.h>
#include <QComboBox>
Visiteur::Visiteur()
{
id=0;
nom=" ";
prenom=" ";
}

Visiteur::Visiteur (int id, QString nom ,QString prenom,int age,int tel,QString email,QString etat)
{
this->id=id;
    this->email=email;
    this->age=age;
    this->tel=tel;
this->nom=nom;
this->prenom=prenom;
    this->etat=etat;
}

int Visiteur:: getid()
{
return id;
}

int Visiteur:: getage()
{
return age;
}

int Visiteur:: gettel()
{
return tel;
}

QString Visiteur:: getemail()
{
return email;
}
QString Visiteur:: getetat()
{
return etat;
}
void Visiteur:: setetat(QString etat)
{this->etat=etat;}

void Visiteur:: setemail(QString(em))
{this->email=em;}

void Visiteur:: settel(int tel)
{this->tel=tel;}

void Visiteur:: setage(int age)
{this->age=age;}

QString Visiteur::getnom()
{return nom;}
QString Visiteur:: getprenom()
{
return prenom;
}

void Visiteur:: setid(int id)
{this->id=id;}

void Visiteur:: setnom(QString nom)
{this->nom=nom;}
void Visiteur:: setprenom(QString prenom )
{this->prenom=prenom;}
bool Visiteur::ajouter()
{

    QSqlQuery query;
    QString id_string=QString:: number(id);
    QString tel_string=QString:: number(tel);
    QString age_string=QString:: number(age);

    query.prepare("INSERT INTO Visiteur (id, nom, prenom,age,tel,email,etat) "
                  "VALUES (:id, :nom, :prenom, :age, :tel,:email,:etat)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
     query.bindValue(":age",age_string);
      query.bindValue(":email",email );
        query.bindValue(":etat",etat );
       query.bindValue(":tel", tel_string);
    return query.exec();
}
bool  Visiteur::supprimer(int id)
{  QSqlQuery query;
    QString id_string=QString:: number(id);
    query.prepare("Delete from visiteur where id=:id");
    query.bindValue(":id", id);
    return query.exec();
}


QSqlQueryModel* Visiteur::afficher()
{
 QSqlQueryModel*model=new QSqlQueryModel();


      model->setQuery("SELECT* FROM visiteur");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));


 return  model;
}
bool Visiteur::modifier(int id,int tel,QString nom,QString prenom,QString email,QString etat)
{

    QSqlQuery query;

    QString res=QString::number(id);
    QString res2=QString::number(tel);
    query.prepare("UPDATE VISITEUR SET nom= :nom, prenom= :prenom, tel= :tel, email= :email,etat= :etat where id= :id ");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":etat",etat);
    query.bindValue(":tel",res2);

            return    query.exec();

}

QSqlQueryModel * Visiteur::tricroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM VISITEUR ORDER BY age ASC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));



    return model;
}
QSqlQueryModel * Visiteur::trideccroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM VISITEUR ORDER BY age DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));


    return model;
}

bool Visiteur::rechercher(QString etat)
{

    QSqlQuery query;
               query.prepare("Select * from VISITEUR where etat= :etat");
               query.bindValue(":etat", etat);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
           return  true;


}
