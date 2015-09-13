
#include <QDebug>

#include "message.h"

Message::Message(MessageType type, QString id, QObject *parent) :
    QObject(parent)
{
    m_type = type;
    m_id   = id;
}

QJsonObject *Message::toJSON() const
{
    QJsonObject *obj = new QJsonObject();
    obj->insert("id", m_id);

    if (m_type == MessageType::ACKNOWLEDGEMENT) {
        obj->insert("type", QString("ack"));
        return obj;
    }

    obj->insert("type", QString("msg"));
    obj->insert("dir" , QString(m_type == MessageType::INCOMING ? "in" : "out"));

    obj->insert("content", m_content);
    obj->insert("contact", *m_contact->toJSON());

    return obj;
}

Message *Message::fromJSON(const QJsonObject obj)
{
    Message *m = NULL;

    if ( obj["type"] == "msg" ) {
            MessageType type;
            if ( obj["dir"] == "in" ) {
                type = MessageType::INCOMING;
            } else if ( obj["dir"] == "out" ) {
                type = MessageType::OUTGOING;
            }

            m = new Message(type, "1");
            m->setContent(obj["content"].toString());
            m->setContact(Contact::fromJSON(obj["contact"].toObject()));
    }

    return m;
}

QString Message::content() const
{
    return m_content;
}

void Message::setContent(const QString &content)
{
    m_content = content;
}

QVariant Message::contact() const
{
    return qVariantFromValue(m_contact);
}

void Message::setContact(Contact* contact)
{
    m_contact = contact;
}



