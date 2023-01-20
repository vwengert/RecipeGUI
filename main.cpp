#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "unitapi.h"

int main( int argc, char* argv[] )
{
    qputenv( "QT_IM_MODULE", QByteArray( "qtvirtualkeyboard" ) );

    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;
    const QUrl url( "qrc:/RecipeGUI/main.qml" );
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
    [url]( QObject * obj, const QUrl & objUrl ) {
        if( !obj && url == objUrl ) {
            QCoreApplication::exit( -1 );
        }
    },
    Qt::QueuedConnection );
    engine.load( url );

    UnitApi unit( qgetenv( "API_BASE_URL" ) );
    unit.getUnits();
    unit.getUnitById( 1 );

    return app.exec();
}
