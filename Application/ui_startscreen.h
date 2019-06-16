/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startScreen
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *gameDefaultBtn;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *nbRowTf;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *nbColTf;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *nbBombTf;
    QComboBox *bombUnit;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *bombDefault;
    QPushButton *gameCustomBtn;
    QWidget *page_2;
    QLCDNumber *lcdNumber;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *containerCase;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *newGameBtn;
    QFrame *line_2;
    QPushButton *statBtn;

    void setupUi(QWidget *startScreen)
    {
        if (startScreen->objectName().isEmpty())
            startScreen->setObjectName(QStringLiteral("startScreen"));
        startScreen->resize(475, 439);
        stackedWidget = new QStackedWidget(startScreen);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 38, 475, 401));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 441, 333));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, -1, 0, -1);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        gameDefaultBtn = new QPushButton(layoutWidget);
        gameDefaultBtn->setObjectName(QStringLiteral("gameDefaultBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameDefaultBtn->sizePolicy().hasHeightForWidth());
        gameDefaultBtn->setSizePolicy(sizePolicy);
        gameDefaultBtn->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(gameDefaultBtn);


        verticalLayout_3->addLayout(verticalLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        nbRowTf = new QLineEdit(layoutWidget);
        nbRowTf->setObjectName(QStringLiteral("nbRowTf"));
        nbRowTf->setMaximumSize(QSize(150, 16777215));
        nbRowTf->setSizeIncrement(QSize(0, 0));
        nbRowTf->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(nbRowTf);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        nbColTf = new QLineEdit(layoutWidget);
        nbColTf->setObjectName(QStringLiteral("nbColTf"));
        nbColTf->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(nbColTf);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        nbBombTf = new QLineEdit(layoutWidget);
        nbBombTf->setObjectName(QStringLiteral("nbBombTf"));
        nbBombTf->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(nbBombTf);

        bombUnit = new QComboBox(layoutWidget);
        bombUnit->setObjectName(QStringLiteral("bombUnit"));

        horizontalLayout_3->addWidget(bombUnit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        bombDefault = new QCheckBox(layoutWidget);
        bombDefault->setObjectName(QStringLiteral("bombDefault"));

        verticalLayout_2->addWidget(bombDefault);

        gameCustomBtn = new QPushButton(layoutWidget);
        gameCustomBtn->setObjectName(QStringLiteral("gameCustomBtn"));
        gameCustomBtn->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(gameCustomBtn);


        verticalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lcdNumber = new QLCDNumber(page_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(330, 20, 121, 21));
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 49, 441, 311));
        containerCase = new QVBoxLayout(verticalLayoutWidget);
        containerCase->setObjectName(QStringLiteral("containerCase"));
        containerCase->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(page_2);
        layoutWidget1 = new QWidget(startScreen);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 441, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        newGameBtn = new QPushButton(layoutWidget1);
        newGameBtn->setObjectName(QStringLiteral("newGameBtn"));

        horizontalLayout_4->addWidget(newGameBtn);

        line_2 = new QFrame(layoutWidget1);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_2);

        statBtn = new QPushButton(layoutWidget1);
        statBtn->setObjectName(QStringLiteral("statBtn"));

        horizontalLayout_4->addWidget(statBtn);


        retranslateUi(startScreen);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(startScreen);
    } // setupUi

    void retranslateUi(QWidget *startScreen)
    {
        startScreen->setWindowTitle(QApplication::translate("startScreen", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("startScreen", "Cr\303\251er une nouvelle partie", Q_NULLPTR));
        label_2->setText(QApplication::translate("startScreen", "Par d\303\251faut, un plateau mesure 9 x 9 et comporte 10 bombes.", Q_NULLPTR));
        gameDefaultBtn->setText(QApplication::translate("startScreen", "Nouvelle partie par d\303\251faut", Q_NULLPTR));
        label_3->setText(QApplication::translate("startScreen", "Vous pouvez cr\303\251er votre propre partie personnalis\303\251e :", Q_NULLPTR));
        label_4->setText(QApplication::translate("startScreen", "Nombre de lignes :", Q_NULLPTR));
        label_5->setText(QApplication::translate("startScreen", "Nombre de colonnes :", Q_NULLPTR));
        label_6->setText(QApplication::translate("startScreen", "Nombre de bombes :", Q_NULLPTR));
        bombUnit->clear();
        bombUnit->insertItems(0, QStringList()
         << QApplication::translate("startScreen", "%", Q_NULLPTR)
         << QApplication::translate("startScreen", "bombes", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("startScreen", "* Si vous choisissez un pourcentage de bombe, x % du plateau", Q_NULLPTR));
        label_8->setText(QApplication::translate("startScreen", "sera rempli de bombes, x \303\251tant la valeur introduite.", Q_NULLPTR));
        bombDefault->setText(QApplication::translate("startScreen", "Jouer avec un nombre par d\303\251faut de bombes.", Q_NULLPTR));
        gameCustomBtn->setText(QApplication::translate("startScreen", "Nouvelle partie personnalis\303\251e", Q_NULLPTR));
        newGameBtn->setText(QApplication::translate("startScreen", "Nouvelle Partie ", Q_NULLPTR));
        statBtn->setText(QApplication::translate("startScreen", "Statistiques", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class startScreen: public Ui_startScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
