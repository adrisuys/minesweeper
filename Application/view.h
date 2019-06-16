#ifndef VIEW_H
#define VIEW_H


#include <vector>
#include <string>
#include "score.h"
#include <iostream>

using namespace std;

class Game;

class Controller;

/*!
 * \brief The View class
 * This class represents the view of the Game. It handles all the thing that must be displayed such as
 * the board, the different messages for the player.
 */
class View{
public:

    /*!
     * \brief game_
     * The model of the game.
     */
    Game * game_;

protected:

    /*!
     * \brief controller_
     * The controller of the game.
     */
    Controller * controller_;
public:
    /*!
     * \brief View
     * Creates an instance of the class with a predefined Game.
     * \param game the model that will be linked to the view.
     */
    View(Game * game);

    /*!
     * \brief View
     * Creates an instance of the class from nothing.
     */
    View();

    /*!
     * \brief the destructor.
     * Deletes all the elements of the class that need to be deleted.
     */
    ~View(){};

    /*!
     * \brief setGame
     * Set the attribute game_ with the value of the Game in parameter.
     * \param game the game that will give its value to the current one.
     */
    void setGame(Game * game);

    /*!
     * \brief setController
     * Set the attribute controller_ with the value of the Controller in parameter.
     * \param controller the controller that will give its value to the current one.
     */
    void setController (Controller * controller);

    /*!
     * \brief printBoard
     * Displays the board.
     */
    void printBoard();

    /*!
     * \brief isPlayCommand
     * Indicates if the first element of the vector myCommand is "PLAY".
     * \param myCommand a vector of String. Actually it is a string split in a vector.
     * \return true if the first element is "PLAY", false otherwise.
     */
    bool isPlayCommand(std::vector<string> myCommand);

    /*!
     * \brief isFlagCommand
     * Indicates if the first element of the vector myCommand is "FLAG".
     * \param myCommand a vector of String. Actually it is a string split in a vector.
     * \return true if the first element is "FLAG", false otherwise.
     */
    bool isFlagCommand(std::vector<string> myCommand);

    /*!
     * \brief isExitCommand
     * Indicates if the first element of the vector myCommand is "FLAG".
     * \param myCommand a vector of String. Actually it is a string split in a vector.
     * \return true if the first element is "FLAG", false otherwise.
     */
    bool isExitCommand(std::vector<string> myCommand);

    /*!
     * \brief isAutoCommand
     * Indicates if the first element of the vextor myCommand is "AUTO"
     * \param myCommand a vector of String. Actually it is a string split in a vector.
     * \return true if the first element is "AUTO", false otherwise.
     */
    bool isAutoCommand(std::vector<string> myCommand);

    /*!
     * \brief isBonusCommand
     * Indicates if the first element of the vextor myCommand is "BONUS"
     * \param myCommand a vector of String. Actually it is a string split in a vector.
     * \return true if the first element is "BONUS", false otherwise.
     */
    bool isBonusCommand(std::vector<string> myCommand);

    /*!
     * \brief askUsername
     * Asks the user its name.
     * \return the string entered by the user.
     */
    std::string askUsername();

    /*!
     * \brief askCommand
     * Asks the user what he wants to play.
     * 'PLAY row col' or 'FLAG row col'.
     * It then convert this string in vector of string by splitting it where there are spaces in the string.
     * \return a vector of string that represents the command entered by the user.
     */
    std::vector<std::string> askCommand();

    /*!
     * \brief askInitCommand
     * Asks the user what he wants to play for the first play.
     * By default, the first case can not contain a bomb.
     * Plus, since it's the first play, it makes no sense to flag a case so the player has to play with
     * the command 'PLAY row col'.
     * It then convert this string in vector of string by splitting it where there are spaces in the string.
     * \return a vector of string that represents the command entered by the user.
     */
    std::vector<std::string> askInitCommand();

    /*!
     * \brief askNbRow
     * Asks the user the number of row he wants for the board of its game.
     * \param valMax the maximum number of row the board can have.
     * \return an int representing the number of row.
     */
    int askNbRow(int valMax);

    /*!
     * \brief askNbColumn
     * Asks the user the number of column he wants for the board of its game.
     * \param valMax the maximum number of column the board can have.
     * \return an int representing the number of column.
     */
    int askNbColumn(int valMax);

    /*!
     * \brief askNbBomb
     * Asks the user the number of bombs he wants for the board of its game to contain.
     * \param valMax the maximum number of bombs the board can contain.
     * \return an int representing the number of bombs.
     */
    double askNbBomb(int valMax);

    /*!
     * \brief getGame
     * Returns the modellinked to the view.
     * \return a Game, the model linked to the view.
     */
    inline Game* getGame();

    /*!
     * \brief displayLostMsg
     * Displays a message when the player has lost.
     */
    inline void displayLostMsg();

    /*!
     * \brief displayWinMsg
     * Displays a message when the player has won.
     */
    inline void displayWinMsg(int sec);

