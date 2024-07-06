#include <QString>

class SignUp
{
public:
    SignUp(const QString &name, const QString &username, const QString &phone, const QString &address, const QString &password);

    bool saveUser();
    static bool validateUser(const QString &username, const QString &password);

private:
    QString name;
    QString username;
    QString phone;
    QString address;
    QString password;

    QString getWritableFilePath();
    void copyFileFromResources();
};
