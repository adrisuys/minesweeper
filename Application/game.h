#ifndef GAME_H
#define GAME_H
#include "board.h"
#include <ctime>
#include <chrono>
#include <set>

using namespace std;

/*!
 * \brief The Game class
 * It represents the model of the application, it handles all the functionality of the game Demineur.
 */
class Game{
private:
    /*!
     * \brief board_ the board.
     */
    Board board_;

    /*!
     * \brief startTime_ a T moment that holds the starting time of the game.
     */
    std::chrono::time_point<std::chrono::system_clock> startTime_;

    /*!
     * \brief instantiated_ a boolean indicating if the game is instantiated or not.
     */
    bool instantiated_;

    /*!
     * \brief isOver_ a boolean indicating if the game is over or not.
     */
    bool isOver_;

    /*!
     * \brief isWon_ a boolean indicating if the game is won or not.
     */
    bool isWon_;
public:

    /*!
     * \brief Game the constructor
     * Instantiates an instance of the class with predefined Board and Player.
     * \param board the board on which the game has to be played.
     * \param player the player that plays.
     */
    Game(const Board& board);

    /*!
     * \brief Game the constructor
     * Instantiates an instance of the class with predefined lenght and width to set the board's dimension,
     * a number of bombs and the name of the player.
     * \param length the length (height, y-axis) of the board.
     * \param width the width (x-axis) of the board.
     * \param nbBombs the number of bombs that need to be put on the board.
     * \param name the name of the player.
     */
    Game(int length, int width, int nbBombs);

    /*!
     * \brief Game, the constructor
     * Creates an instance of the class from nothing.
     */
    Game() = default;

    /*!
     * \brief the destructor
     * Deletes all the element from the class that need to be deleted.
     */
    ~Game(){};

    /*!
     * \brief init
     * Initializes the Game by
     * - setting the bool instantiated_ to true
     * - put all the bombs on the table by choosing randomly the cases that must contain them.
     * - set the content (nb of bombs around) of each empty case
     * - unveil the case (i,j). This case, by default, never contains a bomb.
     * - start the timer.
     * \param i the row of the case we have to unveil.
     * \param j the column of the case we have to unveil.
     */
    void init(int i, int j);

    /*!
     * \brief getBoard
     * Returns the board of the game.
     * \return a Board, the board of the game.
     */
    inline Board& getBoard();

    /*!
     * \brief isInstantiated
     * Indicates if the game has been instantiated or not.
     * \return true if the game is instantiated, false otherwise.
     */
    inline bool isInstantiated();

    /*!
     * \brief getStartTime
     * Returns the starting time of the game.
     * \return the starting time of the game.
     */
    inline std::chrono::time_point<std::chrono::system_clock>& getStartTime();

    /*!
     * \brief isOver
     * Indicates if the game is over or not.
     * \return true if it is over, false otherwise.
     */
    inline bool isOver();

    /*!
     * \brief operator =
     * Assign the values of a game to the current one.
     * \param o the game that will give its value.
     * \return the newly formed game.
     */
    //inline Game& operator=(Game& o);

    /*!
     * \brief unveilAll
     * Unveills all the case of the board by setting the attribute visible_ of Case to true.
     */
    void unveilAll();

    /*!
     * \brief timeStop
     * Get the intermediate time. Before each display of the game, the current time will be kept in a variable
     * and we'll make a substraction : current time - starting time. Once converted in seconds, we will have the
     * number of seconds already spend on the game.
     * \return the number of seconds the player has played the game so far.
     */
    inline int timeStop();

    /*!
     * \brief isWon
     * Indicates if the game is won or not. To win, the player must unveil all the cases that are not bombs.
     * \return true if it is won, false otherwise.
     */
    bool isWon();
    /*!
     * \brief isOverAndWon
     * Indicates if the game is over and won.
     * \return true if it is won and over, false otherwise.
     */
    bool isOverAndWon();

    /*!
     * \brief putFlag
     * If the case already contains a flag, the flag will be removed, else a flag will be put.
     * We will set the attribut flag_ of Case to false or true, accordingly.
     * \param i the row of the case.
     * \param j the column of the case.
     * \return an int, 1 if the flag has been put, 2 if it has been removed and 3 if an error occured.
     */
    int putFlag(int i, int j);

    /*!
     * \brief play
     * Unveil the case (i,j).
     * If there is a bomb, the game is over (isOver_ set to true);
     * If the player can not play on this case, an invalid_argument is thrown (e.g., a flag is on it or it is already unveiled);
     * Else, we unveil the case.
     * \param i the row.
     * \param j the col.
     */
    void play(int i, int j);

    /*!
     * \brief activateBonus
     * Use the bonus of the user. It plays on a random case. This case is assured not to be a bomb.
     */
    void activateBonus();

private:
    void setBombsInTable(int x, int y);
    void fillBoard();
    void unveil(Case& square);
    void unveil(unsigned i, unsigned j);
};
//inline

Board &Game::getBoard(){
    return board_;
}

bool Game::isInstantiated(){
    return instantiated_;
}

std::chrono::time_point<chrono::system_clock> &Game::getStartTime(){
    return startTime_;
}

bool Game::isOver(){
    return isOver_;
}

/*Game& Game::operator=(Game& o){
    if (this != &o){
        board_ = o.getBoard();
        instantiated_ = o.isInstantiated();
        isOver_ = o.isOver();
        startTime_ = o.getStartTime();
    }
    return *this;
}*/

int Game::timeStop(){
    std::chrono::time_point<chrono::system_clock> tmp = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(tmp - startTime_).count();
}


#endif // GAME_H
