#include "visiteur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<qobject.h>
#include <QComboBox>
#include <QApplication>
#include <QtCore>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include<QPaintEngineState>
#include <QSystemTrayIcon>
#include<QMessageBox>
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
bool  Visiteur::supprimer()
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
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL"));
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
bool rechercher_id(int id)
{ QSqlQuery query;
    query.prepare("Select * from VISITEUR where ID= :id");
    query.bindValue(":ID", id);
    query.exec();
     QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery(query);
   if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
return  true;}

bool rechercher_tel(int tel)
{ QSqlQuery query;
    query.prepare("Select * from VISITEUR where TEL= :tel");
    query.bindValue(":TEL", tel);
    query.exec();
     QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery(query);
   if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
return  true;}

void Visiteur::genererPDFact()
{
    QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName("C:\\Users\\msi\\Desktop\\SMART_PARK\\Atelier_Connexion\\nonwritable.pdf");
       QPainter painter;
       if (! painter.begin(&printer)) {  qWarning("failed to open file, is it writable?"); return;}
       //printer.setPageMargins(QMargins(100, 50, 30, 30));
       painter.setPen(Qt::blue);
          painter.setFont(QFont("Arial", 50));
        painter.drawText(60,180, "~Attestation De Visite~");
        painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 12));
         painter.drawText(20,300, "Madame, Monieur\n");
          painter.drawText(20,330,"Park++ vous offre cette attestation, à présenter la prochaine fois pour bénificer de nos promos.");
          painter.setPen(Qt::red);
             painter.setFont(QFont("Arial", 30));
           painter.drawText(20,430, "Information visiteur");
painter.setPen(Qt::black);
          painter.drawRect(10,30,940,1300);

                                  painter.setFont(QFont("Arial", 13));
                                  painter.drawText(50,600,"ID");
                                  painter.drawText(200,600,"NOM");
                                  painter.drawText(350,600,"PRENOM");
                                  painter.drawText(520,600,"TEL");
                                  painter.drawText(650,600,"AGE");
                                  painter.drawText(800,600,"EMAIL");

                                  QSqlQuery query;
                                  query.prepare("Select * from VISITEUR where id=:id ");
                                  query.bindValue(":id", id);
                                  query.exec();

                                  while (query.next())
                                  {
                                      painter.drawText(50,700,query.value(0).toString());
                                      painter.drawText(200,700,query.value(1).toString());
                                      painter.drawText(350,700,query.value(2).toString());
                                      painter.drawText(520,700,query.value(5).toString());
                                      painter.drawText(650,700,query.value(3).toString());
                                      painter.drawText(800,700,query.value(4).toString());

                                  }

       painter.end();
}






Notification::Notification()
{

}

void Notification::notification_ajouter()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    //notifyIcon->setIcon(QIcon("C:/Users/asus/Desktop/pdf/logo_projet"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des VISITEUR ","nouveau VISITEUR est ajouté ",QSystemTrayIcon::Information,15000);
}




void Notification::notification_supprimer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des VISITEUR ","Un VISITEUR est supprimé",QSystemTrayIcon::Information,15000);
}




void Notification::notification_modifier(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des VISITEUR ","UN VISITEUR est modifié",QSystemTrayIcon::Information,15000);

}
