#include "guiscreen.h"
#include "ui_guiscreen.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QSpacerItem>
#include <QPixmap>
#include <QTimer>
#include <sstream>
#include <cstdlib>

using namespace std;



GUIScreen::GUIScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIScreen),
    timer{new QTimer(this)}
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    initMineSweeperTitle();
    connectWidgetsToMethods();
}

GUIScreen::~GUIScreen()
{
    delete ui;
}

void GUIScreen::connectWidgetsToMethods()
{
    connect(ui->defaultGameButton,&QPushButton::clicked, this, &GUIScreen::launchDefaultGame);
    connect(ui->personnalizedGameButton,&QPushButton::clicked, this, &GUIScreen::initGame);
    connect(ui->playButton,&QPushButton::clicked, this, &GUIScreen::initName);
    connect(ui->quitButton,&QPushButton::clicked, this, &GUIScreen::exitMinesWeeper);
    connect(ui->giveUpButton,&QPushButton::clicked, this, &GUIScreen::goBackToInitScreen);
    connect(ui->exitButton,&QPushButton::clicked, this, &GUIScreen::exitMinesWeeper);
    connect(ui->hallOfFameButton,&QPushButton::clicked, this, &GUIScreen::goToStatScreen);
    connect(ui->toInitScreenButton,&QPushButton::clicked, this, &GUIScreen::goToInitScreen);
    connect(ui->printScoreButton,&QPushButton::clicked, this, &GUIScreen::printScore);
    connect(ui->bonusButton,&QPushButton::clicked,this,&GUIScreen::useBonus);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    ui->bonusButton->setEnabled(false);
    ui->help->setPixmap(QPixmap("./img_cases/help.png"));
    ui->help->setToolTip("Le bonus, utilisable une fois sur la partie, révèle une case au hasard.\n Cette case ne contiendra pas de bombe.");
}

void GUIScreen::setController(Controller *controller) {
    controller_ = controller;
}

void GUIScreen::initMineSweeperTitle() {
    QPixmap pixmap("./img_cases/title.png");
    ui->MineSweeperTitle->setPixmap(pixmap);
}

void GUIScreen::goToPlayScreen() {
    ui->stackedWidget->setCurrentIndex(2);
}

void GUIScreen::goToStatScreen() {
    ui->stackedWidget->setCurrentIndex(3);
    refreshHoF();
}

void GUIScreen::goToInitScreen() {
    ui->stackedWidget->setCurrentIndex(1);
    initTime();
}

void GUIScreen::goBackToInitScreen(){
    stopTimer();
    auto listWidget = ui->frame;
    for (auto widget: listWidget->findChildren<QWidget*>()) delete widget;
    delete ui->frame->layout();
    controller_->reInit();
    delete game_;
    goToInitScreen();
}

void GUIScreen::useBonus() {
    controller_->activateBonus();
    update();
}

void GUIScreen::refreshHoF() {
    ui->boardTypeBox->clear();
    vector<string> keys = controller_->getHOF().getKeys();
    for (string aKey : keys) {
        QString key(aKey.c_str());
        ui->boardTypeBox->addItem(key);
    }
}

void GUIScreen::clearScoreBoard() {
    int nbRow = ui->scoresBoard->rowCount();
    for (nbRow-1;nbRow >= 0; nbRow--) {
        ui->scoresBoard->removeRow(nbRow);
    }
}

void GUIScreen::printScore() {
    int index;
    clearScoreBoard();
    if (ui->boardTypeBox->currentIndex() >= 0) {
        index = ui->boardTypeBox->currentIndex();
        vector<Score> top = controller_->getHOF().getTop(index);
        int position = 1;
        for (Score aScore : top) {
            ui->scoresBoard->insertRow(ui->scoresBoard->rowCount());
            ui->scoresBoard->setItem(ui->scoresBoard->rowCount()-1,0,new QTableWidgetItem(to_string(position).c_str()));
            ui->scoresBoard->setItem(ui->scoresBoard->rowCount()-1,1,new QTableWidgetItem(aScore.getPlayerName().c_str()));
            ui->scoresBoard->setItem(ui->scoresBoard->rowCount()-1,2,new QTableWidgetItem(to_string(aScore.getTime()).c_str()));
            position++;
        }
    }
}

void GUIScreen::initTime() {
    controller_->setScore(0);
    ui->timer->display(0);
}

void GUIScreen::launchTimer() {
    timer->start(1000);
}

void GUIScreen::stopTimer() {
    timer->stop();
}

void GUIScreen::showTime() {
    QString text;
    controller_->setScore(controller_->getScore() + 1);
    text = QString::number(controller_->getScore());
    ui->timer->display(text);
}

void GUIScreen::launchDefaultGame() {
    game_ = new Game(9,9,10);
    controller_->setGame(game_);
    generateBoard(9,9);
    goToPlayScreen();
    ui->bombCounter->display(10);
}

void GUIScreen::launchGame(int height, int width, double nbBombs) {
    game_ = new Game(height, width, nbBombs);
    controller_->setGame(game_);
    generateBoard(height,width);
    goToPlayScreen();
    ui->bombCounter->display(nbBombs);
}

void GUIScreen::generateBoard(int height, int width){
    board = new GUIBoard(height,width);
    ui->frame->setLayout(board);
}

void GUIScreen::launchAlertBox(string msg)
{
    QMessageBox::information(this,tr(""),tr(msg.c_str()));
}

