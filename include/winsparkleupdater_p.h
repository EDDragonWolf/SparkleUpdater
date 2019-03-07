#ifndef WINSPARKLEUPDATER_P_H
#define WINSPARKLEUPDATER_P_H

#include "sparkleupdater_p.h"

class WinSparkleUpdaterPrivate final: public SparkleUpdaterPrivate
{
public:
    explicit WinSparkleUpdaterPrivate();
    ~WinSparkleUpdaterPrivate();

    void setLanguage(const QString &languageLocale) override;

    void setAppInfo(const QString &companyName, const QString &appName, const QString &appVersion) override;

    void setFeedUrl(const QUrl &feedUrl) override;

    bool autoChecksUpdates() const override;
    void setAutoChecksUpdates(bool autoChecksUpdates) override;

    quint64 checkUpdatesInterval() const override;
    void setCheckUpdatesInterval(const quint64 &checkUpdatesInterval) override;

    void init() override;
    void clean() override;

    void checkForUpdates(bool silent) override;

private:
    static void errorCallback();
    static int canCloseCallback();
    static void willCloseCallback();
    static void didFindUpdateCallback();
    static void didNotFindUpdateCallback();
    static void cancelCallback();

private:
    static WinSparkleUpdaterPrivate *sGlobal;
};

#endif // WINSPARKLEUPDATER_P_H
