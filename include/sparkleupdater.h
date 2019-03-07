#ifndef SPARKLEUPDATER_H
#define SPARKLEUPDATER_H

#include "sparkleupdater_p.h"

#include <QObject>
#include <QUrl>

#include <functional>

class SparkleUpdater : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(SparkleUpdater)
    Q_PROPERTY(bool autoChecksUpdates READ autoChecksUpdates WRITE setAutoChecksUpdates)
    Q_PROPERTY(quint64 checkUpdatesInterval READ checkUpdatesInterval WRITE setCheckUpdatesInterval)
public:
    static SparkleUpdater* instance();

    //only works for Windows
    void setLanguage(const QString &languageLocale);

    void setAppInfo(const QString &companyName, const QString &appName, const QString &appVersion);

    void setFeedUrl(const QUrl &feedUrl);

    bool autoChecksUpdates() const;
    void setAutoChecksUpdates(bool autoChecksUpdates);

    quint64 checkUpdatesInterval() const;
    void setCheckUpdatesInterval(const quint64 &checkUpdatesInterval);

    void setCanCloseCallback(const CanCloseCallback &canCloseCallback);
    void setWillCloseCallback(const WillCloseCallback &willCloseCallback);

signals:
    void findUpdate(bool);
    void cancelDownload();
    void error(const QString&);

public slots:
    void init();
    void clean();
    void checkForUpdates(bool silent = false);

private:
    explicit SparkleUpdater(QObject *parent = nullptr);
    ~SparkleUpdater();

private:
    static SparkleUpdater *mInstance;

    SparkleUpdaterPrivate *mDPtr;
};

#endif // SPARKLEUPDATER_H
