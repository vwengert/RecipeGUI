#ifndef UNITAPI_H
#define UNITAPI_H

#include <QObject>

class QNetworkRequest;

class UnitApi : public QObject
{
        Q_OBJECT
    public:
        explicit UnitApi( QString baseUrl, QObject* parent = nullptr );
        const QByteArray* getUnitById( int id );
        const QByteArray* getUnits( );

    public slots:
        void onError();

    private:
        QNetworkRequest getUnitRequest( QUrl unitUrl );
        const QByteArray* getRequest( const QNetworkRequest& request );

    private:
        QString m_baseUrl;

};

#endif // UNITAPI_H
