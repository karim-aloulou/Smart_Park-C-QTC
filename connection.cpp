#include "connection.h"


Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("TEST");
db.setUserName("machhout");//inserer nom de l'utilisateur
db.setPassword("machhout");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
