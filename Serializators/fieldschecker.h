#ifndef FIELDSCHECKER_H
#define FIELDSCHECKER_H

#include <QString>
#include <QStringList>

class FieldsChecker
{
public:
    FieldsChecker();

    static bool checkCode(const QString &code);
    static bool checkCodes(const QStringList &codes);
    static QStringList parseCodes(const QStringList &codes);
};

#endif // FIELDSCHECKER_H
