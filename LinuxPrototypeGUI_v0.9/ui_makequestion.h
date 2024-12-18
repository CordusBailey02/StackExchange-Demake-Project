/********************************************************************************
** Form generated from reading UI file 'makequestion.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEQUESTION_H
#define UI_MAKEQUESTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_makeQuestion
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ask;
    QPushButton *pushButton_uploadQuestionImage;
    QLabel *label_questionFileSelected;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_postQuestion;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *makeQuestion)
    {
        if (makeQuestion->objectName().isEmpty())
            makeQuestion->setObjectName("makeQuestion");
        makeQuestion->resize(440, 300);
        verticalLayout_2 = new QVBoxLayout(makeQuestion);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_ask = new QLabel(makeQuestion);
        label_ask->setObjectName("label_ask");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_ask->sizePolicy().hasHeightForWidth());
        label_ask->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        label_ask->setFont(font);

        horizontalLayout_4->addWidget(label_ask);

        pushButton_uploadQuestionImage = new QPushButton(makeQuestion);
        pushButton_uploadQuestionImage->setObjectName("pushButton_uploadQuestionImage");
        sizePolicy.setHeightForWidth(pushButton_uploadQuestionImage->sizePolicy().hasHeightForWidth());
        pushButton_uploadQuestionImage->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(146, 194, 242, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton_uploadQuestionImage->setPalette(palette);
        pushButton_uploadQuestionImage->setFont(font);

        horizontalLayout_4->addWidget(pushButton_uploadQuestionImage);

        label_questionFileSelected = new QLabel(makeQuestion);
        label_questionFileSelected->setObjectName("label_questionFileSelected");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_questionFileSelected->sizePolicy().hasHeightForWidth());
        label_questionFileSelected->setSizePolicy(sizePolicy1);
        label_questionFileSelected->setFont(font);

        horizontalLayout_4->addWidget(label_questionFileSelected);


        verticalLayout->addLayout(horizontalLayout_4);

        plainTextEdit = new QPlainTextEdit(makeQuestion);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_postQuestion = new QPushButton(makeQuestion);
        pushButton_postQuestion->setObjectName("pushButton_postQuestion");
        sizePolicy1.setHeightForWidth(pushButton_postQuestion->sizePolicy().hasHeightForWidth());
        pushButton_postQuestion->setSizePolicy(sizePolicy1);
        QPalette palette1;
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        pushButton_postQuestion->setPalette(palette1);
        pushButton_postQuestion->setFont(font);

        horizontalLayout->addWidget(pushButton_postQuestion);

        pushButton_cancel = new QPushButton(makeQuestion);
        pushButton_cancel->setObjectName("pushButton_cancel");
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);
        QPalette palette2;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        pushButton_cancel->setPalette(palette2);
        pushButton_cancel->setFont(font);

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(makeQuestion);

        QMetaObject::connectSlotsByName(makeQuestion);
    } // setupUi

    void retranslateUi(QDialog *makeQuestion)
    {
        makeQuestion->setWindowTitle(QCoreApplication::translate("makeQuestion", "Ask a Question Window", nullptr));
        label_ask->setText(QCoreApplication::translate("makeQuestion", "Ask a Question", nullptr));
        pushButton_uploadQuestionImage->setText(QCoreApplication::translate("makeQuestion", "Upload Image", nullptr));
        label_questionFileSelected->setText(QCoreApplication::translate("makeQuestion", "No file selected", nullptr));
        plainTextEdit->setPlainText(QString());
        pushButton_postQuestion->setText(QCoreApplication::translate("makeQuestion", "Ok", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("makeQuestion", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class makeQuestion: public Ui_makeQuestion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEQUESTION_H
