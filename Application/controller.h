#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "halloffame.h"
#include <cmath>

/*!
 * \brief The Controller class
 * It controls all the game and is the link between the view and the model.
 */
class Controller{
    private:

        /*!
         * \brief name_ the name of the player.
         */
        std::string name_;

        /*!
         * \brief score_ the score, number of seconds the player took to finish the game/
         */
        int score_;

        /*!
         * \brief hallOfFame_ the hall of fame containing the best 5 score for each type of board.
         */
        HallOfFame hallOfFame_;

        /*!
         * \brief game_, the model of the game Demineur.
         */
        Game * game_;

        /*!
         * \brief bonusUsed, a boolean indicating if the player has used its one-time bonus.
         */
        bool bonusUsed_;

        /*!
         * \brief nbClick, the number of click the user has done.
         */
        int nbClick;
    public:

        /*!
         * \brief Controller, the constructor
         * It creates an instance of the class from nothing
         */
        Controller();

        /*!
         * \brief The destructor
         * It deletes all the element from the class that need to be deleted.
         */
        ~Controller(){};

        /*!
         * \brief operator =
         * Assign the values of a controller to the current one.
         * \param o the controller that will give its value.
         * \return the newly formed controller.
         */
        inline Controller& operator=(Controller& o);

        /*!
         * \brief setName
         * Sets the name of the player.
         * \param name the name of the player.
         */
        inline void setName(std::string name);

        /*!
         * \brief setGame
         * Sets the game in the controller.
         * \param g The game to set.
         */
        inline void setGame(Game * g);

        /*!
         * \brief firstPlay
         * Play for the first time.
         * \param i The row of the board.
         * \param j The column of the board.
         */
        void firstPlay(int i, int j);

        /*!
         * \brief getName
         * Get the name of the user.
         * \return The name of the user.
         */
        inline std::string getName();

        /*!
         * \brief getScore
         * Get the score of the user.
         * \return The score of the user.
         */
        inline int getScore();

        /*!
         * \brief addScore
         * Add a score to the HoF.
         * \param boardType The boardType of the lastGame of the user.
         * \return True if the user has a score that can be added and false if not.
         */
        bool addScore(const BoardType &boardType);

        /*!
         * \brief getGame
         * Get the game.
         * \return The game of the controller.
         */
        inline Game *getGame();

        /*!
         * \brief getHOF
         * Get the hall of fame.
         * \return The hall of fame of the game.
         */
        inline HallOfFame getHOF();

        /*!
         * \brief playOnce
         * Play a turn.
         * \param i The row of board.
         * \param j The column of the board.
         * \param play True if the user wants to unveil a case and false if he just wants to flag a case.
         * \return 1 if a flag has been put, 2 if it has been removed, 3 if an error occured and 4 if the player only plays
         */
        int playOnce(int i, int j, bool play);

        /*!
         * \brief nbBombsDefault
         * Calculte the number of bombs by default.
         * \param i The number of row.
         * \param j The number of column.
         * \return The number of bombs for this format.
         */
        inline int nbBombsDefault(int i, int j);

        /*!
         * \brief isWon
         * Check if the player has won.
         * \return True if he won and false if not.
         */
        inline bool isWon();

        /*!
         * \brief isOver
         * Check if the game of the user is over.
         * \return True if the game is over and false if not.
         */
        inline bool isOver();

        /*!
         * \brief activateBonus
         * Use the bonus of the user.
         */
        inline void activateBonus();

        /*!
         * \brief isBonusUsed
         * Check if the bonus is already used.
         * \return True if the user has already used his bonus and false if not.
         */
        inline bool isBonusUsed();

        /*!
         * \brief setBonusUsed
         * Set the bonusUsed.
         * \param used The new value of bonusUsed.
         */
        inline void setBonusUsed(bool used);

        /*!
         * \brief setScore
         * Set the score of the user.
         * \param newScore The new score of the user.
         */
        inline void setScore(int newScore);

        /*!
         * \brief getNbClick
         * Get the number of click of the user when he's playing.
         * \return  The number of click of the user when he's playing.
         */
        inline int getNbClick();

        /*!
         * \brief addClick
         * Add a click on click count.
         */
        inline void addClick();

        /*!
         * \brief reInit
         * Init the controller.
         */
        inline void reInit();

};

//inline

std::string Controller::getName(){
    return name_;
}

int Controller::getScore(){
    return score_;
}

void Controller::setScore(int newScore) {
    score_ = newScore;
}

void Controller::setName(std::string name){
    name_ = name;
}

Game* Controller::getGame(){
    return game_;
}

HallOfFame Controller::getHOF(){
    return hallOfFame_;
}

Controller& Controller::operator=(Controller& o){
    if (this != &o){
        name_ = o.getName();
        score_ = o.getScore();
        hallOfFame_ = o.getHOF();
        game_ = o.getGame();
    }
    return *this;
}

void Controller::setGame(Game * g){
    game_ = g;
}

int Controller::nbBombsDefault(int i, int j){
    double multiply = i * j;
    double power = pow(multiply,2);
    double result = (0.0002 * power) + (0.0938 * multiply) + 0.8937;
    return round(result);
}

bool Controller::isWon(){
    return game_->isWon();
}

bool Controller::isOver(){
    return game_->isOver();
}

void Controller::activateBonus(){
    if (!bonusUsed_) {
        game_->activateBonus();
        bonusUsed_ = true;
    }
}

bool Controller::isBonusUsed(){
    return bonusUsed_;
}

void Controller::setBonusUsed(bool used){
    bonusUsed_ = used;
}

int Controller::getNbClick() {
    return nbClick;
}

void Controller::addClick() {
    nbClick++;
}

void Controller::reInit() {
    nbClick = 0;
    bonusUsed_ = false;
}

#endif // CONTROLLER_H
