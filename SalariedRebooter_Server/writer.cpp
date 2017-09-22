#include <QString>
#include <QDebug>
#include <QTextStream>

#include "writer.h"

Writer::Writer(){}

QString Writer::create_string(QString id, QString app, QString stream, QString urls){
    QString string = "{";
    string += this->id + id + this->divider +
            this->app + app + this->divider +
            this->stream + stream + this->divider +
            this->urls + urls + this->divider +
            this->protokol + this->divider +
            this->duration + this->divider +
            this->transmux + this->divider +
            this->idle_time + this->divider +
            this->multi_stream + this->divider +
            this->rtsp_settings + this->divider + "},";
    return string;
}

bool Writer::write_to_file(QFile *file, QString path_file, QString str){
    file->setFileName(path_file);
    file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if(file->isOpen()){
        qDebug()<<"file is open!";
        QTextStream q_str;
        q_str.setDevice(file);
        q_str<<str<<endl;
        file->close();
        return true;
    }else{
        return false;
    }
}

QString Writer::create_id(QSqlQuery *query, DatabaseConnector connector, QString region_name, bool cam_type, QString new_id){
    if(cam_type == false){
        new_id = connector.get_regione_code(query, region_name) + "000"
                + QString::number(connector.get_cams_count(query, region_name) + 1);
    }else if(cam_type == true){
        new_id = connector.get_regione_code(query, region_name) + "000"
                + QString::number(connector.get_cams_count(query, region_name) + 1) + "1";
    }
    return new_id;
}
