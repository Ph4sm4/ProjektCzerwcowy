#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("projekt_testowy", "Main");

    DatabaseHandler dbHandler;
    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("dbHandler", &dbHandler);

    return app.exec();
}
