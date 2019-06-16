#include "guiboard.h"
#include <sstream>

GUIBoard::GUIBoard(int row, int col){
    for (int k = 0; k < row; k++){
        for (int l = 0; l < col; l++){
            Square * aCase = new Square(k, l);
            aCase->setFixedSize(20,20);
            addWidget(aCase, k+1, l+1);
        }
    }
    setSpacing(0);
    setHorizontalSpacing(0);
    setMargin(0);

    addItem(new QSpacerItem(30,30,QSizePolicy::Minimum, QSizePolicy::Expanding), 0, 0, 1, col+2);
    addItem(new QSpacerItem(30,30,QSizePolicy::Minimum, QSizePolicy::Expanding), row+1, 0, 1, col+2);

    addItem(new QSpacerItem(30,30,QSizePolicy::Minimum, QSizePolicy::Expanding), 1, 0, row, 1);
    addItem(new QSpacerItem(30,30,QSizePolicy::Minimum, QSizePolicy::Expanding), 1, row+1, col, 1);
}

void GUIBoard::refreshBoard(Game *game) {
    int height = game->getBoard().getBoardType().dimension.height;
    for (int i = 0; i < height; i++) {
        updateLine(i,game);
    }
}

void GUIBoard::refreshBoardEndGame(Game *game){
    int height = game->getBoard().getBoardType().dimension.height;
    for (int i = 0; i < height; i++) {
        updateEndGameLine(i,game);
    }
}

void GUIBoard::updateLine(int line, Game *game) {
    for (int i = 0; i < game->getBoard().getBoardType().dimension.width; i++) {
        QLayoutItem * qli = itemAtPosition(line+1,i+1);
        if (!game->getBoard().getBoard()[line][i].isVisible()) {
            if (game->getBoard().getBoard()[line][i].isFlag()) {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/flag.png");
            } else {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/veiled.png");
            }
        } else {
            if (game->getBoard().getBoard()[line][i].isBomb()) {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/bomb.png");
            } else {
                int content = game->getBoard().getBoard()[line][i].getContent();
                string valStr = to_string(content);
                stringstream ss;
                ss << "./img_cases/" << valStr << ".png";
                string completePath = ss.str();
                dynamic_cast<Square *> (qli->widget())->setImg(completePath);
            }
        }
    }
}

void GUIBoard::updateEndGameLine(int line, Game * game){
    for (int i = 0; i < game->getBoard().getBoardType().dimension.width; i++) {
        QLayoutItem * qli = itemAtPosition(line+1,i+1);
        if (game->getBoard().getBoard()[line][i].isFlag() && !game->getBoard().getBoard()[line][i].isBomb()){
            dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/bombSet.png");
        } else if (!game->getBoard().getBoard()[line][i].isVisible()) {
            if (game->getBoard().getBoard()[line][i].isFlag()) {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/flag.png");
            } else {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/veiled.png");
            }
        } else {
            if (game->getBoard().getBoard()[line][i].isBomb()) {
                dynamic_cast<Square *> (qli->widget())->setImg("./img_cases/bomb.png");
            } else {
                int content = game->getBoard().getBoard()[line][i].getContent();
                string valStr = to_string(content);
                stringstream ss;
                ss << "./img_cases/" << valStr << ".png";
                string completePath = ss.str();
                dynamic_cast<Square *> (qli->widget())->setImg(completePath);
            }
        }
    }
}
