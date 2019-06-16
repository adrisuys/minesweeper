#include "halloffame.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <score.h>
#include <algorithm>

using namespace std;

HallOfFame::HallOfFame() {
    map<BoardType,Top*> myMap;
    scores_ = myMap;
}

void HallOfFame::addScore(const BoardType& boardType, const Score& score) {
    try {
        putInMap(boardType,score);
    } catch (invalid_argument e) {
        throw;
    }

}

void HallOfFame::initMapScore() {
    ifstream scoreFile("Score.txt");
    vector<string> splitScoreLine;
    string aScoreLine,name;
    int height, width, nbBomb, time;
    Dimension dim;
    BoardType boardType;

    if(scoreFile) {
        while(getline(scoreFile, aScoreLine)) {
            splitScoreLine = splitString(aScoreLine);
            if (checkScoreLine(splitScoreLine)) {
                height = getHeight(splitScoreLine);
                width = getWidth(splitScoreLine);
                nbBomb = getNbBomb(splitScoreLine);
                name = getName(splitScoreLine);
                time = getTime(splitScoreLine);
                dim.height = height;
                dim.width = width;
                boardType.dimension = dim;
                boardType.nbBomb = nbBomb;
                Score score(name,time);
                putInMap(boardType,score);
            }
        }
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

std::vector<Score> HallOfFame::getTop(const BoardType& boardType) {
    map<BoardType,Top*>::iterator it = scores_.find(boardType);
    if (it != scores_.end()) {
        return it->second->getListScore();
    } else {
        throw invalid_argument("Le BoardType en paramètre n'existe pas.");
    }
}

std::vector<Score> HallOfFame::getTop(int index) {
    if (index < scores_.size()) {
        int i = 0;
        map<BoardType,Top*>::iterator it=scores_.begin();
        while (i != index) {
            i++;
            it++;
        }
        return it->second->getListScore();
    } else {
        vector<Score> trash;
        return trash;
    }
}

void HallOfFame::writeFile() {
    int height, width, nbBomb, time;
    string name;
    vector<Score> list;
    ofstream flux("Score.txt");
    if(flux) {
        for(map<BoardType,Top*>::iterator it=scores_.begin() ; it!=scores_.end() ; ++it) {
            list = it->second->getListScore();
            height = it->first.dimension.height;
            width = it->first.dimension.width;
            nbBomb = it->first.nbBomb;
            for (Score aScore : list) {
                name = aScore.getPlayerName();
                time = aScore.getTime();
                flux << height << '.' << width << '.' << nbBomb << '.' << name << '.' << time << endl;
            }
        }
    }

}

void HallOfFame::putInMap(const BoardType& boardType,const Score& score) {
    map<BoardType,Top*>::iterator it = scores_.find(boardType);
    if (it != scores_.end()) {
        it->second->addScore(score);
    } else {
        try {
            scores_.insert(pair<BoardType,Top*>(boardType,new Top));
            it = scores_.find(boardType);
            it->second->addScore(score);
        } catch (invalid_argument& e) {
            throw;
        }

    }
}

vector<string> HallOfFame::splitString(string sentence) {
    vector<string> command;
    sentence.push_back('.');
    string delimiter = ".";

    size_t pos = 0;
    string token;
    while ((pos = sentence.find(delimiter)) != string::npos) {
        token = sentence.substr(0, pos);
        command.push_back(token);
        sentence.erase(0, pos + delimiter.length());
    }
    return command;
}

int HallOfFame::getHeight(vector<string>splitScoreLine) {
    istringstream istr(splitScoreLine[0]);
    int height;
    istr >> height;
    return height;
}

int HallOfFame::getWidth(vector<string>splitScoreLine) {
    istringstream istr(splitScoreLine[1]);
    int width;
    istr >> width;
    return width;
}

int HallOfFame::getNbBomb(vector<string>splitScoreLine) {
    istringstream istr(splitScoreLine[2]);
    int nbBomb;
    istr >> nbBomb;
    return nbBomb;
}

string HallOfFame::getName(vector<string>splitScoreLine) {
    return splitScoreLine[3];
}

int HallOfFame::getTime(vector<string>splitScoreLine) {
    istringstream istr(splitScoreLine[4]);
    int time;
    istr >> time;
    return time;
}

bool HallOfFame::checkScoreLine(vector<string> scoreLine) {
    int i(0);
    if (scoreLine.size() == 5) {
        while (i < 3 && isConvertibleToInt(scoreLine[i])) {
            i++;
        }
        if (i==3) {
            if (isConvertibleToInt(scoreLine[4])) {
                return true;
            }
        }
    }
    return false;
}

bool HallOfFame::isConvertibleToInt(string str) {
    return !str.empty() && find_if(str.begin(),
            str.end(), [](char c) { return !isdigit(c); }) == str.end();
}

vector<string> HallOfFame::getKeys() {
    vector<string> keys;
    int height, width, nbBomb;
    string key;
    for(map<BoardType,Top*>::iterator it=scores_.begin() ; it!=scores_.end() ; ++it) {
        key.clear();
        height = it->first.dimension.height;
        width = it->first.dimension.width;
        nbBomb = it->first.nbBomb;
        key.append(to_string(height));
        key.append("x");
        key.append(to_string(width));
        key.append(" ");
        key.append(to_string(nbBomb));
        key.append("b");
        keys.push_back(key);
    }
    return keys;
}
