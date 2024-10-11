/********************************************************************************
** Form generated from reading UI file 'main_window_t.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_T_H
#define UI_MAIN_WINDOW_T_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window_t
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *begin_btn;
    QPushButton *record_btn;
    QPushButton *tutor_btn;

    void setupUi(QWidget *main_window_t)
    {
        if (main_window_t->objectName().isEmpty())
            main_window_t->setObjectName("main_window_t");
        main_window_t->resize(240, 280);
        QFont font;
        font.setPointSize(8);
        main_window_t->setFont(font);
        verticalLayoutWidget = new QWidget(main_window_t);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 30, 160, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        begin_btn = new QPushButton(verticalLayoutWidget);
        begin_btn->setObjectName("begin_btn");
        begin_btn->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221")});
        font1.setPointSize(16);
        begin_btn->setFont(font1);

        verticalLayout->addWidget(begin_btn);

        record_btn = new QPushButton(verticalLayoutWidget);
        record_btn->setObjectName("record_btn");
        record_btn->setMinimumSize(QSize(0, 40));
        record_btn->setFont(font1);

        verticalLayout->addWidget(record_btn);

        tutor_btn = new QPushButton(verticalLayoutWidget);
        tutor_btn->setObjectName("tutor_btn");
        tutor_btn->setMinimumSize(QSize(0, 40));
        tutor_btn->setFont(font1);

        verticalLayout->addWidget(tutor_btn);


        retranslateUi(main_window_t);

        QMetaObject::connectSlotsByName(main_window_t);
    } // setupUi

    void retranslateUi(QWidget *main_window_t)
    {
        main_window_t->setWindowTitle(QCoreApplication::translate("main_window_t", "main_window_t", nullptr));
        begin_btn->setText(QCoreApplication::translate("main_window_t", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        record_btn->setText(QCoreApplication::translate("main_window_t", "\345\216\206\345\217\262\345\210\206\346\225\260", nullptr));
        tutor_btn->setText(QCoreApplication::translate("main_window_t", "\346\270\270\346\210\217\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window_t: public Ui_main_window_t {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_T_H
