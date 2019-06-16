#include "square.h"
#include <QPixmap>
#include <sstream>
#include <iostream>

using namespace std;

Square::Square(int column, int row) : row_{row}, column_{column}{
    setPixmap(QPixmap("./img_cases/veiled.png"));
    this->setStyleSheet("border: 1px solid black");
}

void Square::setImg(string path){
    setPixmap(QPixmap(path.c_str()));
}


