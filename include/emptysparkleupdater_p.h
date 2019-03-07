#ifndef EMPTYSPARKLEUPDATER_P_H
#define EMPTYSPARKLEUPDATER_P_H

#include "sparkleupdater_p.h"

class EmptySparkleUpdaterPrivate final: public SparkleUpdaterPrivate
{
public:
    void setLanguage(const QString &) override {}

    void setAppInfo(const QString &, const QString &, const QString &) override {}

    void setFeedUrl(const QUrl &) override
    {
        qWarning("There are no Sparkle Updater for this platform.");
    }

    bool autoChecksUpdates() const override {return false;}
    void setAutoChecksUpdates(bool) override {}

    quint64 checkUpdatesInterval() const override {return 0;}
    void setCheckUpdatesInterval(const quint64 &) override {}

    void init() override {}
    void clean() override {}

    void checkForUpdates(bool) override{}
};

#endif // EMPTYSPARKLEUPDATER_P_H
