#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>

#include "databaseconnector.h"

DatabaseConnector::DatabaseConnector(){}

bool DatabaseConnector::connect_to_database(QSqlDatabase database, QString database_name, QString user, QString password){
    database = QSqlDatabase::addDatabase("QODBC");
    database.setDatabaseName(database_name);
    database.setUserName(user);
    database.setPassword(password);
    if(!database.open()){
        qDebug()<<"Conection failed!";
        return false;
    }
    qDebug()<<"Conection successful!";
    return true;
}

QString DatabaseConnector::get_regione_code(QSqlQuery *query, QString regione_name){
    query->prepare("select code	from regione_code where region = :regione_name");
    query->bindValue(":regione_name", regione_name);
    query->exec();
    if(query->next()){
        return query->value(0).toString();
    }
    return query->value(0).toString();
}
