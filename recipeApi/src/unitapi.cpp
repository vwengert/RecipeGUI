#include "unitapi.h"
#include "qglobal.h"
#include "qnetworkrequest.h"
#include <QEventLoop>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

UnitApi::UnitApi( QString baseUrl, QObject* parent )
    : QObject{parent},
      m_baseUrl{ baseUrl }
{
}

const QByteArray* UnitApi::getUnitById( int id )
{
    const QByteArray* response = getRequest( getUnitRequest( QUrl( m_baseUrl + "/unitById/" + QString::number( id ) ) ) );

    qDebug() << *response;
    return response;
}

const QByteArray* UnitApi::getUnits()
{
    const QByteArray* response = getRequest( getUnitRequest( QUrl( m_baseUrl + "/unit" ) ) );

    qDebug() << *response;
    return response;

}

void UnitApi::onError()
{

}

QNetworkRequest UnitApi::getUnitRequest( QUrl unitUrl )
{
    QNetworkRequest unitRequest( unitUrl );
    return unitRequest;
}

const QByteArray* UnitApi::getRequest( const QNetworkRequest& request )
{
    QNetworkAccessManager networkManager;
    QEventLoop loop;
    connect( &networkManager, &QNetworkAccessManager::finished,
             &loop, &QEventLoop::quit );
    QNetworkReply* reply = networkManager.get( request );
    connect( reply, &QNetworkReply::errorOccurred, this, &UnitApi::onError );
    loop.exec();

    return new QByteArray( reply->readAll() );
}
