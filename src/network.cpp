
#include <QDebug>
#include <QJsonDocument>

#include "network.h"
#include "message.h"

Network::Network(QString server, int port, QObject *parent) :
    QObject(parent)
{
    m_client = new QMQTT::Client(server, port, QMQTT::Transport::SSL);

    QObject::connect(m_client, SIGNAL(connacked(quint8)), this, SLOT(onConnected()));
    QObject::connect(m_client, SIGNAL(received(QMQTT::Message)),
                     this, SLOT(onIncomingMessage(QMQTT::Message)));
    m_client->connect();
}

void Network::onConnected() {
    qDebug() << "mqtt::connected";
    m_client->subscribe("smssync/#", 1);
}

void Network::onIncomingMessage(QMQTT::Message qmsg)
{
    qDebug() << "mqtt:incoming message:" << qmsg.id() << qmsg.topic() << qmsg.payload();

    QJsonDocument jdoc = QJsonDocument::fromJson(qmsg.payload());
    Message *m = Message::fromJSON(jdoc.object());

    emit incomingMessage(qVariantFromValue(m));
}


