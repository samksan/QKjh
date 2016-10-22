#include <QCoreApplication>
#include "network/netnumber.h"
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = NetNumber::getHtml
            ("http://trend.caipiao.163.com/qlc/?periodNumber=100");

    NetNumber::strToDB(data);

    QList<QList<int>> list = NetNumber::getNumbers();

    foreach (QList<int> tempList, list) {
        qDebug() << tempList[0] << "," << tempList[1] << "," << tempList[2]
                                << ","<< tempList[3] << ","<< tempList[4]
                                << ","<< tempList[5] << ","<< tempList[6]
                                << ","<< tempList[7] << ","<< tempList[8] << endl;
    }

    return a.exec();
}
