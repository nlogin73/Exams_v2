#include "exception.h"

QMap<int, QString> Exception::errorsMap = QMap<int, QString>();
//Exception::errorsMap.insert(-1, "Unknown exception");

Exception::Exception()
{
    errorCode = -1;
}

Exception::Exception(ExceptionType errorCode)
{
    this->errorCode = errorCode;

    if (!errorsMap.contains(errorCode))
    {
        errorsMap.insert(errorCode, "Unnamed exception");
    }
}

Exception::Exception(ExceptionType errorCode, const QString &errorMessage)
{
    this->errorCode = errorCode;

    errorsMap[errorCode] = errorMessage;
}

int Exception::getErrorCode() const
{
    return errorCode;
}

const QString Exception::getErrorMessage() const
{
    return errorsMap[errorCode];
}

QString Exception::getOutputMessage() const
{
    QString result;
    result = "There where caused the error with code: ";
    result += QString::number(errorCode, 10) + " - " + errorsMap[errorCode];
    return result;
}
