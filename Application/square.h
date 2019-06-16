#ifndef SQUARE_H
#define SQUARE_H

#include <QStackedWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

using namespace std;

/*!
 * \brief The Square class
 * It represents a graphical case. It is actually a QLabel that contains a image.
 */
class Square : public QLabel {
    private :
        int row_;
        int column_;
    public :
        /*!
         * \brief Square, the constructor
         * Creates an instance of the class.
         * \param column the column of the QGridLayout it is contained in.
         * \param row the row of the QGridLayout it is contained in.
         */
        Square(int column, int row);

        /*!
         * \brief ~Square, the destructor.
         * Destroy all the elements of the class that need to be.
         */
        ~Square() = default;

        /*!
         * \brief setImg
         * Sets an image as Pixmap of the QLabel
         * \param path the relative path to the image.
         */
        void setImg(string path);

        /*!
         * \brief getRow
         * Returns the row of the QGridLayout the Square is in.
         * \return an int, the row.
         */
        inline int getRow();

        /*!
         * \brief getCol
         * Returns the column of the QGridLayout the Square is in.
         * \return an int, the column.
         */
        inline int getCol();
};

int Square::getCol(){
    return column_;
}

int Square::getRow(){
    return row_;
}

#endif // SQUARE_H
