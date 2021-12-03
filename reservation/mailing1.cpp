/*#include "reservation/mailing1.h"
#include "ui_mailing1.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QString>
#include <QDebug>
#include "reservation/smtp.h"
mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("SELECT EMAIL FROM VISITEURS")  ;
    ui->combobox_email->setModel(model);
    qDebug()<<(model->rowCount());

}

mailing::~mailing()
{
    delete ui;
}

 void mailing::on_pushButton_clicked()
 {
    Smtp* smtp = new Smtp("parksmart414@gmail.com","emna1234","smtp.gmail.com",465);
        QString object=ui->objetit->text();
        QString message=ui->message->toPlainText();

                    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                    smtp->sendMail("parksmart414@gmail.com","khilfaouiemna9@gmail.com",object,message);
 }
*/
