#include "loginmanager.h"

LoginManager::LoginManager(QObject *parent) : QObject(parent) {
}

bool LoginManager::login(const QString &username, const QString &password) {
    QString filePath = "D:/users.json";
    QJsonObject users = readJsonFile(filePath);

    if (users.contains(username) && users[username].toString() == password) {
        qDebug() << "Login successful!";
        return true;
    } else {
        qDebug() << "Login failed!";
        return false;
    }
}

QJsonObject LoginManager::readJsonFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file:" << filePath;
        return QJsonObject();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(data));
    return doc.object();
}
