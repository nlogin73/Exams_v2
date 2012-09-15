#include "reviewedtesttask.h"

ReviewedTestTask::ReviewedTestTask(const QString &taskId,
                                   const QStringList &innerCodes,
                                   const QStringList &outerCodes,
                                   const QString &htmlSource,
                                   const QStringList &xmlTestTasks)
{
    this->taskId = taskId;
    this->innerCodes = innerCodes;
    this->outerCodes = outerCodes;
    this->htmlSource = htmlSource;
    this->xmlTestTasks = xmlTestTasks;
}

const QString ReviewedTestTask::getTaskId() const
{
    return taskId;
}

const QString ReviewedTestTask::getHtmlSource() const
{
    return htmlSource;
}

const QStringList ReviewedTestTask::getXmlTestTasks() const
{
    return xmlTestTasks;
}

