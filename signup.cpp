#include "SignUp.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QDir>

SignUp::SignUp(const QString &name, const QString &username, const QString &phone, const QString &address, const QString &password)
    : name(name), username(username), phone(phone), address(address), password(password)
{
    copyFileFromResources();
}

QString SignUp::getWritableFilePath()
{
    return "D:/users.json";
}

void SignUp::copyFileFromResources()
{
    QString resourcePath = ":/users.json";
    QString writablePath = getWritableFilePath();

    if (QFile::exists(writablePath)) {
        return; // اگر فایل قبلاً کپی شده، نیازی به کپی مجدد نیست
    }

    QFile resourceFile(resourcePath);
    if (!resourceFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open resource file for reading";
        return;
    }

    QFile writableFile(writablePath);
    if (!writableFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open writable file for writing";
        return;
    }

    writableFile.write(resourceFile.readAll());
    resourceFile.close();
    writableFile.close();
}

bool SignUp::saveUser()
{
    QString filePath = getWritableFilePath();
    QFile file(filePath);

    QJsonObject jsonObject;

    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray jsonData = file.readAll();
            file.close();

            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
            jsonObject = jsonDoc.object();
        }
    }

    QJsonObject userObject;
    userObject["name"] = name;
    userObject["phone"] = phone;
    userObject["address"] = address;
    userObject["password"] = password;

    jsonObject[username] = userObject;
    QJsonDocument jsonDocument(jsonObject);

    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Data registration successful";
        return true;
    }
    else
    {
        qDebug() << "Failed to open file for writing";
        return false;
    }
}

bool SignUp::validateUser(const QString &username, const QString &password)
{
    QString filePath = "D:/users.json";
    QFile file(filePath);

    if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading";
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();

    if (jsonObject.contains(username) && jsonObject[username].toObject()["password"].toString() == password) {
        return true;
    }

    return false;
}
