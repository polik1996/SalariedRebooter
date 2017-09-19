#include <QString>
#include <QFile>
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

bool Writer::write_to_file(QString str){
    QFile file;
    file.setFileName("D:\\test\\test\\rules.conf");
    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if(file.isOpen()){
        qDebug()<<"file is open!";
        QTextStream q_str;
        q_str.setDevice(&file);
        q_str<<str<<endl;
        file.close();
        return true;
    }else{
        return false;
    }
}

int Writer::create_id(QString area, int last_number){}

void Writer::init_area_code_table(QHash<QString, int> table){}
