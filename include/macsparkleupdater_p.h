#ifndef MACSPARKLEUPDATER_P_H
#define MACSPARKLEUPDATER_P_H

#include "sparkleupdater_p.h"

Q_FORWARD_DECLARE_OBJC_CLASS(SUUpdater);
Q_FORWARD_DECLARE_OBJC_CLASS(MacSparkleUpdaterDelegate);
Q_FORWARD_DECLARE_OBJC_CLASS(NSString);

class MacSparkleUpdaterPrivate final: public SparkleUpdaterPrivate
{
public:
    explicit MacSparkleUpdaterPrivate();
    ~MacSparkleUpdaterPrivate();

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


    void didNewUpdate(bool found);
    void didCancelDownload();
    void throwError(NSString *error);

private:
    SUUpdater *mUpdater;

    MacSparkleUpdaterDelegate *mDelegate;
};

#endif // MACSPARKLEUPDATER_P_H
