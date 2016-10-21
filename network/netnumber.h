#ifndef NETNUMBER_H
#define NETNUMBER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtCore>
#include <QList>

class NetNumber : public QObject
{
    Q_OBJECT
public:
    static QString getHtml(QString url);
    static void strToDB(QString str);
    static QList<QList<int>> getNumbers();
private:
    static void toDB(int number[100][9]);
};

#endif // NETNUMBER_H
