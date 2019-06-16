#ifndef TOP_H
#define TOP_H

#include <vector>
#include "score.h"

/*!
 * \brief The Top class
 * This class represents a top. It is basically a list of the x Scores, x being a int.
 */
class Top {
private:

    /*!
     * \brief top_
     * A vector of Scores (name of the player and its time). The x best times.
     */
    std::vector<Score> top_;

    /*!
     * \brief nbScore_
     * The number of Score that can fit in a Top. If nbScore_ equals 10, it will be a Top 10, e.g.
     */
    int nbScore_;

public:

    /*!
     * \brief Top, the constructor
     * It creates an instance of the class with a predefined vector of Scores.
     * \param top a vector of Scores.
     */
    Top(std::vector<Score> top);

    /*!
     * \brief Top, the constructor
     * It creates an instance of the class from nothing.
     */
    Top();

    /*!
     * \brief the destructor
     * It deletes all the elements from the class that need to be deleted.
     */
    ~Top(){};

    /*!
     * \brief addScore
     * Adds a Score into the vector. Before doing this, the methods verify if the Score to be added can fit in
     * the vector. If the time of the new Score is faster (smaller) than the fifth time, the Score is added; else,
     * nothing is done.
     * \param score the new Score that has to be verified and then added, accordingly.
     */
    void addScore(Score score);

    /*!
     * \brief getListScore
     * Returns a copy of the vector top_.
     * \return a copy of the vector top_.
     */
    std::vector<Score> getListScore();

private:
    bool fitsInHoF(Score score);
};



#endif // TOP_H
