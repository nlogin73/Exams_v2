#ifndef ABSTRACTTEST_H
#define ABSTRACTTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "abstracttesttask.h"
#include "testtask.h"
#include "reviewedtesttask.h"
#include "exception.h"

template <typename TaskType>
class AbstractTest
{
public:
    AbstractTest();
    AbstractTest(const QString &title,
                 const QString &testVersion) :
                 title(title), testVersion(testVersion) {}

    void clear();
    void addTask(const TaskType &task);

    const TaskType getTask(const QString &taskId) const throw (Exception);
    const TaskType getTask(const int &taskNumber) const throw (Exception);

    const int getTasksCount() const;

    const QString getTestTitle() const;
    const QString getTestVersion() const;

protected:

    QString title;
    QString testVersion;

    QList<TaskType> tasks;
};

template <typename TaskType>
AbstractTest<TaskType>::AbstractTest()
{
}

template <typename TaskType>
void AbstractTest<TaskType>::clear()
{
    tasks.clear();
}

template <typename TaskType>
void AbstractTest<TaskType>::addTask(const TaskType &task)
{
    tasks.append(task);
}

template <typename TaskType>
const int AbstractTest<TaskType>::getTasksCount() const
{
    return tasks.length();
}

template <typename TaskType>
const TaskType AbstractTest<TaskType>::getTask(const QString &taskId) const throw (Exception)
{
    if (tasks.size() > 0)
    {
        if (dynamic_cast<AbstractTestTask *>(&(tasks.at(0))) == NULL)
        {
            throw Exception(Exception::BadType, "Bad task Type");
        }
    }

    for (int i = 0; i < tasks.length(); i++)
    {
        if (tasks.at(i).getTaskId() == taskId)
        {
            return tasks.at(i);
        }
    }

    throw Exception(Exception::ItemNotFound, "The task with id " + taskId + " is not found");
}

template <typename TaskType>
const TaskType AbstractTest<TaskType>::getTask(const int &taskNumber) const throw (Exception)
{
    if (taskNumber >= tasks.length() || (taskNumber < 0))
    {
        throw Exception(Exception::ItemNotFound, "The task " + QString::number(taskNumber, 10) + " is not found");
    }

    return tasks.at(taskNumber);
}

template <typename TaskType>
const QString AbstractTest<TaskType>::getTestTitle() const
{
    return title;
}

template <typename TaskType>
const QString AbstractTest<TaskType>::getTestVersion() const
{
    return testVersion;
}


#endif // ABSTRACTTEST_H
