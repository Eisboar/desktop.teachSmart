#ifndef HTTPSCLIENT_H
#define HTTPSCLIENT_H

#include "network/networkinterface.h"
#include <QString>
//#include <ui/mainwindow.h>
#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QtCore>


//using namespace std;

class HttpsClient: public QObject{
Q_OBJECT

private:
    NetworkInterface* callback;
    QString task;
    QString jsonRequest;
    QNetworkAccessManager *networkManager;
public:
    HttpsClient(NetworkInterface*);
    ~HttpsClient();
    void execute();
    void setTask(QString);
    void setJsonRequest(QString);
    const QString SERVER_ADDR = "http://localhost:8081/wanda.backend/";
    //const QString SERVER_ADDR2 = "https://localhost:8443/wanda.backend/login";

public slots:
      void finishedRequest(QNetworkReply*);

};

#endif // HTTPSCLIENT_H
