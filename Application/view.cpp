
/*
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include "view.h"


using namespace std;

View::View(Game *game){
    setGame(game);
}

View::View() : game_{0}, controller_{0}{
    //Nothing
}

void View::setGame(Game* game) {
    game_ = game;
}

void View::setController(Controller *controller){
    controller_ = controller;
}

void View::printBoard() {
    printNumberOfColumn();
    for (int i = 0; i < game_->getBoard().getBoardType().dimension.height; i++) {
        printLine(i);
        cout << endl;
    }
    cout << endl;
}

 void View::printLine(int line) {
    cout << setw(2) << line << " |  ";
    for (int i = 0; i < game_->getBoard().getBoardType().dimension.width; i++) {
        if (!game_->getBoard().getBoard()[line][i].isVisible()) {
            if (game_->getBoard().getBoard()[line][i].isFlag()) {
                cout << "F |  ";
            } else {
                cout << ". |  ";
            }
        } else {
            if (game_->getBoard().getBoard()[line][i].isBomb()) {
                cout << "* |  ";
            } else if (game_->getBoard().getBoard()[line][i].getContent() == 0) {
                cout << " " << " |  ";
            } else {
                cout << "" << game_->getBoard().getBoard()[line][i].getContent() << " |  ";
            }
        }
    }
    cout << endl;
}

void View::printNumberOfColumn() {
    cout << "    ";
    for (int i = 0; i < game_->getBoard().getBoardType().dimension.width; i++) {
        if (i < 10) cout << "  " << i << " |";
        else cout << " " << i << " |";
    }
    cout << endl;
}

vector<string> View::askCommand() {
    string command;
    cout << "Entrez une commande (ex: play 2 3 OU flag 2 3 OU exit OU bonus) : ";
    getline (cin, command);
    return splitString(command);
}

vector<string> View::askInitCommand() {
    string command;
    cout << "Il vous faut initialiser la partie, décidez de la case qui sera dévoilée." << endl;
    cout << "Par défaut, ça ne sera pas une bombe." << endl;
    cout << "Entrez une commande (ex: play 2 3) : ";
    getline (cin, command);
    return splitString(command);
}

int View::askNbRow(int valMax) {
    int nbRow;
    string commandNbRow;
    istringstream istr;
    cout << "Combien de lignes souhaitez-vous pour votre tableau ?";
    getline(cin, commandNbRow);
    istr.str(commandNbRow);
    while (!(istr >> nbRow) || nbRow < 2 || nbRow > valMax) {
        cout << "Nombre de lignes incorrectes ! (Min 2,Max " << valMax << ")" << endl;
        return askNbRow(valMax);
    }
    return nbRow;
}

double View::askNbBomb(int valMax) {
    double nbBomb;
    string command;
    istringstream istr;
    vector<string> splitCommand;
    cout << "Entrez la densité ou le nombre de bombes souhaité (ex: d 23 (d = densité en %) OU 23 (nombre de bombes) ou 'AUTO' si vous voulez un nombre de bombes par défaut : ";
    getline(cin,command);
    splitCommand = splitString(command);
    toUpperCase(splitCommand[0]);
    if (isAutoCommand(splitCommand)){
        return -1;
    } else if (splitCommand[0].compare("D")==0) {
        istr.str(splitCommand[1]);
        if (istr >> nbBomb) {
            if (nbBomb > 0 && nbBomb < 100) {
                return nbBomb/100.0;
            } else {
                cout << "Vous devez taper une densité comprise entre 1 et 99" << endl;
                return askNbBomb(valMax);
            }
        } else {
            cout << "Commande incorrecte ! " << endl;
            return askNbBomb(valMax);
        }
    } else {
        istr.str(splitCommand[0]);
        if (istr >> nbBomb) {
            if (nbBomb > valMax) {
                cout << "Commande incorrecte ! Nombre trop élevé de bombes !" << endl;
                return askNbBomb(valMax);
            } else {
                return nbBomb;
            }

        } else {
            cout << "Commande incorrecte ! " << endl;
            return askNbBomb(valMax);
        }
    }
}

int View::askNbColumn(int valMax) {
    int nbColumn;
    string commandNbColumn;
    istringstream istr;
    cout << "Combien de colonnes souhaitez-vous pour votre tableau ? ";
    getline(cin, commandNbColumn);
    istr.str(commandNbColumn);
    while (!(istr >> nbColumn) || nbColumn < 2 || nbColumn > valMax) {
        cout << "Nombre de colonnes incorrectes ! (Min 2,Max " << valMax << ")" << endl;
        return askNbColumn(valMax);
    }
    return nbColumn;
}

vector<string> View::splitString(string sentence) {
    vector<string> command;
    sentence.push_back(' ');
    string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = sentence.find(delimiter)) != string::npos) {
        token = sentence.substr(0, pos);
        command.push_back(token);
        sentence.erase(0, pos + delimiter.length());
    }
    return command;
}

bool View::isPlayCommand(vector<string> myCommand) {
    int line, column;
    bool isCorrect(false);
    toUpperCase(myCommand[0]);
    if (myCommand[0].compare("PLAY") == 0) {
        istringstream istr(myCommand[1]);
        istringstream istr1(myCommand[2]);
        istr >> line;
        istr1 >> column;
        if (istr.fail() || istr1.fail()){
            isCorrect = false;
        } else if (istr.eof() && istr.eof()){
            if (0 <= line && line < game_->getBoard().getBoardType().dimension.height) {
                if (0 <= column && column < game_->getBoard().getBoardType().dimension.width) {
                    isCorrect = true;
                }
            }
        } else {
            isCorrect = false;
        }
    }
    return isCorrect;
}

bool View::isFlagCommand(vector<string> myCommand) {
    int line, column;
    bool isCorrect(false);
    toUpperCase(myCommand[0]);
    if (myCommand[0].compare("FLAG") == 0) {
        istringstream istr(myCommand[1]);
        istringstream istr1(myCommand[2]);
        istr >> line;
        istr1 >> column;
        if (istr.fail() || istr1.fail()){
            isCorrect = false;
        } else if (istr.eof() && istr.eof()){
            if (0 <= line && line < game_->getBoard().getBoardType().dimension.height) {
                if (0 <= column && column < game_->getBoard().getBoardType().dimension.width) {
                    isCorrect = true;
                }
            }
        } else {
            isCorrect = false;
        }
    }
    return isCorrect;
}

bool View::isExitCommand(vector<string> myCommand){
    if (myCommand.size() > 1) return false;
    toUpperCase(myCommand[0]);
    if (myCommand[0].compare("EXIT") == 0){
        return true;
    } else {
        return false;
    }
}

bool View::isBonusCommand(std::vector<string> myCommand){
    if (myCommand.size() > 1) return false;
    toUpperCase(myCommand[0]);
    if (myCommand[0].compare("BONUS") == 0){
        return true;
    } else {
        return false;
    }
}

string View::askUsername() {
    string username;
    cout << "Entrez votre pseudo : ";
    getline (cin, username);
    return username;
}

void View::toUpperCase(string& str) {
    int i=0;
    char c;
    while (str[i]) {
        c=str[i];
        str[i] = toupper(c);
        i++;
    }
}

bool View::configure(){
    string cmd;
    cout << "Si vous voulez configurer le plateau de jeu, entrez 'settings'. Sinon, entrez 'play'." << endl;
    cout << "Dans le cas où vous jouez directement, le tableau est de dimension 9x9 et comprend 10 bombes" << endl;
    getline(cin, cmd);
    toUpperCase(cmd);
    if (cmd.compare("SETTINGS")==0){
        return true;
    } else if (cmd.compare("PLAY")==0) {
        cout << "Vous avez décidé de jouer avec les valeurs par défaut! C'est parti ! Bonne chance!" << endl;
        return false;
    } else {
        cout << "Commande incorrecte ! " << endl;
        return configure();
    }
}

void View::update(int i){
    switch(i){
        case 1 :
            displayTime(game_->timeStop());
            printBoard(); break;
        case 2 :
            displayLostMsg();
            displayTime(game_->timeStop());
            printBoard();
            break;
        case 3 : displayWinMsg(game_->timeStop());
                 printBoard(); break;
        case 4 : displayNotFairMsg();
                 printBoard(); break;
        case 5 : cout << "Vous ne pouvez pas dévoiler une case qui n'est pas libre!" << endl; break;
        case 6 : cout << "Vous ne pouvez pas poser de drapeau sur une case dévoilée!" << endl; break;
        default : break;
    }
}

void View::initName(){
    displayTitle();
    controller_->setName(askUsername());
}

Game View::initGame(){
    int height;
    int width;
    double nbBombs;
    bool settings = configure();
    if (!settings){
        height = 9;
        width = 9;
        nbBombs = controller_->nbBombsDefault(height,width);
    } else {
        height = askNbRow(100);
        width = askNbColumn(100);
        int valMax = height * width - 1;
        nbBombs = askNbBomb(valMax);
        //Dans le cas où un user a décidé de prendre le nombre de bombes par défaut.
        if (nbBombs == -1){
            nbBombs = controller_->nbBombsDefault(height,width);
        }
        //Dans le cas où le user a rentré un pourcentage de bombes.
        else if (nbBombs < 1) {
            nbBombs = round(height * width * nbBombs);
            if (nbBombs < 1){
                nbBombs = 1;
            }
        }
    }
    Game game = controller_->createGame(height, width, nbBombs);
    return game;
}

bool View::isAutoCommand(std::vector<string> myCommand){
    if (myCommand.size() > 1) return false;
    toUpperCase(myCommand[0]);
    if (myCommand[0].compare("AUTO") == 0){
        return true;
    } else {
        return false;
    }
}

void View::playDemineur(){
    printBoard();
    vector<string> cmd = validateCmdFirstPlay();
    int i = toInt(cmd[1]);
    int j = toInt(cmd[2]);
    controller_->firstPlay(i, j);
    if (controller_->isWon()){
        controller_->handleCheat();
    } else {
        //play();
        bool win = false;
        bool lost = false;
        while (!win && !lost){
            bool unvalid = true;
            vector<string> cmd;
            while (unvalid){
                cmd = askCommand();
                unvalid = !validateCmd(cmd);
                if (unvalid) displayErrorMsg();
            }
            if (isExitCommand(cmd)){
                lost = true;
            } else if (isBonusCommand(cmd)){
                if (!controller_->isBonusUsed()){
                    controller_->activateBonus();
                    controller_->setBonusUsed(true);
                } else {
                    displayBonusErrorMsg();
                }
            } else {
                int i = toInt(cmd[1]);
                int j = toInt(cmd[2]);
                if (isFlagCommand(cmd)){
                    controller_->playOnce(i, j, false);
                } else if (isPlayCommand(cmd)) {
                    controller_->playOnce(i, j, true);
                    if (controller_->isOver()){
                        lost = true;
                    }
                    if (controller_->isWon()){
                        win = true;
                    }
                }else {
                    //nothing
                }
            }
        }
        controller_->handleEndGame(lost);
    }

}

vector<string> View::validateCmdFirstPlay(){
    bool unvalid = true;
    vector<string> cmd;
    while (unvalid){
        cmd = askInitCommand();
        unvalid = !validateCmd(cmd);
        if (isFlagCommand(cmd)){
            unvalid = true;
        }
        if (isExitCommand(cmd)){
            unvalid = true;
        }
        if (unvalid) displayErrorMsg();
    }
    return cmd;
}

bool View::validateCmd(vector<string> cmd){
    if (isExitCommand(cmd)){
        return true;
    }
    if (isBonusCommand(cmd)){
        return true;
    }
    if (isFlagCommand(cmd)){
        return true;
    }
    if (isPlayCommand(cmd)){
        return true;
    }
    return false;
}
*/
