#ifndef TICKETS_H
#define TICKETS_H
#include <QString>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDir>

class tickets
{
public:
    tickets();
    tickets(int,QString,QString,QString,QString);
    bool ajouter_tickets();
    QSqlQueryModel * afficher_tickets();
    bool supprimer_tickets(int);
    bool modifier_tickets(int);

        int getcode();
        QString getnumero(){return numero;};
        QString getprix(){return prix;};
        QString getdate(){return date;};
        QString gettype(){return type;};
        void setcode(int);
        void setnumero(QString);
        void setprix(QString);
        void setdate(QString);
        void settype(QString);
        QSqlQueryModel *afficher_recherche(QString ch);
        QSqlQueryModel *afficher_recherche2(QString ch);
        QSqlQueryModel *afficher_recherche3(QString ch);
        QSqlQueryModel * afficher_choix(QString choix);



    private:
        int code;
        QString numero,prix,date,type;

};

#endif // TICKETS_H
