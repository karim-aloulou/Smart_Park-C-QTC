#ifndef SERVICES_H
#define SERVICES_H


#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
//#include <qcustomplot.h>
//#include <QChart>
//#include <Qchartview>
//#include <QPieSeries>

class SERVICES
{


private:
    QString HEURE_O,HEURE_F;
    QString ID_SERVICE  ;
    QString TYPE_SERVICE;
    QString ETAT;
public:
    SERVICES();
    SERVICES(QString,QString,QString,QString,QString);
    QString get_HEURE_O(){return HEURE_O;};
    QString get_HEURE_F(){return HEURE_F;};
    QString get_ID_SERVICE(){return ID_SERVICE;};
    QString get_TYPE_SERVICE(){return TYPE_SERVICE;};
    QString get_ETAT(){return ETAT;};
    void setID_SERVICE(QString);


    bool ajouter_SERVICES();
    QSqlQueryModel * afficher_SERVICES();
    bool supprimer_SERVICES(QString);
    bool modifier();
    QSqlQueryModel * tri();
     QSqlQueryModel * tri_t();
      QSqlQueryModel * tri_e();
      QSqlQueryModel *rechercher(QString searche);




};


#endif // SERVICES_H
