#include "connection.h"
//test tutoriel git

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("projet");
db.setUserName("khilfaoui");//inserer nom de l'utilisateur
db.setPassword("khilfaoui");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
