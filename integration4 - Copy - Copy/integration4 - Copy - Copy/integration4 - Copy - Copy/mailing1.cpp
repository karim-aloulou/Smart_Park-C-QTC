#include "mailing1.h"
#include "ui_mailing1.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QString>
#include <QDebug>
#include<QDialog>
#include<QObject>

#include "reservation/smtp.h"

mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("SELECT EMAIL FROM VISITEUR")  ;
    ui->combobox_email->setModel(model);
    qDebug()<<(model->rowCount());

}

mailing::~mailing()
{
    delete ui;
}

 void mailing::on_pushButton_clicked()
 {
     //Smtp smtp("parksmart414@gmail.com","emna1234","smtp.gmail.com",465);
     //Smtp* sp= new Smtp("parksmart414@gmail.com","emna1234","smtp.gmail.com",465);
    //Smtp* smtp = new Smtp(sm);
     Smtp* sp= new Smtp("parksmart414@gmail.com","emna1234","smtp.gmail.com",465);

        QString object=ui->objetit->text();
        QString message=ui->message->toPlainText();
        QObject::connect(sp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        sp->sendMail("parksmart414@gmail.com","khilfaouiemna9@gmail.com",object,message);
 }

