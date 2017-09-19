#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include <QHash>

class Writer{

public:
    const QString protokol = "\"protocol\":\"RTSP\"";
    const QString duration = "\"duration\":0";
    const QString transmux = "\"transmux\":[]";
    const QString idle_time = "\"idle_time\":15";
    const QString multi_stream = "\"multi_streams\":false";
    const QString rtsp_settings = "\"RtspSettings\":{\"mode\":\"TCP_UDP\",\"http_proxy\":\"\"}";

    const QString id = "\"id\":";
    const QString app = "\"app\":";
    const QString stream = "\"stream\":";
    const QString urls = "\"urls\":";

    const QString divider = ",";

public:
    Writer();
    QString create_string(QString id, QString app, QString stream, QString urls);
    bool write_to_file(QString str);
    int create_id(QString area, int last_number);
    void init_area_code_table(QHash<QString, int> table);

};

#endif // WRITER_H
