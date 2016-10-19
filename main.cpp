#include <QCoreApplication>
#include "network/netnumber.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = NetNumber::getHtml
            ("http://trend.caipiao.163.com/qlc/?periodNumber=100");

    NetNumber::strToDB(data);

//    qDebug() << data << endl;
    return a.exec();
}
