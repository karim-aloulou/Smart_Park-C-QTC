#ifndef personnelles_H
#define personnelles_H
#include<QString>
#include <iostream>
#include<QSqlQuery>
#include <QSqlQueryModel>

class personnelles
{


public:
    //constructeurs
    personnelles();
    personnelles( QString, QString,QString,QString,int,QString,QString,QString);


    //Getters
    QString getCIN(){return CIN;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getdate(){return date;}
    int getnumtel(){return numtel;}
    QString getEmail(){return Email;}
    QString getadresse(){return adresse;}
    QString getgrade(){return grade;}


    //Setters

    void setCIN(QString c){CIN=c;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setdate(QString d){date=d;}
    void setnumtel(int nt){numtel=nt;}
    void setEmail(QString e){Email=e;}
    void setadresse(QString a){adresse=a;}
    void setgrade(QString g){grade=g;}




    bool ajouter();
     QSqlQueryModel * afficher();

    bool supprimer(int);
QSqlQueryModel * recherche(QString );

    bool modiffier();
    QSqlQueryModel* trie(QString);
     QSqlQueryModel* trie_age(QString);
      QSqlQueryModel* trie_nom(QString);
private:
      QString nom, prenom, Email , adresse , grade , date ,  CIN ;

      int numtel;
};


#endif // FACTURE_H
