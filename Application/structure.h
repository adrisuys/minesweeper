#ifndef STRUCTURE_H
#define STRUCTURE_H

/*!
 * \brief Dimension, the dimension of the board.
 * A dimension is composed of an height and a width.
 */
typedef struct Dimension {

    /*!
     * \brief height
     * the height of the board.
     */
    int height;

    /*!
     * \brief width
     * the width of the board.
     */
    int width;

    /*!
     * \brief operator =
     * Assigns the value of a Dimension to a new one.
     * \param a the Dimension we take the value from.
     * \return a new Dimension, that has the same value as the other one.
     */
    Dimension& operator=(const Dimension& a){
        height=a.height;
        width=a.width;
        return *this;
    }

    /*!
     * \brief operator <
     * Verifies if a Dimension is smaller than another.
     * \param a the Dimension the current Dimension is compared to.
     * \return true if the Dimension is smaller, false otherwise.
     */
    bool operator<(const Dimension& r ) const
    {
        if ( height < r.height )  return true;
        if ( height > r.height )  return false;

        // Otherwise a are equal
        if ( width < r.width )  return true;
        if ( width > r.width )  return false;

        // Otherwise both are equal
        return false;
    }

    /*!
     * \brief operator >
     * Verifies if a Dimension is greater than another.
     * \param a the Dimension the current Dimension is compared to.
     * \return true if the Dimension is greater, false otherwise.
     */
    bool operator>(const Dimension& r ) const
    {
        if ( height > r.height )  return true;
        if ( height < r.height )  return false;

        // Otherwise a are equal
        if ( width > r.width )  return true;
        if ( width < r.width )  return false;

        // Otherwise both are equal
        return false;
    }

    /*!
     * \brief operator ==
     * Verifies if two Dimensions have the same values.
     * \param a the Dimension the current Dimension is compared to.
     * \return true if the Dimension are equals, false otherwise.
     */
    bool operator==(const Dimension& dim) {
        return height == dim.height && width == dim.width;
    }

} Dimension;


/*!
 * \brief Coordinates, the coordinates of a case.
 * The coordinates of the case is composed of a x-axis value, row, and a y-axis value, column
 * Theses are used to localize the cases in the board.
 */
typedef struct Coordinates {

    /*!
     * \brief row
     * the row of a case
     */
    int row;

    /*!
     * \brief col
     * the column of a case
     */
    int col;

    /*!
     * \brief operator =
     * Assigns the value of a Coordinates to a new one.
     * \param a the Coordinates we take the value from.
     * \return a new Coordinates, that has the same value as the other one.
     */
    Coordinates& operator=(const Coordinates& a){
        row=a.row;
        col=a.col;
        return *this;
    }

} Coordinates;


/*!
 * \brief BoardType
 * A BoardType is composed of a Dimension and a number of bombs.
 */
typedef struct BoardType {

    /*!
     * \brief dimension
     * The dimension of the board.
     */
    Dimension dimension;

    /*!
     * \brief nbBomb
     * The number of bombs that are in the board.
     */
    int nbBomb;

    /*!
     * \brief operator =
     * Assigns the value of a BoardType to a new one.
     * \param a the BoardType we take the value from.
     * \return a new BoardType, that has the same value as the other one.
     */
    BoardType& operator=(const BoardType& a){
        dimension=a.dimension;
        nbBomb=a.nbBomb;
        return *this;
    }

    /*!
     * \brief operator <
     * Verifies if a BoardType is smaller than another.
     * \param a the BoardType the current Dimension is compared to.
     * \return true if the BoardType is smaller, false otherwise.
     */
    bool operator<(const BoardType& r ) const
    {
        if ( dimension < r.dimension )  return true;
        if ( dimension > r.dimension )  return false;

        // Otherwise a are equal
        if ( nbBomb < r.nbBomb )  return true;
        if ( nbBomb > r.nbBomb )  return false;

        // Otherwise both are equal
        return false;
    }

    /*!
     * \brief operator >
     * Verifies if a BoardType is greater than another.
     * \param a the BoardType the current Dimension is compared to.
     * \return true if the BoardType is greater, false otherwise.
     */
    bool operator>(const BoardType& r )
    {
        if ( dimension > r.dimension )  return true;
        if ( dimension < r.dimension )  return false;

        // Otherwise a are equal
        if ( nbBomb > r.nbBomb )  return true;
        if ( nbBomb < r.nbBomb )  return false;

        // Otherwise both are equal
        return false;
    }

    /*!
     * \brief operator ==
     * Verifies if two BoardType have the same values.
     * \param a the BoardType the current Dimension is compared to.
     * \return true if the BoardType are equals, false otherwise.
     */
    bool operator==(const BoardType& board) {
        return dimension == board.dimension && nbBomb == board.nbBomb;
    }
} BoardType;

#endif // STRUCTURE_H
