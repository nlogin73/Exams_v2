#ifndef EXTENDSTHEORYLEARNINGWIDGET_H
#define EXTENDSTHEORYLEARNINGWIDGET_H

#include <QWidget>

namespace Ui {
    class ExtendsTheoryLearningWidget;
}

class ExtendsTheoryLearningWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExtendsTheoryLearningWidget(QWidget *parent = 0);
    ~ExtendsTheoryLearningWidget();

private:
    Ui::ExtendsTheoryLearningWidget *ui;
};

#endif // EXTENDSTHEORYLEARNINGWIDGET_H
