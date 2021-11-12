#ifndef VISITEUR_H
#define VISITEUR_H
#include<qsqlquerymodel.h>
#include<QString>

class Visiteur
{
public:
    Visiteur();
    Visiteur (int,QString,QString,int,int,QString,QString);
    int getid();
    int gettel();
    int getage();
    QString getemail();
    QString getetat();
    void setetat(QString);
    QString getnom();
    QString getprenom();
    void setid(int);
    void settel(int);
    void setage(int);
    void setnom(QString);
    void setemail(QString);
    void setprenom(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id,int num_tel,QString nom,QString prenom,QString mail,QString etat);
    QSqlQueryModel *trideccroissant();
    QSqlQueryModel *tricroissant();
    bool  rechercher(QString etat);
private:
    int id,age,tel;
    QString nom, prenom,email,etat;
};

#endif // Visiteur_H
