#include "Server.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent)
{
}

void Server::startServer()
{
    int port = 12345; // پورت سرور
    if (listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on IP:" << QNetworkInterface::allAddresses().at(1).toString() << "Port:" << port;
    } else {
        qDebug() << "Server could not start!";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    if (socket->setSocketDescriptor(socketDescriptor)) {
        clients.insert(socket, "");
        connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
        qDebug() << "New client connected: " << socketDescriptor;
    } else {
        delete socket;
    }
}

void Server::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        QByteArray data = socket->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject json = doc.object();

        QString type = json["type"].toString();
        if (type == "login") {
            QString username = json["username"].toString();
            QString password = json["password"].toString();

            // بررسی لاگین
            if (username == "test" && password == "test") { // فرض کنید کاربر و رمز عبور معتبر هستند
                clients[socket] = username;
                QJsonObject response;
                response["type"] = "login";
                response["status"] = "success";
                socket->write(QJsonDocument(response).toJson());
            } else {
                QJsonObject response;
                response["type"] = "login";
                response["status"] = "failure";
                socket->write(QJsonDocument(response).toJson());
            }
        }
    }
}

void Server::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        clients.remove(socket);
        socket->deleteLater();
    }
}
