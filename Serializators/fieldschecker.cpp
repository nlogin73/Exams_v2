#include "fieldschecker.h"

FieldsChecker::FieldsChecker()
{
}

bool FieldsChecker::checkCode(const QString &code)
{
    if (code.contains(QRegExp("[^0-9.]")))
    {
        return false;
    }

    QStringList list = code.split(".");

    for (int i = 0; i < list.length(); i++)
    {
        if (list.at(i).contains(QRegExp("[^0-9]")) || (list.at(i) == ""))
        {
            return false;
        }
    }

    return true;
}

bool FieldsChecker::checkCodes(const QStringList &codes)
{
    bool result = true;

    for (int i = 0; i < codes.length(); i++)
    {
        result &= checkCode(codes.at(i));
    }

    return result;
}

QStringList FieldsChecker::parseCodes(const QStringList &codes)
{
    QStringList result;

    for (int i = 0; i < codes.length(); i++)
    {
        if (checkCode(codes.at(i)))
        {
            result.append(codes.at(i));
        }
    }

    return result;
}
