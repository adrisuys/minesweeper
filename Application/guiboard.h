#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QGridLayout>
#include <square.h>
#include "game.h"

/*!
 * \brief The GUIBoard class
 * Represents a board graphically.
 */
class GUIBoard : public QGridLayout{
private:
    void updateLine(int line, Game* game);
    void updateEndGameLine(int line, Game* game);
public:
    /*!
     * \brief GUIBoard
     * Build a new GUI Board.
     * \param row The number of row.
     * \param col The number of column.
     */
    GUIBoard(int row, int col);

    ~GUIBoard() = default;

    /*!
     * \brief refreshBoard
     * Update the board with a given game.
     * \param game The game the board has to print.
     */
    void refreshBoard(Game* game);

    /*!
     * \brief refreshBoardEndGame
     * Updates the board by checking if the player had put a flag on a bomb.
     * If so, a special image of a crossed bomb is put in the case.
     * \param game The game the board has to print.
     */
    void refreshBoardEndGame(Game* game);
};

#endif // GUIBOARD_H
