#ifndef EXAMSTEST_H
#define EXAMSTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "abstracttest.h"
#include "testtask.h"
#include "exception.h"

class ExamsTest : public AbstractTest<TestTask>
{
public:
    ExamsTest();
    ExamsTest(const QString &title,
              const QString &testVersion) :
              AbstractTest<TestTask>(title, testVersion) {}
private:

};

#endif // EXAMSTEST_H
