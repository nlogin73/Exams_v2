#ifndef REVIEWEDTEST_H
#define REVIEWEDTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "abstracttest.h"
#include "reviewedtesttask.h"
#include "exception.h"

class ReviewedTest : public AbstractTest<ReviewedTestTask>
{
public:
    ReviewedTest();
    ReviewedTest(const QString &title,
                 const QString &testVersion) :
                 AbstractTest<ReviewedTestTask>(title, testVersion) {}
private:

};

#endif // REVIEWEDTEST_H
