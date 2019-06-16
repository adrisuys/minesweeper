#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "structure.h"
#include "case.h"

/*!
 * \brief The Board class
 * This class represents a board.
 */
class Board {
private:
    /*!
     * \brief the type of the board
     * BType is the type of the board. It has 2 main features :
     * - a dimension (a height and a width)
     * - a number of bomb
     */
    BoardType btype_;

    /*!
     * \brief the board itself
     * Board is a 2-dimensions-vector that contains Cases.
     */
    std::vector<std::vector<Case>> board_;

public:
    /*!
     * \brief the constructor
     * It creates an instance of the class using a predefined BoardType.
     * \param btype the type of the board.
     */
    Board(const BoardType& btype);

    /*!
     * \brief the constructor
     * It creates an instance of the class from nothing.
     */
    Board() = default;

    /*!
     * \brief the destructor
     * It deletes all the elements from Board that need to be deleted.
     */
    ~Board(){};

    /*!
     * \brief the setter of BoardType.
     * Changes the values of the BoardType with the value of the one in parameter.
     * \param btype the new BoardType from which the value are taken.
     */
    inline void setBoardType(BoardType btype);

    /*!
     * \brief the getter of BoardType.
     * Returns the BoardType.
     * \return a BoardType.
     */
    inline BoardType& getBoardType();

    /*!
     * \brief the getter of the board.
     * Returns the board.
     * \return a vector of Case.
     */
    inline std::vector<std::vector<Case>> & getBoard();

    /*!
     * \brief unveill all the cases of the board.
     * It sets to visible all the cases.
     */
    void unveilAll();

    /*!
     * \brief puts all the bombs in the board.
     * It randomly chooses X cases, X being the number of bombs, and puts a bomb on them.
     * The case defined by col and row can not contain a bomb.
     * \param col the given column.
     * \param row the given row.
     */
    void setBombsInTable(int col, int row);

    /*!
     * \brief fills all the case of the square that does not contain a bomb.
     * Those have been previously filled. So it will set the content of the different cases.
     * The content represents the number of bombs that are around those cases.
     */
    void fillBoard();

    /*!
     * \brief states if the game is won.
     * It is won if all the non-bomb cases are unveiled.
     * \return true if it is won, false otherweise.
     */
    bool isWon();

    /*!
     * \brief puts a flag on the case indicated by i and j.
     * \param i the row.
     * \param j the column.
     * \return true if the player put a flag, false if he removed it.
     */
    bool putFlag(int i, int j);

    /*!
     * \brief unveil the case indicated by i and j.
     * \param i the row.
     * \param j the column.
     * \return false if the case is a bomb, true otherwise.
     */
    bool play(int i, int j);

    /*!
     * \brief activateBonus
     * Selects randomly a case that will be unveil for the user.
     * \return the case which the computer will reveal for the user.
     */
    Case activateBonus();

private:
    bool isInsideBoard(int i, int j);
    int getNbBombAround(Case square);
    void playTurn(int i, int j);
    std::vector<Case*> getAdjacent(Case square);
    int myrandom(int i);
};

//implémentations des méthodes inline

std::vector<std::vector<Case> > &Board::getBoard(){
    return board_;
}

void Board::setBoardType(BoardType btype){
    btype_ = btype;
}

BoardType &Board::getBoardType(){
    return btype_;
}


#endif // BOARD_H
