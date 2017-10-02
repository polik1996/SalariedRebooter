#include <iostream>
#include <QDebug>
#include <QFile>
#include <QtSql/QSqlDatabase>

#include "writer.h"
#include "databaseconnector.h"

using namespace  std;

int main(){
    Writer writer;
    DatabaseConnector connector;
    QSqlDatabase database;
//    QString id, app, stream, urls;
//    std::string temp;
//    QFile file;
//    cin>>temp;
//    cout<<endl;
//    id = temp.c_str();
//    cin>>temp;
//    cout<<endl;
//    app = temp.c_str();
//    cin>>temp;
//    cout<<endl;
//    stream = temp.c_str();
//    cin>>temp;
//    cout<<endl;
//    urls = temp.c_str();
//    writer.write_to_file(&file, "D:\\test\\test\\rules.conf", writer.create_string(id, app, stream, urls));
//    qDebug()<<writer.create_string(id, app, stream, urls)<<endl;
    connector.connect_to_database(database, "SalariedRebooter_Database", "postgres", "shans");
    system("pause");
    return 0;

}
