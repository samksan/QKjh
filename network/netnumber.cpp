#include "netnumber.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

void NetNumber::toDB(int number[100][9])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("kjh.db");
    db.open();

    QSqlQuery query;

    bool success;
//    success = query.exec("create table kjh(sn int primarykey,n1 int,n2 int,n3 int,n4 int,n5 int,n6 int,n7 int,nt int)");
//    if(success)
//        qDebug() << "create database table kjh success" << endl;
//    else
//        qDebug() << "create database table kjh failed" << endl;

    for (int var = 0; var < 100; ++var) {
        query.bindValue(0,number[var][0]);
        query.bindValue(1,number[var][1]);
        query.bindValue(2,number[var][2]);
        query.bindValue(3,number[var][3]);
        query.bindValue(4,number[var][4]);
        query.bindValue(5,number[var][5]);
        query.bindValue(6,number[var][6]);
        query.bindValue(7,number[var][7]);
        query.bindValue(8,number[var][8]);
        success = query.exec();
        if(success)
            qDebug() << "Success" << endl;
        else
            qDebug() << "Failed" << endl;
    }



    //    for (int var = 0; var < 100; ++var) {
    //        qDebug() << number[var][0] << "," << number[var][1] << "," << number[var][2]
    //                                   << "," << number[var][3] << "," << number[var][4]
    //                                   << "," << number[var][5] << "," << number[var][6]
    //                                   << "," << number[var][7] << "," << number[var][8]
    //                                   << endl;
    //    }
}

QString NetNumber::getHtml(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    responseData = reply->readAll();
    return QString(responseData);
}

void NetNumber::strToDB(QString str)
{
    QStringList list;
    QString temp = "data-period=\"";

    // 分隔成101个字符串（1 - 100）包含开奖号码，0是网站的信息头
    list = str.split(temp);
    list.removeFirst();

    QString sn,s1,s2,s3,s4,s5,s6,s7,st;
    int result[100][9];

    for (int var = 0; var < list.size(); ++var) {
        sn = list[var].mid(0,7);
        s1 = list[var].mid(21,2);
        s2 = list[var].mid(24,2);
        s3 = list[var].mid(27,2);
        s4 = list[var].mid(30,2);
        s5 = list[var].mid(33,2);
        s6 = list[var].mid(36,2);
        s7 = list[var].mid(39,2);
        st = list[var].mid(42,2);
        result[var][0] = sn.toInt();
        result[var][1] = s1.toInt();
        result[var][2] = s2.toInt();
        result[var][3] = s3.toInt();
        result[var][4] = s4.toInt();
        result[var][5] = s5.toInt();
        result[var][6] = s6.toInt();
        result[var][7] = s7.toInt();
        result[var][8] = st.toInt();
    }
    NetNumber::toDB(result);

}


