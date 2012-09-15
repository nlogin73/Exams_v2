#include "testingwidget.h"
#include "ui_testingwidget.h"

TestingWidget::TestingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestingWidget)
{
    ui->setupUi(this);

    navigationsInit();
    answersAInit();
    answersBInit();
}

TestingWidget::~TestingWidget()
{
    delete ui;
}

void TestingWidget::navigationsInit()
{
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);
    ui->scrollAreaWidgetContents->setLayout(verticalLayout);

    for (int i = 1; i < 21; i++)
    {
        QWidget *navigationWidget = new QWidget;
        navigationWidget->setObjectName("navigationWidget_" + QString::number(i, 10));
        navigationWidget->setFixedHeight(45);
        navigationWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        horizontalLayout->setSpacing(0);
        navigationWidget->setLayout(horizontalLayout);

        QPushButton *navigationButton = new QPushButton;
        navigationButton->setObjectName("navigationButton_" + QString::number(i, 10));
        navigationButton->setFlat(true);
        navigationButton->setText("NB" + QString::number(i, 10));
        navigationButton->setFixedHeight(45);
        navigationButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        navigationWidget->layout()->addWidget(navigationButton);

        QToolButton *taskHelpButton = new QToolButton();
        taskHelpButton->setObjectName("navigationHelpButton_" + QString::number(i, 10));
        taskHelpButton->setFixedSize(36, 36);
        taskHelpButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        navigationWidget->layout()->addWidget(taskHelpButton);

        ui->scrollAreaWidgetContents->layout()->addWidget(navigationWidget);
    }
}

void TestingWidget::answersAInit()
{
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout->setSpacing(3);
    ui->answerPage_A->setLayout(horizontalLayout);

    for (int i = 1; i < 21; i++)
    {
        QGroupBox *groupBox = new QGroupBox();
        groupBox->setTitle("A" + QString::number(i, 10));
        groupBox->setObjectName("aGroupBox_" + QString::number(i, 10));
        groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QVBoxLayout *verticalLayout = new QVBoxLayout;
        groupBox->setLayout(verticalLayout);

        for (int j = 1; j < 5; j++)
        {
            QCheckBox *checkBox = new QCheckBox;
            checkBox->setObjectName("A_" + QString::number(i, 10) + "_" + QString::number(j, 10));
            checkBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

            groupBox->layout()->addWidget(checkBox);
        }

        ui->answerPage_A->layout()->addWidget(groupBox);
    }
}

void TestingWidget::answersBInit()
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(5);

    for (int i = 1; i < 21; i++)
    {
        QWidget *answerWidget = new QWidget;
        answerWidget->setObjectName("bAnswerWidget_" + QString::number(i, 10));
        answerWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(5);

        QLabel *answerLabel = new QLabel;
        answerLabel->setText("B" + QString::number(i, 10));
        answerLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        answerLabel->setFixedWidth(30);

        QLineEdit *answerLineEdit = new QLineEdit;
        answerWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        answerWidget->setObjectName("B_" + QString::number(i, 10));

        horizontalLayout->addWidget(answerLabel);
        horizontalLayout->addWidget(answerLineEdit);

        answerWidget->setLayout(horizontalLayout);
        gridLayout->addWidget(answerWidget, (i - 1) % 5, (i - 1) / 5);
    }

    ui->answerPage_B->setLayout(gridLayout);
}

void TestingWidget::answersCInit()
{
}
