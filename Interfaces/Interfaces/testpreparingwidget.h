#ifndef TESTPREPARINGWIDGET_H
#define TESTPREPARINGWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class TestPreparingWidget;
}

class TestPreparingWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit TestPreparingWidget(QWidget *parent = 0);
    ~TestPreparingWidget();
    
private:
    Ui::TestPreparingWidget *ui;
};

#endif // TESTPREPARINGWIDGET_H
