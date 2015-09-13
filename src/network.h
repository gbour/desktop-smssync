#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

#include "qmqtt.h"
#include "message.h"

class Network: public QObject
{
    Q_OBJECT

public:
    explicit Network(QString server, int port, QObject *parent = 0);

signals:
    //void incomingMessage(const QString content);
    // content type is Message
    void incomingMessage(const QVariant content);
    void mimi();

public slots:
    void onConnected();
    void onIncomingMessage(const QMQTT::Message);

private:
    QMQTT::Client *m_client;
};

#endif // NETWORK_H
