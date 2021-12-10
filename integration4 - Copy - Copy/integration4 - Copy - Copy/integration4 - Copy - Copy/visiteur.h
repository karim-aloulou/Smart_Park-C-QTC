#ifndef VISITEUR_H
#define VISITEUR_H
#include<qsqlquerymodel.h>
#include<QString>
#include <QSystemTrayIcon>



class Visiteur
{
public:
    Visiteur();
    Visiteur (int,QString,QString,int,int,QString,QString);
    int getid_v();
    int gettel();
    int getage();
    QString getemail();
    QString getetat();
    void setetat(QString);
    QString getnom();
    QString getprenom();
    void setid_v(int);
    void settel(int);
    void setage(int);
    void setnom(QString);
    void setemail(QString);
    void setprenom(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
    bool supprimer();
    bool modifier(int id_v,int num_tel,QString nom,QString prenom,QString mail,QString etat);
    QSqlQueryModel *trideccroissant();
    QSqlQueryModel *tricroissant();
    bool  rechercher(QString etat);
    bool rechercher_id(int id_v);
    bool rechercher_tel(int tel);
    void genererPDFact();


private:
    int id_v,age,tel;
    QString nom, prenom,email,etat;
};


class Notification
{
public:
    Notification();
    void notification_ajouter();

    void notification_supprimer();

    void notification_modifier();

};



#endif // Visiteur_H
