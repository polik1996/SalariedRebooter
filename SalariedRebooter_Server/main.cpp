#include <iostream>
#include <QDebug>

#include "writer.h"

using namespace  std;

int main(){
    Writer writer;
    QString id, app, stream, urls;
    std::string temp;
    cin>>temp;
    cout<<endl;
    id = temp.c_str();
    cin>>temp;
    cout<<endl;
    app = temp.c_str();
    cin>>temp;
    cout<<endl;
    stream = temp.c_str();
    cin>>temp;
    cout<<endl;
    urls = temp.c_str();
    writer.write_to_file(writer.create_string(id, app, stream, urls));
    qDebug()<<writer.create_string(id, app, stream, urls)<<endl;
    system("pause");
    return 0;
}
