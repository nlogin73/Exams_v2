#include "abstracttesttask.h"

AbstractTestTask::AbstractTestTask()
{
}

const QStringList AbstractTestTask::getInnerCodes() const
{
    return innerCodes;
}

const QStringList AbstractTestTask::getOuterCodes() const
{
    return outerCodes;
}

bool AbstractTestTask::isInnerCodeRepresent(const QString &innerCode) const
{
    for (int i = 0; i < innerCodes.length(); i++)
    {
        if (innerCode == innerCodes.at(i))
        {
            return true;
        }
    }

    return false;
}

bool AbstractTestTask::isOuterCodeRepresent(const QString &outerCode) const
{
    for (int i = 0; i < outerCodes.length(); i++)
    {
        if (outerCode == outerCodes.at(i))
        {
            return true;
        }
    }

    return false;
}
