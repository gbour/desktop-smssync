#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QObject>
#include <QSystemTrayIcon>

class Systray : public QObject
{
    Q_OBJECT
    QSystemTrayIcon m_systray;

public:
    explicit Systray(QObject *parent = 0);

signals:
    void systrayClicked();

public slots:
    void onActivated(QSystemTrayIcon::ActivationReason);

};

#endif // SYSTRAY_H
