#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();

    Q_INVOKABLE QJsonObject performAuthenticatedGET(const QString &databasePath,
                                                    const QString &userIdToken,
                                                    const QString &queryParams = "");
    Q_INVOKABLE bool registerNewUser(class User *user, class QLabel *errorLabel = nullptr);
    Q_INVOKABLE class User *logInWithEmailAndPassword(const QString &email,
                                                      const QString &password,
                                                      class QLabel *errorLabel = nullptr);
    Q_INVOKABLE QJsonObject performPOST(const QString &url, const QJsonDocument &payload);
    Q_INVOKABLE QJsonObject performAuthenticatedPUT(const QString &databasePath,
                                                    const QJsonDocument &payload,
                                                    const QString &userIdToken);
    Q_INVOKABLE QJsonObject performAuthenticatedPOST(const QString &databasePath,
                                                     const QJsonDocument &payload,
                                                     const QString &userIdToken);
    Q_INVOKABLE bool sendEmailVerification(const QString &idToken);
    Q_INVOKABLE bool changeAuthDisplayName(const QString &idToken, const QString &newName);
    Q_INVOKABLE bool updateUserData(const QString &userId,
                                    const QJsonDocument &fieldsToUpdate,
                                    const QString &idToken);
    Q_INVOKABLE QJsonObject performAuthenticatedPATCH(const QString &databasePath,
                                                      const QJsonDocument &payload,
                                                      const QString &userIdToken);
    Q_INVOKABLE bool changeAuthUserEmail(const QString &idToken, const QString &newEmail);
    Q_INVOKABLE bool changeAuthUserPassword(const QString &idToken, const QString &newPassword);
    //Q_INVOKABLE bool emailChangedExternallyUpdate(User *user);
    Q_INVOKABLE QJsonObject sendPasswordResetLink(const QString &email);
    Q_INVOKABLE QJsonObject updateAuthAttributes(const QJsonDocument &payload);
    Q_INVOKABLE bool deleteUserAccount(const QString &idToken);

public slots:
    void test() { qDebug() << "test"; }

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
    const QString api_key = "AIzaSyD2hh2Bm6RSDiVKdtDcUsdXHXQXlEoGxY8";
    QJsonObject signUpWithEmailAndPassword(const QString email, const QString password);
    QJsonObject getAuthAccountInfo(const QString &idToken);
};

#endif // DATABASEHANDLER_H
