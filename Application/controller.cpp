#include "controller.h"
#include <sstream>
#include <string>

using namespace std;

//Controller::Controller(View view): name_{""}, score_{0}, nbClick(0){
//    HallOfFame hallOfFame;
//    view_ = view;
//    hallOfFame_=hallOfFame;
//    hallOfFame_.initMapScore();
//    bonusUsed_ = false;
//}

//Controller::Controller(GUIScreen *gui):
//    name_{""},
//    score_{0},
//    nbClick(0)
//{
//    HallOfFame hallOfFame;
//    gui_ = gui;
//    hallOfFame_=hallOfFame;
//    hallOfFame_.initMapScore();
//    bonusUsed_ = false;
//}

Controller::Controller(): name_{""}, score_{0}, nbClick(0){
    HallOfFame hallOfFame;
    hallOfFame_=hallOfFame;
    hallOfFame_.initMapScore();
    bonusUsed_ = false;
}

void Controller::firstPlay(int i, int j){
    addClick();
    game_->init(i,j);
}

bool Controller::addScore(const BoardType& boardType) {
    try {
        Score score(name_,score_);
        hallOfFame_.addScore(boardType,score);
        hallOfFame_.writeFile();
        return true;
    } catch (invalid_argument e) {
        return false;
    }
}

int Controller::playOnce(int i, int j, bool play){
   if (play){
        game_->play(i,j);
        addClick();
        return 4;
    } else {
        return game_->putFlag(i,j);
    }
}
