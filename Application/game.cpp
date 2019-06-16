#include "game.h"
#include <iostream>

using namespace std;

Game::Game(const Board& board) : board_{board},instantiated_{false},isOver_{false},isWon_{false}{
    //nothing
}

Game::Game(int length, int width, int nbBombs):instantiated_{false},isOver_{false},isWon_{false}{
    Dimension dim {length, width};
    BoardType bt {dim,nbBombs};
    Board b{bt};
    board_ = b;
}

void Game::init(int i, int j){
    instantiated_ = true;
    setBombsInTable(j,i);
    fillBoard();
    board_.play(i,j);
    startTime_ = std::chrono::system_clock::now();
    if (isWon()){
        unveilAll();
    }
}

void Game::unveil(Case& square){
    square.unveil();
}

void Game::unveil(unsigned i, unsigned j) {
    Case& caseToUnveil(board_.getBoard()[i][j]);
    unveil(caseToUnveil);
}

bool Game::isWon(){
    if (board_.isWon()) {
        isWon_ = true;
        isOver_ = true;
        return true;
    } else {
        return false;
    }
}

bool Game::isOverAndWon() {
    return isWon_;
}

int Game::putFlag(int i, int j){
    try{
        bool flag = board_.putFlag(i,j);
        isWon();
        if (flag){
            return 1;
        } else {
            return 2;
        }
    } catch (invalid_argument& e){
        return 3;
    }
}

void Game::setBombsInTable(int x, int y){
    board_.setBombsInTable(x,y);
}

void Game::fillBoard(){
    board_.fillBoard();
}

void Game::play(int i, int j){
    try{
        if (!board_.play(i,j)){
            isOver_ = true;
        }
        if (isOver()){
            unveilAll();
        } else if (isWon()){
            unveilAll();
        }
    } catch (invalid_argument& ex){
    }
}

void Game::unveilAll(){
    board_.unveilAll();
}

void Game::activateBonus(){
    Case sq = board_.activateBonus();
    int i = sq.getCoordinates().row;
    int j = sq.getCoordinates().col;
    play(i,j);
}





