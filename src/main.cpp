
#include <QDebug>
#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "systray.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Systray systray;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("systray", &systray);

    return app.exec();
}
