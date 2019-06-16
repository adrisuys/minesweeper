/********************************************************************************
** Form generated from reading UI file 'guiscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUISCREEN_H
#define UI_GUISCREEN_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIScreen
{
public:
    QStackedWidget *stackedWidget;
    QWidget *userNameScreen;
    QLabel *MineSweeperTitle;
    QPushButton *playButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *usernameTitle;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *usernameInput;
    QWidget *initScreen;
    QLabel *gameTitle;
    QLabel *defaultGameTitle;
    QPushButton *defaultGameButton;
    QFrame *line;
    QLabel *personnalizedGameTitle;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *defaultNbBomb;
    QPushButton *personnalizedGameButton;
    QFrame *line_2;
    QPushButton *hallOfFameButton;
    QPushButton *quitButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *lineTitle;
    QSpacerItem *horizontalSpacer;
    QLineEdit *nbLineInput;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nbColumnInput;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *bombInput;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *bombsUnit;
    QWidget *playScreen;
    QLCDNumber *timer;
    QWidget *frame;
    QPushButton *exitButton;
    QPushButton *giveUpButton;
    QPushButton *bonusButton;
    QLCDNumber *bombCounter;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *help;
    QWidget *statScreen;
    QTableWidget *scoresBoard;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *boardTypeBox;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *printScoreButton;
    QPushButton *toInitScreenButton;

    void setupUi(QWidget *GUIScreen)
    {
        if (GUIScreen->objectName().isEmpty())
            GUIScreen->setObjectName(QStringLiteral("GUIScreen"));
        GUIScreen->resize(860, 562);
        stackedWidget = new QStackedWidget(GUIScreen);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 871, 561));
        userNameScreen = new QWidget();
        userNameScreen->setObjectName(QStringLiteral("userNameScreen"));
        MineSweeperTitle = new QLabel(userNameScreen);
        MineSweeperTitle->setObjectName(QStringLiteral("MineSweeperTitle"));
        MineSweeperTitle->setGeometry(QRect(320, 30, 300, 150));
        QFont font;
        font.setPointSize(56);
        MineSweeperTitle->setFont(font);
        playButton = new QPushButton(userNameScreen);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(400, 300, 141, 31));
        layoutWidget = new QWidget(userNameScreen);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 230, 322, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        usernameTitle = new QLabel(layoutWidget);
        usernameTitle->setObjectName(QStringLiteral("usernameTitle"));
        QFont font1;
        font1.setPointSize(14);
        usernameTitle->setFont(font1);

        horizontalLayout_5->addWidget(usernameTitle);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        usernameInput = new QLineEdit(layoutWidget);
        usernameInput->setObjectName(QStringLiteral("usernameInput"));

        horizontalLayout_5->addWidget(usernameInput);

        stackedWidget->addWidget(userNameScreen);
        initScreen = new QWidget();
        initScreen->setObjectName(QStringLiteral("initScreen"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(initScreen->sizePolicy().hasHeightForWidth());
        initScreen->setSizePolicy(sizePolicy);
        gameTitle = new QLabel(initScreen);
        gameTitle->setObjectName(QStringLiteral("gameTitle"));
        gameTitle->setGeometry(QRect(380, 30, 171, 20));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        gameTitle->setFont(font2);
        defaultGameTitle = new QLabel(initScreen);
        defaultGameTitle->setObjectName(QStringLiteral("defaultGameTitle"));
        defaultGameTitle->setGeometry(QRect(250, 60, 381, 16));
        defaultGameButton = new QPushButton(initScreen);
        defaultGameButton->setObjectName(QStringLiteral("defaultGameButton"));
        defaultGameButton->setGeometry(QRect(240, 80, 191, 32));
        line = new QFrame(initScreen);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(250, 120, 431, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        personnalizedGameTitle = new QLabel(initScreen);
        personnalizedGameTitle->setObjectName(QStringLiteral("personnalizedGameTitle"));
        personnalizedGameTitle->setGeometry(QRect(250, 140, 341, 16));
        label_3 = new QLabel(initScreen);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 270, 391, 16));
        label_4 = new QLabel(initScreen);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 290, 381, 16));
        defaultNbBomb = new QCheckBox(initScreen);
        defaultNbBomb->setObjectName(QStringLiteral("defaultNbBomb"));
        defaultNbBomb->setGeometry(QRect(260, 310, 301, 20));
        personnalizedGameButton = new QPushButton(initScreen);
        personnalizedGameButton->setObjectName(QStringLiteral("personnalizedGameButton"));
        personnalizedGameButton->setGeometry(QRect(250, 340, 211, 32));
        line_2 = new QFrame(initScreen);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(260, 380, 411, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        hallOfFameButton = new QPushButton(initScreen);
        hallOfFameButton->setObjectName(QStringLiteral("hallOfFameButton"));
        hallOfFameButton->setGeometry(QRect(310, 400, 113, 32));
        quitButton = new QPushButton(initScreen);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(490, 400, 113, 32));
        layoutWidget1 = new QWidget(initScreen);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 170, 391, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineTitle = new QLabel(layoutWidget1);
        lineTitle->setObjectName(QStringLiteral("lineTitle"));

        horizontalLayout->addWidget(lineTitle);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nbLineInput = new QLineEdit(layoutWidget1);
        nbLineInput->setObjectName(QStringLiteral("nbLineInput"));

        horizontalLayout->addWidget(nbLineInput);

        layoutWidget2 = new QWidget(initScreen);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 200, 391, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        nbColumnInput = new QLineEdit(layoutWidget2);
        nbColumnInput->setObjectName(QStringLiteral("nbColumnInput"));

        horizontalLayout_2->addWidget(nbColumnInput);

        layoutWidget3 = new QWidget(initScreen);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(260, 230, 391, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        bombInput = new QLineEdit(layoutWidget3);
        bombInput->setObjectName(QStringLiteral("bombInput"));

        horizontalLayout_3->addWidget(bombInput);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        bombsUnit = new QComboBox(layoutWidget3);
        bombsUnit->setObjectName(QStringLiteral("bombsUnit"));

        horizontalLayout_3->addWidget(bombsUnit);

        stackedWidget->addWidget(initScreen);
        playScreen = new QWidget();
        playScreen->setObjectName(QStringLiteral("playScreen"));
        timer = new QLCDNumber(playScreen);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setGeometry(QRect(650, 20, 111, 23));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        timer->setFont(font3);
        timer->setFrameShape(QFrame::Panel);
        timer->setFrameShadow(QFrame::Sunken);
        timer->setLineWidth(2);
        timer->setMidLineWidth(0);
        timer->setDigitCount(3);
        timer->setSegmentStyle(QLCDNumber::Flat);
        frame = new QWidget(playScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 60, 831, 421));
        exitButton = new QPushButton(playScreen);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(520, 500, 113, 32));
        giveUpButton = new QPushButton(playScreen);
        giveUpButton->setObjectName(QStringLiteral("giveUpButton"));
        giveUpButton->setGeometry(QRect(340, 500, 151, 32));
        bonusButton = new QPushButton(playScreen);
        bonusButton->setObjectName(QStringLiteral("bonusButton"));
        bonusButton->setGeometry(QRect(100, 500, 211, 32));
        bombCounter = new QLCDNumber(playScreen);
        bombCounter->setObjectName(QStringLiteral("bombCounter"));
        bombCounter->setGeometry(QRect(280, 20, 111, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        bombCounter->setPalette(palette);
        bombCounter->setFrameShape(QFrame::Panel);
        bombCounter->setFrameShadow(QFrame::Sunken);
        bombCounter->setLineWidth(2);
        bombCounter->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(playScreen);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 20, 201, 20));
        label_7 = new QLabel(playScreen);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(560, 20, 60, 16));
        help = new QLabel(playScreen);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(50, 500, 30, 30));
        stackedWidget->addWidget(playScreen);
        statScreen = new QWidget();
        statScreen->setObjectName(QStringLiteral("statScreen"));
        scoresBoard = new QTableWidget(statScreen);
        if (scoresBoard->columnCount() < 3)
            scoresBoard->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        scoresBoard->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        scoresBoard->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        scoresBoard->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        scoresBoard->setObjectName(QStringLiteral("scoresBoard"));
        scoresBoard->setGeometry(QRect(200, 110, 441, 341));
        scoresBoard->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        scoresBoard->horizontalHeader()->setVisible(false);
        scoresBoard->horizontalHeader()->setCascadingSectionResizes(false);
        scoresBoard->horizontalHeader()->setDefaultSectionSize(150);
        scoresBoard->verticalHeader()->setVisible(false);
        layoutWidget4 = new QWidget(statScreen);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(200, 70, 441, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        boardTypeBox = new QComboBox(layoutWidget4);
        boardTypeBox->setObjectName(QStringLiteral("boardTypeBox"));

        horizontalLayout_4->addWidget(boardTypeBox);

        horizontalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        printScoreButton = new QPushButton(layoutWidget4);
        printScoreButton->setObjectName(QStringLiteral("printScoreButton"));

        horizontalLayout_4->addWidget(printScoreButton);

        toInitScreenButton = new QPushButton(statScreen);
        toInitScreenButton->setObjectName(QStringLiteral("toInitScreenButton"));
        toInitScreenButton->setGeometry(QRect(330, 450, 201, 32));
        stackedWidget->addWidget(statScreen);

        retranslateUi(GUIScreen);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(GUIScreen);
    } // setupUi

    void retranslateUi(QWidget *GUIScreen)
    {
        GUIScreen->setWindowTitle(QApplication::translate("GUIScreen", "Form", Q_NULLPTR));
        MineSweeperTitle->setText(QString());
        playButton->setText(QApplication::translate("GUIScreen", "Jouer", Q_NULLPTR));
        usernameTitle->setText(QApplication::translate("GUIScreen", "Entrer votre pseudo :", Q_NULLPTR));
        gameTitle->setText(QApplication::translate("GUIScreen", "Cr\303\251er une nouvelle partie", Q_NULLPTR));
        defaultGameTitle->setText(QApplication::translate("GUIScreen", "Par d\303\251faut, un plateau mesure 9 x 9 et comporte 10 bombes.", Q_NULLPTR));
        defaultGameButton->setText(QApplication::translate("GUIScreen", "Nouvelle partie par d\303\251faut", Q_NULLPTR));
        personnalizedGameTitle->setText(QApplication::translate("GUIScreen", "Vous pouvez cr\303\251er votre propre partie personnalis\303\251e :", Q_NULLPTR));
        label_3->setText(QApplication::translate("GUIScreen", "* Si vous choisissez un pourcentage de bombe, x % du plateau", Q_NULLPTR));
        label_4->setText(QApplication::translate("GUIScreen", "sera rempli de bombes, x \303\251tant la valeur introduite.", Q_NULLPTR));
        defaultNbBomb->setText(QApplication::translate("GUIScreen", "Jouer avec un nombre de bombes par d\303\251faut.", Q_NULLPTR));
        personnalizedGameButton->setText(QApplication::translate("GUIScreen", "Nouvelle partie personnalis\303\251e", Q_NULLPTR));
        hallOfFameButton->setText(QApplication::translate("GUIScreen", "Voir le HoF", Q_NULLPTR));
        quitButton->setText(QApplication::translate("GUIScreen", "Quitter le jeu", Q_NULLPTR));
        lineTitle->setText(QApplication::translate("GUIScreen", "Nombre de lignes :", Q_NULLPTR));
        label_2->setText(QApplication::translate("GUIScreen", "Nombre de colonnes : ", Q_NULLPTR));
        label->setText(QApplication::translate("GUIScreen", "Nombre de bombes : ", Q_NULLPTR));
        bombsUnit->clear();
        bombsUnit->insertItems(0, QStringList()
         << QApplication::translate("GUIScreen", "%", Q_NULLPTR)
         << QApplication::translate("GUIScreen", "bombes", Q_NULLPTR)
        );
        exitButton->setText(QApplication::translate("GUIScreen", "Quitter le jeu", Q_NULLPTR));
        giveUpButton->setText(QApplication::translate("GUIScreen", "Abandonner/Quitter", Q_NULLPTR));
        bonusButton->setText(QApplication::translate("GUIScreen", "R\303\251veler une case au hasard", Q_NULLPTR));
        label_6->setText(QApplication::translate("GUIScreen", "Nombres de bombes restantes : ", Q_NULLPTR));
        label_7->setText(QApplication::translate("GUIScreen", "Temps : ", Q_NULLPTR));
        help->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = scoresBoard->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GUIScreen", "Position", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = scoresBoard->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GUIScreen", "Pseudo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = scoresBoard->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GUIScreen", "Score", Q_NULLPTR));
        label_5->setText(QApplication::translate("GUIScreen", "Choisissez le type de tableau :", Q_NULLPTR));
        printScoreButton->setText(QApplication::translate("GUIScreen", "Afficher", Q_NULLPTR));
        toInitScreenButton->setText(QApplication::translate("GUIScreen", "Revenir \303\240 l'\303\251cran d'accueil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIScreen: public Ui_GUIScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUISCREEN_H
