#include "testtask.h"

TestTask::TestTask(const QString &taskId,
                   const AnswerType &answerType,
                   const QStringList &innerCodes,
                   const QStringList &outerCodes,
                   const QString &taskContent,
                   const QString &answer,
                   const QStringList &images,
                   const double &taskCost,
                   const QString &answerHtml)
{
    this->taskId = taskId;
    this->answerType = answerType;
    this->innerCodes = innerCodes;
    this->outerCodes = outerCodes;
    this->taskContent = taskContent;
    this->answer = answer;
    this->images = images;
    this->taskCost = taskCost;
    this->answerHtml = answerHtml;
}

const QString TestTask::getTaskId() const
{
    return taskId;
}

const TestTask::AnswerType TestTask::getAnswerType() const
{
    return answerType;
}

const QString TestTask::getTaskContent() const
{
    return taskContent;
}

const QStringList TestTask::getImageLinks() const
{
    return images;
}

const QString TestTask::getRightAnswer() const
{
    return answer;
}

const double TestTask::getTaskCost() const
{
    return taskCost;
}

const QString TestTask::getAnswerHtml() const
{
    return answerHtml;
}

bool TestTask::checkAnswer(QString answer) const
{
    answer.trimmed();
    answer.toLower();

    return this->answer == answer;
}

QString TestTask::toStringType(const TestTask::AnswerType &type)
{
    if (type == TypeA) { return "A"; }
    if (type == TypeB) { return "B"; }
    if (type == TypeC) { return "C"; }

    return "UnknownType";
}

TestTask::AnswerType TestTask::fromStringType(const QString &type)
{
    if (type.indexOf("A") != -1) { return TypeA; }
    if (type.indexOf("B") != -1) { return TypeB; }
    if (type.indexOf("C") != -1) { return TypeC; }

    return TestTask::UnknownType;
}