    /*!
     * \brief displayErrorMsg
     * Displays a message when the player does something wrong.
     */
    inline void displayErrorMsg();

    /*!
     * \brief displayTitle
     * Displays the title of the game Demineur.
     */
    inline void displayTitle();

    /*!
     * \brief displayTime
     * Displays the time, the number of seconds it has been since the beginning of the game.
     * \param sec an int representing the number of seconds it has been since the beginning of the game.
     */
    inline void displayTime(int sec);

    /*!
     * \brief displayAddScore
     * Displays a message that tells the user its score has been saved into the top5.
     * Its time is amongst the best five all time.
     */
    inline void displayAddScore();

    /*!
     * \brief displayLoser
     * Displays a message that tells the user its score is not good enough to be included in the top5.
     */
    inline void displayLoser();

    /*!
     * \brief displayTop
     * Displays the list of the best 5 scores (name of the player and time) for a given BoardType
     * \param top a vector of 5 scores (the best 5).
     * \param height, the height of the board.
     * \param width, the width of the board.
     * \param nbBomb, the number of bombs in the board.
     */
    inline void displayTop(std::vector<Score> top, int height, int width, int nbBomb);

    /*!
     * \brief configure
     * Asks the player if he wants to configure the board or play with the default board.
     * \return true if he wants to configure the board, false otherwise.
     */
    bool configure();

    /*!
     * \brief replay
     * Asks the player if he wants to replay directly.
     * \return true if he decides to replay, false otherwise.
     */
    bool replay();

    /*!
     * \brief displayNotFairMsg
     * Displays a message that tells the user he needs to at list play twice to enter the top.
     */
    inline void displayNotFairMsg();

    /*!
     * \brief update
     * Updates the view according to the id it gets in parameter.
     * \param idNotif an int representing the way the view has to update itself.
     */
    void update(int idNotif);

    /*!
     * \brief initName
     * Set the name of the player and print the title DEMINEUR;
     */
    void initName();

    /*!
     * \brief initGame
     * Ask the player what value he wants for the nb of row, columns and bombs and then
     * ask the controller to create a game.
     */
    Game initGame();

    /*!
     * \brief playDemineur
     * Simulates a game of Demineur from start to finish.
     */
    void playDemineur();

    inline int toInt(std::string str);

    inline void displayBonusErrorMsg();

private:
    void printNumberOfColumn();
    void printLine(int Line);
    void toUpperCase(std::string& str);
    std::vector<std::string>splitString(std::string sentence);
    std::vector<std::string> validateCmdFirstPlay();
    bool validateCmd(vector<string> cmd);
};

// inline

Game* View::getGame(){
    return game_;
}

void View::displayLostMsg(){
    cout << "Dommage vous avez perdu..." << endl;
}

void View::displayWinMsg(int sec){
    cout << "Yeah! Félicitations, vous avez gagné! Vous avez fini la partie en " << sec << " secondes!" << endl;
}

void View::displayErrorMsg(){
    cout << "Commande erronée, essaye encore!" << endl;
}

void View::displayTitle(){
    cout << " --- D E M I N E U R --- " << endl;
    cout << "Une fois sur la partie, vous pouvez utiliser le bonus. Ce dernier dévoilera une case au hasard \n"
         << "Cette case n'est pas une case contenant une bombe."<< endl;
}

void View::displayTime(int sec){
    cout << "TEMPS : " << sec << " secondes" << endl;
}

void View::displayAddScore(){
    cout << "Félicitation ! Vous avez été ajouté au tableau des scores !" << endl;
}

void View::displayLoser() {
    cout << "Votre score n'est pas assez bon que pour être insérer dans le Hall of Fame." << endl;
}

void View::displayNotFairMsg(){
    cout << "Vous avez gagné mais malheureusement, par soucis d'équité vis-à-vis des autres joueurs, nous ne faisons entrer les joueurs dans le top5 \n"
         << "qu'à partir du moment où ils ont réalisé au moins 2 coups. Si vous avez gagné en 1 coup, il y a de forte chance que vous ayez triché ou eu beaucoup de chance.\n"
         << "Désolé si vous aviez eu de la chance..." << endl;
}

void View::displayBonusErrorMsg(){
    cout << "Désolé, vous avez déjà utilisé ce bonus et il n'est malheureusement utilisable qu'une seule fois..." << endl;
}

void View::displayTop(std::vector<Score> top, int height, int width, int nbBomb) {
    int position = 1;
    cout << "------------- TOP UTILISATEUR ------------- " << endl;
    cout << "    Dimension: " << height << "x" << width << " Nombre de bombes: " << nbBomb << endl;
    for (Score score:top) {
        cout << position << ". " << score.getPlayerName() << " : " << score.getTime() << endl;
        position++;
    }
}

int View::toInt(string str){
    string::size_type sz;
    int nb = stoi(str,&sz);
    return nb;
}

#endif // VIEW_H

