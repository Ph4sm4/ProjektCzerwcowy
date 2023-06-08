#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();

    QJsonObject performAuthenticatedGET(const QString &databasePath,
                                        const QString &userIdToken,
                                        const QString &queryParams = "");
    bool registerNewUser(class User *user, class QLabel *errorLabel = nullptr);
    class User *logInWithEmailAndPassword(const QString &email,
                                          const QString &password,
                                          class QLabel *errorLabel = nullptr);
    QJsonObject performPOST(const QString &url, const QJsonDocument &payload);
    QJsonObject performAuthenticatedPUT(const QString &databasePath,
                                        const QJsonDocument &payload,
                                        const QString &userIdToken);
    QJsonObject performAuthenticatedPOST(const QString &databasePath,
                                         const QJsonDocument &payload,
                                         const QString &userIdToken);
    bool sendEmailVerification(const QString &idToken);
    bool changeAuthDisplayName(const QString &idToken, const QString &newName);
    bool updateUserData(const QString &userId,
                        const QJsonDocument &fieldsToUpdate,
                        const QString &idToken);
    QJsonObject performAuthenticatedPATCH(const QString &databasePath,
                                          const QJsonDocument &payload,
                                          const QString &userIdToken);
    bool changeAuthUserEmail(const QString &idToken, const QString &newEmail);
    bool changeAuthUserPassword(const QString &idToken, const QString &newPassword);
    bool emailChangedExternallyUpdate(User *user);
    QJsonObject sendPasswordResetLink(const QString &email);
    QJsonObject updateAuthAttributes(const QJsonDocument &payload);
    bool deleteUserAccount(const QString &idToken);

public slots:
    //void networkReplyReadyRead();

signals:

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
    const QString api_key = "AIzaSyD2hh2Bm6RSDiVKdtDcUsdXHXQXlEoGxY8";
    QJsonObject signUpWithEmailAndPassword(const QString email, const QString password);
    QJsonObject getAuthAccountInfo(const QString &idToken);
};

#endif // DATABASEHANDLER_H
