#ifndef CASE_H
#define CASE_H
#include "structure.h"
#include <iostream>

/*!
 * \brief The Case class
 * It represents a case of the board.
 */
class Case {
private:

    /*!
     * \brief The coordinates of a case is represented by its abscissa X and its ordinate Y.
     */
    Coordinates coordinates_;

    /*!
     * \brief flag_ A boolean indicating if a flag is put on the case.
     */
    bool flag_;

    /*!
     * \brief visible_ A boolean indicating if the case is unveiled.
     */
    bool visible_;

    /*!
     * \brief content_ A int representing the number of bombs that are around the case (0 to 8).
     */
    int content_;

    /*!
     * \brief bomb_ A boolean indicating if there is a bomb on the case.
     */
    bool bomb_;

public:

    /*!
     * \brief The constructor
     * It creates an instance of the class with predefined coordinates.
     * \param coordinates the given coordinates.
     */
    Case(Coordinates coordinates);

    /*!
     * \brief The constructor
     * It creates an instance of the class from nothing.
     */
    Case() = default;

    /*!
     * \brief The destructor
     * It deletes all the element from the class that need to be deleted.
     */
    ~Case(){};

    /*!
     * \brief returns the coordinates from the case
     * \return a Coordinates structure that contains tow int, a X and a Y.
     */
    inline Coordinates& getCoordinates();

    /*!
     * \brief isVisible indicating if a case is unveiled or not.
     * \return true if the case is unveiled, false otherwise.
     */
    inline bool isVisible();

    /*!
     * \brief isFlag indicating if a case has a flag on it.
     * \return true if the case contains a flag, false otherwise.
     */
    inline bool isFlag();

    /*!
     * \brief isBomb indicating if a case has a bomb on it.
     * \return true if the case contains a bomb, false otherwise.
     */
    inline bool isBomb();

    /*!
     * \brief unveil unveil a case, set the attribute visible to true.
     */
    inline void unveil();

    /*!
     * \brief putFlag put a flag on a case. Set the attribute flag to true.
     */
    inline void putFlag();

    /*!
     * \brief removeFlag remove the flag on a case. Set the attribute flag to false.
     */
    inline void removeFlag();

    /*!
     * \brief putBomb put a bomb on a case. Set the attribute bomb to true.
     */
    inline void putBomb();

    /*!
     * \brief setContent set the content of a case. Calculates the number of bombs around the case and set the value to the case.
     * \param content an int value representing the number of bombs around the case.
     */
    inline void setContent(int content);

    /*!
     * \brief getContent returns the content of a case.
     * \return an int representing the number of bombs that are around the case.
     */
    inline int getContent();
};

//implementation méthode inline

Coordinates& Case::getCoordinates(){
    return coordinates_;
}

bool Case::isVisible(){
    return visible_;
}

bool Case::isFlag(){
    return flag_;
}

bool Case::isBomb(){
    return bomb_;
}

void Case::unveil(){
    visible_ = true;
}

void Case::putFlag(){
    flag_ = true;
}

void Case::removeFlag(){
    flag_ = false;
}

void Case::putBomb(){
    bomb_ = true;
}

void Case::setContent(int content){
    content_ = content;
}

int Case::getContent(){
    return content_;
}

#endif // CASE_H
