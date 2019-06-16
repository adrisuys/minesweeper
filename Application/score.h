#ifndef SCORE_H
#define SCORE_H

#include <string>

/*!
 * \brief The Score class
 * This class represents the score of a player. It has the name of the player and its time (the time he took to finish the game).
 */
class Score {

private:
    /*!
     * \brief playerName_ the name of the player.
     */
    std::string playerName_;

    /*!
     * \brief time_ the time of the player.
     */
    int time_;
public:
    /*!
     * \brief Score, the constructor
     * Creates an instance of the class with a predefined name and time.
     * \param playerName the name of the player.
     * \param score the time of the player.
     */
    Score(std::string playerName, int score);

    /*!
     * \brief Score, the constructor
     * Creates an instance of the class from nothing.
     */
    Score() = default;

    /*!
     * \brief the destructor
     * Deletes all the element from the class that need to be deleted.
     */
    ~Score(){};

    /*!
     * \brief getTime
     * Returns the time of the player.
     * \return an int representing the time the player took to finish the game.
     */
    inline int getTime();

    /*!
     * \brief getPlayerName
     * Returns the name of the player.
     * \return a string representing the name of the player.
     */
    inline std::string getPlayerName();
};

inline bool operator<(Score & t1, Score & t2);

//implementation inline

int Score::getTime(){
    return time_;
}

std::string Score::getPlayerName(){
    return playerName_;
}

bool operator<(Score & t1, Score & t2){
    if (t1.getTime() < t2.getTime()){
        return true;
    }else{
        return false;
    }
}

#endif // SCORE_H
