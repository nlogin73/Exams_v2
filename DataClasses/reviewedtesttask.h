#ifndef REVIEWEDTESTTASK_H
#define REVIEWEDTESTTASK_H

#include <QString>
#include <QStringList>

#include "abstracttesttask.h"

class ReviewedTestTask : public AbstractTestTask
{
public:
    ReviewedTestTask(const QString &taskId,
                     const QStringList &innerCodes,
                     const QStringList &outerCodes,
                     const QString &htmlSource,
                     const QStringList &xmlTestTasks);

    virtual const QString getTaskId() const;

    const QString getHtmlSource() const;

    const QStringList getXmlTestTasks() const;

private:

    QString htmlSource;

    QStringList xmlTestTasks;

};

#endif // REVIEWEDTESTTASK_H
