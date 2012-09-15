#ifndef TESTTASK_H
#define TESTTASK_H

#include <QString>
#include <QStringList>

#include "abstracttesttask.h"

class TestTask : public AbstractTestTask
{
public:

    enum AnswerType
    {
        TypeA,
        TypeB,
        TypeC,
        UnknownType
    };

    static QString toStringType(const AnswerType &type);
    static AnswerType fromStringType(const QString &type);

    TestTask(const QString &taskId,
             const AnswerType &answerType,
             const QStringList &innerCodes,
             const QStringList &outerCodes,
             const QString &taskContent,
             const QString &answer,
             const QStringList &images = QStringList(),
             const double &taskCost = 0,
             const QString &answerHtml = QString());

    virtual const QString getTaskId() const;

    const AnswerType getAnswerType() const;

    const QString getTaskContent() const;
    const QStringList getImageLinks() const;
    const QString getRightAnswer() const;

    const double getTaskCost() const;
    const QString getAnswerHtml() const;

    bool checkAnswer(QString answer) const;

private:

    AnswerType answerType;

    QString taskContent;
    QString answer;

    QStringList images;
    double taskCost;
    QString answerHtml;
};

#endif // TESTTASK_H
