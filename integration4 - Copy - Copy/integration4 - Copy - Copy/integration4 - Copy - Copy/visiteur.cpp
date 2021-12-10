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
id_v=0;
nom=" ";
prenom=" ";
}

Visiteur::Visiteur (int id_v, QString nom ,QString prenom,int age,int tel,QString email,QString etat)
{
this->id_v=id_v;
    this->email=email;
    this->age=age;
    this->tel=tel;
this->nom=nom;
this->prenom=prenom;
    this->etat=etat;
}

int Visiteur:: getid_v()
{
return id_v;
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

void Visiteur:: setid_v(int id_v)
{this->id_v=id_v;}

void Visiteur:: setnom(QString nom)
{this->nom=nom;}
void Visiteur:: setprenom(QString prenom )
{this->prenom=prenom;}
bool Visiteur::ajouter()
{

    QSqlQuery query;
    QString id_v_string=QString:: number(id_v);
    QString tel_string=QString:: number(tel);
    QString age_string=QString:: number(age);

    query.prepare("INSERT INTO Visiteur (id_v, nom, prenom,age,tel,email,etat) "
                  "VALUES (:id_v, :nom, :prenom, :age, :tel,:email,:etat)");
    query.bindValue(":id_v", id_v_string);
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
    QString id_v_string=QString:: number(id_v);
    query.prepare("Delete from visiteur where id_v=:id_v");
    query.bindValue(":id_v", id_v);
    return query.exec();
}


QSqlQueryModel* Visiteur::afficher()
{
 QSqlQueryModel*model=new QSqlQueryModel();


      model->setQuery("SELECT* FROM visiteur");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_V"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));


 return  model;
}
bool Visiteur::modifier(int id_v,int tel,QString nom,QString prenom,QString email,QString etat)
{

    QSqlQuery query;

    QString res=QString::number(id_v);
    QString res2=QString::number(tel);
    query.prepare("UPDATE VISITEUR SET nom= :nom, prenom= :prenom, tel= :tel, email= :email,etat= :etat where id_v= :id_v ");
    query.bindValue(":id_v",res);
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

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_V"));
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

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_V"));
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
bool rechercher_id_v(int id_v)
{ QSqlQuery query;
    query.prepare("Select * from VISITEUR where ID_V= :id_v");
    query.bindValue(":ID_V", id_v);
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
       printer.setOutputFileName("C:\\Users\\21694\\Desktop\\integration4 - Copy - Copy\\integration4 - Copy - Copy\\nonwritable.pdf");
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
                                  painter.drawText(50,600,"ID_V");
                                  painter.drawText(200,600,"NOM");
                                  painter.drawText(350,600,"PRENOM");
                                  painter.drawText(520,600,"TEL");
                                  painter.drawText(650,600,"AGE");
                                  painter.drawText(800,600,"EMAIL");

                                  QSqlQuery query;
                                  query.prepare("Select * from VISITEUR where id_v=:id_v ");
                                  query.bindValue(":id_v", id_v);
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
