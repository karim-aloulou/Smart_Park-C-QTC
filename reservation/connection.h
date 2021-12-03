#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQuery>

class Connection
{QSqlDatabase db;
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
