#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QMap>
#include <QString>

/**
  * NOTE:
  * if there was conctructed the empty exception (Exception()) then errorCode == -1;
  * if there where conctructed an exceptions with one error code but with different errorMessage then the last ErrorMessage use for.
  */
class Exception
{
public:

    enum ExceptionType {
        FileNotFound,
        FileOperationError,
        IndexOutRange,
        BadXMLFile,
        ObjectDoentExist,
        ItemNotFound,
        CouldntOpenFile,
        BadType
    };

    Exception();
    Exception(ExceptionType errorCode);
    Exception(ExceptionType errorCode, const QString& errorMessage);

    int getErrorCode() const;
    const QString getErrorMessage() const;

    QString getOutputMessage() const;

private:

    int errorCode;

    static QMap<int, QString> errorsMap;
};

#endif // EXCEPTION_H
