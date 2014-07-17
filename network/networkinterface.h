#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#include <QString>

class NetworkInterface
{

public:
       virtual void NetworkCallback(QString, QString) = 0;
};

#endif // NETWORKINTERFACE_H