void GUIScreen::initName() {
    QString usernameIn = ui->usernameInput->text();
    string username = usernameIn.toStdString();
    if (username.compare("") != 0) {
        controller_->setName(usernameIn.toStdString());
        goToInitScreen();
    } else {
        launchAlertBox("Vous devez entrer un nom pour pouvoir commencer à jouer.");
    }
}

void GUIScreen::exitMinesWeeper() {
    exit(0);
}

void GUIScreen::initGame() {
    int height;
    int width;
    double nbBombs;
    bool isCorrectParameters = true;
    istringstream istrWidth, istrHeight,istrBombs;
    QString widthInput = ui->nbColumnInput->text();
    QString heightInput = ui->nbLineInput->text();
    QString nbBombsInput = ui->bombInput->text();

    if (widthInput.toStdString().compare("") != 0) {
            istrWidth.str(widthInput.toStdString());
            if (!(istrWidth >> width) || width < 2 || width > 40) {
                launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de colonnes valide ! (Min : 2, Max : 40)");
                isCorrectParameters = false;
            }
    } else {
        launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de colonnes !");
        isCorrectParameters = false;
    }

    if (heightInput.toStdString().compare("") != 0) {
            istrHeight.str(heightInput.toStdString());
            if (!(istrHeight >> height) || height < 2 || height > 25) {
                launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de lignes valide ! (Min : 2, Max : 25)");
                isCorrectParameters = false;
            }
    } else {
        launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de lignes");
        isCorrectParameters = false;
    }

    if (isCorrectParameters) {
        if (ui->defaultNbBomb->isChecked()) {
            nbBombs = controller_->nbBombsDefault(height,width);
        } else {
            if (nbBombsInput.toStdString().compare("") != 0) {
                if (ui->bombsUnit->currentText().toStdString().compare("%")==0) {
                    istrBombs.str(nbBombsInput.toStdString());
                    if (istrBombs >> nbBombs) {
                        if (nbBombs > 0 && nbBombs < 100) {
                            nbBombs = round(height * width * (nbBombs/100));
                        } else {
                            launchAlertBox("Entrée incorrecte ! \nVous devez rentrer une densité cohérente ! (Min : 1 Max: 99)");
                            isCorrectParameters = false;
                        }
                    }
                } else {
                    istrBombs.str(nbBombsInput.toStdString());
                    if (istrBombs >> nbBombs) {
                        int valMax = (height * width) - 1 ;
                        if (nbBombs < 1 || nbBombs > valMax) {
                            string msg = "Entrée incorrecte ! \nVous devez rentrer un nombre de bombe compris entre 1 et ";
                            msg.append(to_string(valMax));
                            msg.append(".");
                            launchAlertBox(msg.c_str());
                            isCorrectParameters = false;
                        }
                    } else {
                        launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de bombe compris entre 1 et valMax");
                        isCorrectParameters = false;
                    }
                }
            } else {
                launchAlertBox("Entrée incorrecte ! \nVous devez rentrer un nombre de bombes.");
                isCorrectParameters = false;
            }
        }
    }

    if (isCorrectParameters) {
        launchGame(height, width, nbBombs);
    }
 }


void GUIScreen::update() {
    string valTime {to_string(controller_->getScore())};
    string msg {""};
    if (game_->isOver()) {
        if (game_->isOverAndWon()) {
            if (controller_->getNbClick() == 1) {
                timer->stop();
                board->refreshBoard(game_);
                launchAlertBox("Vous avez gagné mais malheureusement, par soucis d'équité vis-à-vis des autres joueurs, nous ne faisons entrer les joueurs dans le top5 à partir du moment où ils ont réalisé au moins 2 coups. Si vous avez gagné en 1 coup, il y a de forte chance que vous ayez triché ou eu beaucoup de chance. Désolé si vous aviez eu de la chance...");
            } else {
                timer->stop();
                board->refreshBoard(game_);
                msg.append("Yeah! Félicitations, vous avez gagné! \nVous avez fini la partie en ");
                msg.append(valTime);
                msg.append(" secondes!");
                controller_->addScore(game_->getBoard().getBoardType());
                launchAlertBox(msg.c_str());
            }
        } else {
            timer->stop();
            launchAlertBox("Dommage vous avez perdu...");
            //board->refreshBoard(game_);
            board->refreshBoardEndGame(game_);
        }
    } else {
        board->refreshBoard(game_);
    }
}

void GUIScreen::mousePressEvent(QMouseEvent *event){
    QWidget * const widget = childAt(event->pos());
    Square * sq = dynamic_cast<Square *> (widget);
    if (sq){
        int col = sq->getRow();
        int row = sq->getCol();
        if (event->button() == Qt::LeftButton){
            if (controller_->getNbClick() == 0) {
                controller_->firstPlay(row,col);
                ui->bonusButton->setEnabled(true);
                launchTimer();
            } else {
                controller_->playOnce(row,col,true);
            }
        } else if (event->button() == Qt::RightButton){
            int i = controller_->playOnce(row,col,false);
            int nbBombsLeft = ui->bombCounter->value();
            if (i == 1){
                ui->bombCounter->display(nbBombsLeft-1);
            } else if (i == 2){
                ui->bombCounter->display(nbBombsLeft+1);
            }
        }
        update();
    }

}
