#ifndef NETNUMBER_H
#define NETNUMBER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtCore>

class NetNumber : public QObject
{
    Q_OBJECT
public:
    static QString getHtml(QString url);
    static void strToDB(QString str);
};

#endif // NETNUMBER_H
