#ifndef REWIEVEDTESTSERIALIZATOR_H
#define REWIEVEDTESTSERIALIZATOR_H

#include "../DataClasses/dataclasses.h"
#include "../DataClasses/exception.h"
#include "abstractserializator.h"
#include "fieldschecker.h"

class ReviewedTestSerializator : public AbstractSerializator
{
public:
    ReviewedTestSerializator();

    ReviewedTest loadTest(const QString &filename);
    void saveTest(const ReviewedTest &test, const QString &filename) throw (Exception);

private:
    ReviewedTestTask getTask(const QDomNode &taskNode);
    QDomElement getTaskXML(const ReviewedTestTask &task);
    QDomDocument getTestXML(const ReviewedTest &test);
};

#endif // REWIEVEDTESTSERIALIZATOR_H
