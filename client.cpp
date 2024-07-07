#include "Client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
}

void Client::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void Client::login(const QString &username, const QString &password)
{
    QJsonObject json;
    json["type"] = "login";
    json["username"] = username;
    json["password"] = password;
    json["status"] = "success";
    socket->write(QJsonDocument(json).toJson());
}

void Client::onConnected()
{
    qDebug() << "Connected to server!";
}

void Client::onReadyRead()
{
    QByteArray data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    QString type = json["type"].toString();
    if (type == "login") {
        QString status = json["status"].toString();
        emit loginResponse(status);
    }
}

void Client::onDisconnected()
{
    qDebug() << "Disconnected from server!";
}
