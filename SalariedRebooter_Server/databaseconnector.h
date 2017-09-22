#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QtSql/QSqlDatabase>

class DatabaseConnector{

public:
    DatabaseConnector();
    bool connect_to_database(QSqlDatabase database, QString database_name, QString user, QString password);
    QString get_regione_code(QSqlQuery *query, QString regione_name);
    bool set_cams_count(QSqlQuery *query, QString regione_name, int new_count);
    int get_cams_count(QSqlQuery *query, QString regione_name);
    QString get_last_id_from_region(QSqlQuery *query, QString regione_name, QString last_id);

};

#endif // DATABASECONNECTOR_H
