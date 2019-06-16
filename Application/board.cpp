#include "board.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

Board::Board(const BoardType& btype): btype_{btype}{
    const int width = btype_.dimension.width;
    const int length = btype_.dimension.height;
    Coordinates c{0,0};
    std::vector<std::vector<Case>> tmp(length, std::vector<Case>(width,c));
    board_ = tmp;
    for (int i=0; i<length; i++){
        for (int j=0; j<width; j++){
            c = Coordinates{i,j};
            Case sq {c};
            board_[i][j] = sq;
        }
    }
}

int Board::getNbBombAround(Case square){
    int nbBomb {0};
    std::vector<Case*> v = getAdjacent(square);
    for (unsigned i = 0; i < v.size(); i++){
        if(v[i]->isBomb()){
            nbBomb++;
        }
    }
    return nbBomb;
}

std::vector<Case*> Board::getAdjacent(Case square){
    std::vector<Case*> v;
    int i = square.getCoordinates().row;
    int j = square.getCoordinates().col;
    int length = btype_.dimension.height - 1;
    int width = btype_.dimension.width - 1;
    if (i == 0 && j== 0){
        v.push_back(&board_[i][j+1]);
        v.push_back(&board_[i+1][j]);
        v.push_back(&board_[i+1][j+1]);
    } else if (i == length && j == 0){
        v.push_back(&board_[i-1][j]);
        v.push_back(&board_[i-1][j+1]);
        v.push_back(&board_[i][j+1]);
    } else if (j == 0) {
        v.push_back(&board_[i-1][j]);
        v.push_back(&board_[i+1][j]);
        v.push_back(&board_[i-1][j+1]);
        v.push_back(&board_[i][j+1]);
        v.push_back(&board_[i+1][j+1]);
    } else if (i == 0 && j == width){
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i+1][j-1]);
        v.push_back(&board_[i+1][j]);
    } else if (i == length && j == width){
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i-1][j-1]);
        v.push_back(&board_[i-1][j]);
    } else if (j == width){
        v.push_back(&board_[i-1][j]);
        v.push_back(&board_[i+1][j]);
        v.push_back(&board_[i-1][j-1]);
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i+1][j-1]);
    } else if (i == 0){
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i][j+1]);
        v.push_back(&board_[i+1][j-1]);
        v.push_back(&board_[i+1][j]);
        v.push_back(&board_[i+1][j+1]);
    } else if (i == length){
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i][j+1]);
        v.push_back(&board_[i-1][j-1]);
        v.push_back(&board_[i-1][j]);
        v.push_back(&board_[i-1][j+1]);
    } else {
        v.push_back(&board_[i-1][j-1]);
        v.push_back(&board_[i-1][j]);
        v.push_back(&board_[i-1][j+1]);
        v.push_back(&board_[i][j-1]);
        v.push_back(&board_[i][j+1]);
        v.push_back(&board_[i+1][j-1]);
        v.push_back(&board_[i+1][j]);
        v.push_back(&board_[i+1][j+1]);
    }
    return v;
}

void Board::unveilAll(){
    for (int i = 0; i < btype_.dimension.height; i++){
        for (int j = 0; j < btype_.dimension.width; j++){
            board_[i][j].unveil();
        }
    }
}

int Board::myrandom(int i){
    return rand()%i;
}

void Board::setBombsInTable(int col, int row){
    // first, create the list of cases (except (row, col))
    vector<Case*> cases;
    for (int i=0; i<btype_.dimension.height; i++){
        for (int j=0; j<btype_.dimension.width; j++){
            if (!(i==row && j==col)){
                cases.push_back(&board_[i][j]);
            }
        }
    }
    // shuffle this list
    srand(unsigned(time(0)));
    random_shuffle(cases.begin(), cases.end());
    // put the bombs on the first X cases
    for (int k=0; k < btype_.nbBomb; k++){
        cases[k]->putBomb();
    }
}

void Board::fillBoard(){
    for (int i=0; i<btype_.dimension.height; i++){
        for (int j=0; j<btype_.dimension.width; j++){
            if (!board_[i][j].isBomb()){
                int nbBombAround = getNbBombAround(board_[i][j]);
                board_[i][j].setContent(nbBombAround);
            }
        }
    }
}

bool Board::putFlag(int i, int j){
    if (board_[i][j].isFlag()){
        board_[i][j].removeFlag();
        return false;
    } else {
        if (!board_[i][j].isVisible()){
            board_[i][j].putFlag();
            return true;
        } else {
            throw std::invalid_argument("Tu ne peux pas poser de drapeau sur une case dévoilée!");
        }
    }
}

bool Board::isWon(){
    for (int i=0; i < btype_.dimension.height; i++){
        for (int j=0; j < btype_.dimension.width; j++){
            if (!board_[i][j].isBomb() && !board_[i][j].isVisible()){
                return false;
            }
        }
    }
    return true;
}

bool Board::isInsideBoard(int i, int j){
    return i >= 0 && i < btype_.dimension.height && j >= 0 && j < btype_.dimension.width;
}

bool Board::play(int i, int j){
    bool stillPlaying;
    if (board_[i][j].isBomb()){
        stillPlaying = false;
    } else if (!isInsideBoard(i,j) || board_[i][j].isVisible() || board_[i][j].isFlag()) {
        throw invalid_argument("Vous ne pouvez pas dévoiler une case qui n'est pas libre!");
    } else {
        playTurn(i,j);
        stillPlaying = true;
    }
    return stillPlaying;
}

void Board::playTurn(int i, int j){
    if (isInsideBoard(i,j) && !board_[i][j].isVisible() && !board_[i][j].isBomb() && !board_[i][j].isFlag()){
        board_[i][j].unveil();
        if (board_[i][j].getContent()==0){
            for (int m = -1; m <= 1; m++){
                for (int n = -1; n <= 1; n++){
                    playTurn(i+m, j+n);
                }
            }
        }
    }
}

Case Board::activateBonus(){
    vector<Case*> cases;
    for (int i=0; i<btype_.dimension.height; i++){
        for (int j=0; j<btype_.dimension.width; j++){
            if (!board_[i][j].isBomb() && !board_[i][j].isVisible()){
                cases.push_back(&board_[i][j]);
            }
        }
    }
    // shuffle this list
    srand(unsigned(time(0)));
    random_shuffle(cases.begin(), cases.end());
    // put the bombs on the first X cases
    //cases[0]->unveil();
    return *cases[0];
}
