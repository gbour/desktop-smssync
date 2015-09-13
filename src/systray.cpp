
#include <QDebug>
#include <QSystemTrayIcon>

#include "systray.h"

Systray::Systray(QObject *parent) : QObject(parent),
  m_systray(QIcon(":/resources/smssync-trayicon.png"))
{
    QObject::connect(&m_systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
    m_systray.show();
}

void Systray::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick) {
        emit systrayClicked();
    }
}

