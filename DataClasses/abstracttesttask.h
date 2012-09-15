#ifndef ABSTRACTTESTTASK_H
#define ABSTRACTTESTTASK_H

#include <QString>
#include <QStringList>

class AbstractTestTask
{
public:
    AbstractTestTask();

    virtual const QString getTaskId() const = 0;
    const QStringList getInnerCodes() const;
    const QStringList getOuterCodes() const;

    bool isInnerCodeRepresent(const QString &innerCode) const;
    bool isOuterCodeRepresent(const QString &outerCode) const;

protected:

    QString taskId;

    QStringList innerCodes;
    QStringList outerCodes;
};

#endif // ABSTRACTTESTTASK_H
