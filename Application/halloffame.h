#ifndef HALLOFFAME_H
#define HALLOFFAME_H

#include <map>
#include "structure.h"
#include "top.h"

/*!
 * \brief The HallOfFame class
 * Represents all the top 5 for all the different type of board.
 * For each triplet (height, width, nbBombs), there is a top5.
 */
class HallOfFame {

private:

    /*!
     * \brief scores_ a map which has, as key, a BoardType and, as value, a Top.
     */
    std::map<BoardType,Top*> scores_;
public:

    /*!
     * \brief HallOfFame
     * It creates an instance of the class from nothing.
     */
    HallOfFame();

    /*!
     * \brief The destructor
     * Deletes all the elements from the class that need to be deleted.
     */
    ~HallOfFame(){};

    /*!
     * \brief initMapScore
     * Read all the data (height, width, nbBombs, name of player, time (for 1 game)) in a file (.txt)
     * Copy them all into scores, a map, the attribute of the class.
     */
    void initMapScore();

    /*!
     * \brief addScore
     * Adds a Score (structure composed of the name of the player and its time) into the map.
     * \param boardType The BoardType (height, width and nbBombs of the board)
     * \param score the Score (name and time).
     */
    void addScore(const BoardType& boardType, const Score& score);

    /*!
     * \brief getTop
     * Returns the top (list of 5 bests times) for a given BoardType.
     * \param boardType the BoardType.
     * \return a vector of Score, the top 5 linked to the given BoardType.
     */
    std::vector<Score> getTop(const BoardType& boardType);

    /*!
     * \brief getTop
     * Returns the top (list of 5 bests times) for a given index.
     * \param index The index of the top in the map.
     * \return a vector of Score, the top 5 linked to the given index.
     */
    std::vector<Score> getTop(int index);

    /*!
     * \brief writeFile
     * Writes into a file the content of the map. We do that in order to save the scores and then keep an history of
     * the best scores.
     */
    void writeFile();
    /*!
     * \brief getKeys
     * Get all the boardtype on which it exists a top.
     * \return All the boardType on which it exists a top.
     */
    std::vector<std::string> getKeys();
private:
    int getHeight(std::vector<std::string>splitScoreLine);
    int getWidth(std::vector<std::string>splitScoreLine);
    int getNbBomb(std::vector<std::string>splitScoreLine);
    std::string getName(std::vector<std::string>splitScoreLine);
    int getTime(std::vector<std::string>splitScoreLine);
    void putInMap(const BoardType& Boardtype, const Score& score);
    std::vector<std::string>splitString(std::string sentence);
    bool checkScoreLine(std::vector<std::string> scoreLine);
    bool isConvertibleToInt(std::string str);
};

#endif // HALLOFFAME_H
