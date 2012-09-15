#include "abstracttest.h"
/*
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
*/
