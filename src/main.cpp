
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "systray.h"
#include "network.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("smssync");
    app.setApplicationVersion("0.1.0");
    app.setOrganizationName("har.bour.cc");

    QSettings settings("har.bour.cc", "desktop-smssync");
    //QSettings settings("/tmp/desktop-smssync.conf", QSettings::IniFormat);
    //qDebug() << settings.allKeys();

    // MQTT connection
    //TODO: make it async / in a dedicated thread
    Network net(settings.value("mqtt/server").toString(),
                settings.value("mqtt/port").toInt());

    Systray systray;

    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("netmgr", &net);
    ctx->setContextProperty("systray", &systray);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

