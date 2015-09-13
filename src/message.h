#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include "contact.h"

// not the right denomination
enum MessageType {
    INCOMING = 0,
    OUTGOING,
    ACKNOWLEDGEMENT
};

const QString _qMessageString[] { "INCOMING", "OUTGOING", "ACKNOWLEDGEMENT" };
#define QMessageString(t) _qMessageString[t]

class Message : public QObject
{
    Q_OBJECT

public:
    explicit Message(MessageType type, QString id, QObject *parent = 0);
    QJsonObject *toJSON() const;
    static Message *fromJSON(const QJsonObject);

    Q_INVOKABLE QString content() const;
    void setContent(const QString &content);

    Q_INVOKABLE QVariant contact() const;
    void setContact(Contact* contact);

signals:

public slots:

private:
    MessageType m_type;
    QString     m_id;
    Contact*    m_contact;

    // text message
    QString     m_content;
};

#endif // MESSAGE_H
