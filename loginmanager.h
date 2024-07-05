#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

class LoginManager : public QObject {
    Q_OBJECT

public:
    explicit LoginManager(QObject *parent = nullptr);
    bool login(const QString &username, const QString &password);

private:
    QJsonObject readJsonFile(const QString &filePath);
};

#endif // LOGINMANAGER_H
