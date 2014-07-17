#include "network/httpsclient.h"


#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslCertificate>
#include <QtGlobal>
#include <QtNetwork/QHttpPart>
#include <iostream>


HttpsClient::HttpsClient(NetworkInterface* callback)
{
    this->callback=callback;
    this->task = "";
    this->jsonRequest = "";
    networkManager = new QNetworkAccessManager();
}

HttpsClient::~HttpsClient()
{
    //networkManager->~
    //delete networkManager;
    //delete callback;
    //delete networkManager;
}


void
HttpsClient::setTask(QString task){
    this->task =task;
}

void
HttpsClient::setJsonRequest(QString jsonRequest){
    this->jsonRequest = jsonRequest;
}

void
HttpsClient::execute(){


    QUrl url(SERVER_ADDR+task);
    QNetworkRequest request(url);
    QObject::connect(networkManager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedRequest(QNetworkReply*)));

    // QByteArray postDataSize = QByteArray::number(jsonRequest.toUtf8().size());


    request.setRawHeader("Content-Type", "application/json");

    //request.setRawHeader("Content-Length", postDataSize);
    //request.setRawHeader("Connection", "Close");


    QNetworkReply *reply = networkManager->post(request, jsonRequest.toUtf8());

}

void
HttpsClient::finishedRequest(QNetworkReply* reply){
     std::cout << "in" <<std::endl;
    // Reading attributes of the reply
        // e.g. the HTTP status code
        // no error received?
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray bytes = reply->readAll();
            QString string(bytes); //
            std::cout << string.toStdString() << std::endl;
            std::cout << "found some" << std::endl;
            callback->NetworkCallback(task, string);

        }
        // Some http error received
        else
        {
           std::cout << "error" <<std::endl;
            // handle errors here

        }

        // We receive ownership of the reply object
        // and therefore need to handle deletion.
       // networkManager->finished(reply);
        //reply->close();
       //delete reply;

}
