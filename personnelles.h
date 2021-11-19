#ifndef personelles_H
#define personelles_H
#include<QString>
#include<QSqlQuery>
#include <QSqlQueryModel>

class personelles
{
    QString nom, prenom, Email , adresse , grade , date  ;
    int CIN;
    int numtel;

public:
    //constructeurs
    personelles(){}
    personelles(int, int, QString, QString,QString,QString,QString,QString);


    //Getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getEmail(){return Email;}
    QString getadresse(){return adresse;}
    QString getgrade(){return grade;}
    QString getdate(){return date;}
    int getnumtel(){return numtel;}
    int getCIN(){return CIN;}

    //Setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setEmail(QString e){Email=e;}
    void setadresse(QString a){adresse=a;}
    void setgrade(QString g){grade=g;}
    void setdate(QString d){date=d;}
    void setnumtel(int nt){numtel=nt;}
    void setCIN(int c){CIN=c;}

    bool ajouter();
     QSqlQueryModel * afficher();

    bool supprimer(int);
QSqlQueryModel * recherche(QString a);

    bool modiffier();

};

#endif // FACTURE_H
