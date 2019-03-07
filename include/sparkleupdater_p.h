#ifndef SPARKLEUPDATER_P_H
#define SPARKLEUPDATER_P_H

#include <QUrl>

#include <functional>

typedef std::function<bool ()> CanCloseCallback;
typedef std::function<void ()> WillCloseCallback;

class SparkleUpdater;
class SparkleUpdaterPrivate
{
public:
    virtual ~SparkleUpdaterPrivate() = default;

    virtual void setLanguage(const QString &languageLocale) = 0;

    virtual void setAppInfo(const QString &companyName, const QString &appName, const QString &appVersion) = 0;

    virtual void setFeedUrl(const QUrl &feedUrl) = 0;

    virtual bool autoChecksUpdates() const = 0;
    virtual void setAutoChecksUpdates(bool autoChecksUpdates) = 0;

    virtual quint64 checkUpdatesInterval() const = 0;
    virtual void setCheckUpdatesInterval(const quint64 &checkUpdatesInterval) = 0;

    virtual void init() = 0;
    virtual void clean() = 0;

    virtual void checkForUpdates(bool silent) = 0;

    SparkleUpdater *mQPtr;

    CanCloseCallback mCanCloseCallback;
    WillCloseCallback mWillCloseCallback;
};

#endif // SPARKLEUPDATER_P_H
