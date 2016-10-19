#include "netnumber.h"
#include <QDebug>

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
    QStringList list; //存储分隔的字符串的list
    QString temp = "data-period=\"";

    // 分隔成101个字符串（1 - 100）包含开奖号码，0是网站的信息头
    list = str.split(temp);

    QString sn,s1,s2,s3,s4,s5,s6,s7,st;

    for (int var = 1; var < list.size(); ++var) {
        sn = list[var].mid(0,7);
        s1 = list[var].mid(21,2);
        s2 = list[var].mid(24,2);
        s3 = list[var].mid(27,2);
        s4 = list[var].mid(30,2);
        s5 = list[var].mid(33,2);
        s6 = list[var].mid(36,2);
        s7 = list[var].mid(39,2);
        st = list[var].mid(42,2);

        qDebug() << sn << "-" << s1 << " " << s2 << " "
                 << s3 << " " << s4 << " " << s5 << " "
                 << s6 << " " << s7 << " " << st << endl;
    }

}
