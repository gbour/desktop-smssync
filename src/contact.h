#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QJsonObject>

class Contact : public QObject
{
    Q_OBJECT

public:
    explicit Contact(QString phoneNumber, QObject *parent = 0);
    QJsonObject* toJSON() const;
    static Contact *fromJSON(const QJsonObject);

    Q_INVOKABLE QString name() const;
    void setName(const QString &name);

    Q_INVOKABLE QString phoneNumber() const;

signals:

public slots:

private:
    QString m_phoneNumber;
    QString m_name;
    //TODO:avatar
};

#endif // CONTACT_H
