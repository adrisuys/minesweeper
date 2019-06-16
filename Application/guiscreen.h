#ifndef GUISCREEN_H
#define GUISCREEN_H

#include <QWidget>
#include "controller.h"
#include "guiboard.h"

namespace Ui {
    class GUIScreen;
}
/*!
 * \brief The GUIScreen class
 * Represents a MineSweeper application.
 */
class GUIScreen : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief GUIScreen
     * Build a new MineSweeper application.
     * \param parent
     */
    explicit GUIScreen(QWidget *parent = 0);
    ~GUIScreen();
    /*!
     * \brief setController
     * Set the controller for the application.
     * \param controller The new controller.
     */
    void setController(Controller* controller);
private:
    Ui::GUIScreen *ui;
    QTimer *timer;
    GUIBoard *board;
    Controller* controller_;
    Game* game_;

    void goToPlayScreen();
    void goToInitScreen();
    void goBackToInitScreen();
    void goToStatScreen();
    void refreshHoF();
    void clearScoreBoard();
    void launchTimer();
    void stopTimer();
    void initTime();
    void initMineSweeperTitle();
    void update();
    void connectWidgetsToMethods();
    void generateBoard(int height, int width);
    void launchAlertBox(string msg);

private slots:
    void initName();
    void initGame();
    void exitMinesWeeper();
    void launchGame(int height, int width, double nbBombs);
    void launchDefaultGame();
    void useBonus();
    void printScore();
    void showTime();
    void mousePressEvent(QMouseEvent *event);
};

#endif // GUISCREEN_H
