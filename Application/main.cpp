#include "guiscreen.h"
#include <QApplication>

using namespace std;

int main (int argc, char *argv[])
{
    QApplication a(argc,argv);
    //View view{};
    GUIScreen gui{};
    Controller control;
    //Game game{};
    //view.setController(&control);
    gui.setController(&control);
    // lancement du premier "écran" --- demande du pseudo
    //view.initName();
    // lancement du deuxième "écran" --- demande des settings pour le board
    //game = view.initGame();

    //game.registerObservers(&view);
    //control.setGame(&game);
    //view.setGame(&game);
    //view.playDemineur();
    gui.show();
    return a.exec();
}
