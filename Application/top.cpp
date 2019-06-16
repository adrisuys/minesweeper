#include "top.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

Top::Top(vector<Score> top):top_{top}{
    Top::nbScore_ = 5;
}

Top::Top(): nbScore_{5} {

}

void Top::addScore(Score score){
    if (top_.size() < (unsigned)nbScore_){
        top_.push_back(score); // on rajoute à la fin le score
        sort(top_.begin(), top_.end(), [](Score & a, Score & b) -> bool{return a.getTime() < b.getTime();}); // tri
    } else {
        if (!Top::fitsInHoF(score)){
            throw invalid_argument("Votre score n'est pas assez bon pour rentrer dans le Hall Of Fame");
        } else {
            top_.pop_back();  // on enlève le score le plus mauvais
            top_.push_back(score); // on rajoute à la fin le nouveau score
            sort(top_.begin(), top_.end(), [](Score & a, Score & b) -> bool{return a.getTime() < b.getTime();}); // tri
        }
    }
}

bool Top::fitsInHoF(Score score){
    unsigned long i = 0;
    while (i < top_.size() && top_[i] < score) {
        i++;
    }
    return i < top_.size();
}

vector<Score> Top::getListScore() {
    //DEEPCOPY
    return vector<Score>(top_);
}

