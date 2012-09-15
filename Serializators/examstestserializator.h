#ifndef ExamsTestSerializator_H
#define ExamsTestSerializator_H

#include "../DataClasses/dataclasses.h"
#include "../DataClasses/exception.h"
#include "abstractserializator.h"
#include "fieldschecker.h"

class ExamsTestSerializator : public AbstractSerializator
{
public:
    ExamsTestSerializator();
    ExamsTest loadTest(const QString &filename);
    void saveTest(const ExamsTest &test, const QString &filename) throw (Exception);

private:
    TestTask getTask(const QDomNode &taskNode);
    QDomElement getTaskXML(const TestTask &task);
    QDomDocument getTestXML(const ExamsTest &test);
};

#endif // ExamsTestSerializator_H
