#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "board.cpp"
#include "case.cpp"
#include "controller.cpp"
#include "game.cpp"
#include "halloffame.cpp"
#include "score.cpp"
#include "top.cpp"
#include "view.cpp"
#include "board.h"
#include "case.h"
#include "controller.h"
#include "game.h"
#include "halloffame.h"
#include "score.h"
#include "top.h"
#include "view.h"

using namespace std;

TEST_CASE("Test of class Top"){
    /*SECTION("method fitsInHoF(Score score)"){
        Score s1 {"Jean",50};
        Score s2 {"Marc",67};
        Score s3 {"Jean-Jass",54};
        Score s4 {"Caba",73};
        Score s5 {"Romeo",52};
        vector<Score> v {s1,s2,s3,s4,s5};
        Top top{v};

        Score sa {"Amza", 87};
        bool valid = top.fitsInHoF(sa);
        REQUIRE(valid == false);

        Score sc {"Amza", 30};
        valid = top.fitsInHoF(sb);
        REQUIRE(valid == true);

        Score sc {"Amza", 73};
        valid = top.fitsInHoF(sc);
        REQUIRE(valid == false);
    }*/

    SECTION("method addScore(Score score) --> notOk"){
        Top t{};
        Score s1 {"Jean",50};
        Score s2 {"Marc",67};
        Score s3 {"Jean-Jass",54};
        Score s4 {"Caba",73};
        Score s5 {"Romeo",52};
        t.addScore(s1);
        t.addScore(s2);
        t.addScore(s3);
        t.addScore(s4);
        t.addScore(s5);

        Score sa {"Amza", 87};
        REQUIRE_THROWS(t.addScore(sa));
        REQUIRE(t.getListScore()[0].getPlayerName() == "Jean");
        REQUIRE(t.getListScore()[0].getTime() == 50);
        REQUIRE(t.getListScore()[1].getPlayerName() == "Romeo");
        REQUIRE(t.getListScore()[1].getTime() == 52);
        REQUIRE(t.getListScore()[2].getPlayerName() == "Jean-Jass");
        REQUIRE(t.getListScore()[2].getTime() == 54);
        REQUIRE(t.getListScore()[3].getPlayerName() == "Marc");
        REQUIRE(t.getListScore()[3].getTime() == 67);
        REQUIRE(t.getListScore()[4].getPlayerName() == "Caba");
        REQUIRE(t.getListScore()[4].getTime() == 73);
    }

    SECTION("method addScore(Score score) --> ok"){
        Top t{};
        Score s1 {"Jean",50};
        Score s2 {"Marc",67};
        Score s3 {"Jean-Jass",54};
        Score s4 {"Caba",73};
        Score s5 {"Romeo",52};
        t.addScore(s1);
        t.addScore(s2);
        t.addScore(s3);
        t.addScore(s4);
        t.addScore(s5);
        Score sa {"Amza", 72};
        t.addScore(sa);
        REQUIRE((t.getListScore()[0].getPlayerName().compare("Jean") == 0));
        REQUIRE(t.getListScore()[0].getTime() == 50);
        REQUIRE(t.getListScore()[1].getPlayerName().compare("Romeo") == 0);
        REQUIRE(t.getListScore()[1].getTime() == 52);
        REQUIRE(t.getListScore()[2].getPlayerName().compare("Jean-Jass") == 0);
        REQUIRE(t.getListScore()[2].getTime() == 54);
        REQUIRE(t.getListScore()[3].getPlayerName().compare("Marc") == 0);
        REQUIRE(t.getListScore()[3].getTime() == 67);
        REQUIRE(t.getListScore()[4].getPlayerName().compare("Amza") == 0);
        REQUIRE(t.getListScore()[4].getTime() == 72);
    }
}

/*TEST_CASE("Test of class Controller"){
    SECTION("methode toInt(string str)"){
        string str1 = "un";
        string str2 = "1";
        View view{};
        Controller ctrl{view};
        REQUIRE_THROWS(ctrl.toInt(str1));
        int nb = ctrl.toInt(str2);
        REQUIRE(nb == 1);
    }

    SECTION("methode validateCmd(vector<string> cmd)"){
        vector<string> v1 {"play","1","2"};
        vector<string> v5 {"flag","1","2"};
        vector<string> v2 {"play","1"};
        vector<string> v3 {"flag","un","2"};
        vector<string> v4 {"play","1","deux"};
        View view{};
        Controller ctrl{view};
        REQUIRE(ctrl.validateCmd(v1) == true);
        REQUIRE(ctrl.validateCmd(v2) == false);
        REQUIRE(ctrl.validateCmd(v3) == false);
        REQUIRE(ctrl.validateCmd(v4) == false);
        REQUIRE(ctrl.validateCmd(v5) == true);
    }
}*/

//TEST_CASE("Test of class View"){
    /*SECTION("methode splitString(string str)"){
        string str1 = "salut les gars";
        vector<string> v1 = splitString(str1);
        bool valid1 = v1[0].compare("salut");
        bool valid2 = v1[1].compare("les");
        bool valid3 = v1[2].compare("gars");
        REQUIRE(valid1 == true);
        REQUIRE(valid2 == true);
        REQUIRE(valid3 == true);

        string str2 = "salutlesgars";
        vector<string> v2 = splitString(str1);
        bool valid = v1[0].compare("salutlesgars");
        REQUIRE(valid == true);
    }*/

    /*SECTION("methode toUpperCase(string s"){
        string str1 = "play my game.. C'est CoOl";
        string str2 = tpUpperCase(str1);
        bool valid = str2.compare("PLAY MY GAME.. C'EST COOL");
        REQUIRE (valid == true);
    }*/

/*
    SECTION("methode isPlayCommand(vector<string> cmd)"){
        Game g{10,10,10};
        Game* pg = &g;
        View v{pg};
        vector<string> v1 {"play", "1", "2"};
        vector<string> v2 {"PlAy", "1", "2"};
        vector<string> v3 {"hide", "1", "2"};
        vector<string> v4 {"play", "1"};
        vector<string> v5 {"1", "play", "1"};
        vector<string> v6 {"play", "1", "z"};
        REQUIRE(v.isPlayCommand(v1) == true);
        REQUIRE(v.isPlayCommand(v2) == true);
        REQUIRE(v.isPlayCommand(v3) == false);
        //REQUIRE(v.isPlayCommand(v4) == false);
        REQUIRE(v.isPlayCommand(v5) == false);
        REQUIRE(v.isPlayCommand(v6) == false);
    }

    SECTION("methode isFlagCommand(vector<string> cmd)"){
        Game g{10,10,10};
        Game* pg = &g;
        View v{pg};
        vector<string> v1 {"flag", "1", "2"};
        vector<string> v2 {"Flag", "1", "2"};
        vector<string> v3 {"hide", "1", "2"};
        vector<string> v4 {"1", "flag", "1"};
        vector<string> v5 {"flag", "1", "z"};
        REQUIRE(v.isFlagCommand(v1) == true);
        REQUIRE(v.isFlagCommand(v2) == true);
        REQUIRE(v.isFlagCommand(v3) == false);
        REQUIRE(v.isFlagCommand(v4) == false);
        REQUIRE(v.isFlagCommand(v5) == false);
    }

    SECTION("methode isExitCommand(vector<string> cmd)"){
        Game g{10,10,10};
        Game* pg = &g;
        View v{pg};
        vector<string> v1 {"exit"};
        vector<string> v2 {"ExIT"};
        vector<string> v3 {"hide", "1", "2"};
        vector<string> v4 {"exit", "1"};
        vector<string> v5 {"exits"};
        vector<string> v6 {" ", "exits"};
        REQUIRE(v.isExitCommand(v1) == true);
        REQUIRE(v.isExitCommand(v2) == true);
        REQUIRE(v.isExitCommand(v3) == false);
        REQUIRE(v.isExitCommand(v4) == false);
        REQUIRE(v.isExitCommand(v5) == false);
        REQUIRE(v.isExitCommand(v6) == false);
    }
}
*/

TEST_CASE("Test of class Board") {
    SECTION("Méthode unveilAll") {
        bool allUnveil(true);
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};
        board.unveilAll();

        for(int i = 0; i < boardType.dimension.height;i++) {
            for (int j = 0; j < boardType.dimension.width;j++) {
                if (!board.getBoard()[i][j].isVisible()) {
                    allUnveil = false;
                }
            }
        }

        REQUIRE(allUnveil == true);
    }

    SECTION("Méthode fillBoard") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};
        board.getBoard()[2][2].putBomb();
        board.getBoard()[2][4].putBomb();

        board.fillBoard();

        REQUIRE(board.getBoard()[3][3].getContent()==2);
        REQUIRE(board.getBoard()[1][2].getContent()==1);
        REQUIRE(board.getBoard()[3][4].getContent()==1);
    }

    SECTION("Méthode fillBoard") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};
        board.getBoard()[2][2].putBomb();
        board.getBoard()[2][3].putBomb();
        board.getBoard()[3][3].putBomb();
        board.getBoard()[4][3].putBomb();
        board.getBoard()[4][2].putBomb();
        board.getBoard()[4][1].putBomb();
        board.getBoard()[3][1].putBomb();
        board.getBoard()[2][1].putBomb();

        board.fillBoard();

        REQUIRE(board.getBoard()[3][2].getContent()==8);
        REQUIRE(board.getBoard()[0][0].getContent()==0);
    }

    SECTION("Méthode setBombInTable") {
        int nbBomb(0);
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};
        board.setBombsInTable(2,2);

        for(int i = 0; i < boardType.dimension.height;i++) {
            for (int j = 0; j < boardType.dimension.width;j++) {
                if (board.getBoard()[i][j].isBomb()) {
                    nbBomb++;
                }
            }
        }

        REQUIRE(nbBomb==3);
    }

    SECTION("Méthode putFlag") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};

        board.putFlag(2,2);
        board.putFlag(4,4);

        REQUIRE(board.getBoard()[2][2].isFlag()==true);
        REQUIRE(board.getBoard()[4][4].isFlag()==true);
    }

    SECTION("Méthode play") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};

        board.getBoard()[1][1].putBomb();
        board.play(2,2);
        board.play(4,4);

        REQUIRE(board.getBoard()[2][2].isVisible());
        REQUIRE(board.getBoard()[4][4].isVisible());
        REQUIRE(board.play(3,3)==true);
        REQUIRE(board.play(1,1)==false);
        //REQUIRE_THROWS(board.play(6,6));
    }

    SECTION("Méthode isWon OK") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};

        board.getBoard()[2][4].putBomb();

        for(int i = 0; i < boardType.dimension.height;i++) {
            for (int j = 0; j < boardType.dimension.width;j++) {
                if (!(i == 2 && j ==4)) {
                    board.getBoard()[i][j].unveil();
                }
            }
        }

        REQUIRE(board.isWon()==true);
    }

    SECTION("Méthode isWon NOT OK") {
        Dimension d{5,5};
        BoardType boardType{d,3};
        Board board{boardType};

        board.getBoard()[2][4].putBomb();
        board.getBoard()[3][3].unveil();

        REQUIRE(board.isWon()==false);
    }

    /*SECTION("Méthode isInsideBoard") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        REQUIRE(board.isInsideBoard(1,3)==true);
        REQUIRE(board.isInsideBoard(7,3)==false);
        REQUIRE(board.isInsideBoard(7,7)==false);
        REQUIRE(board.isInsideBoard(2,9)==false);
    }*/

    /*SECTION("Méthode getNbBombAround") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        board.getBoard()[2][2].putBomb();
        board.getBoard()[3][3].putBomb();
        board.getBoard()[4][3].putBomb();

        REQUIRE(board.getNbBombAround(board.getBoard()[3][2])==3);
        REQUIRE(board.getNbBombAround(board.getBoard()[0][4])==0);
    }*/

    /*SECTION("Méthode playTurn") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        bool isCorrect(true);

        board.getBoard()[1][1].putBomb();
        board.playTurn(4,4);

        for(int i = 0; i < boardType.dimension.height;i++) {
            for (int j = 0; j < boardType.dimension.width;j++) {
                if (!(i == 1 && j ==1)) {
                    isCorrect = board.getBoard()[i][j].isVisible();
                }
            }
        }

        REQUIRE(isCorrect==true);
    }*/

    /*SECTION("Méthode playTurn") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        bool isCorrect(true);

        board.getBoard()[1][1].putBomb();
        board.playTurn(0,0);

        for(int i = 0; i < boardType.dimension.height;i++) {
            for (int j = 0; j < boardType.dimension.width;j++) {
                if (!(i ==0 && j ==0)) {
                    isCorrect = !board.getBoard()[i][j].isVisible();
                }
            }
        }

        REQUIRE(isCorrect==true);
    }*/

    /*SECTION("Méthode getAdjacent") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        bool isEquals(true);

        vector<Case*> adjacents;
        vector<Case*> supposedAdjactents;

        adjacents.push_back(&(board.getBoard()[1][2]));
        adjacents.push_back(&(board.getBoard()[2][2]));
        adjacents.push_back(&(board.getBoard()[3][2]));
        adjacents.push_back(&(board.getBoard()[3][1]));
        adjacents.push_back(&(board.getBoard()[3][0]));
        adjacents.push_back(&(board.getBoard()[2][0]));
        adjacents.push_back(&(board.getBoard()[1][0]));
        adjacents.push_back(&(board.getBoard()[1][1]));

        supposedAdjactents = board.getAdjacent(board.getBoard()[2][1]);

        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});
        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});

        if (adjacents.size() == supposedAdjactents.size()) {
            for (int i = 0; i < adjacents.size(); i++) {
                if(!(adjacents[i] == supposedAdjactents[i])) {
                    isEquals = false;
                }
            }
        } else {
            isEquals = false;
        }
    }*/

    /*SECTION("Méthode getAdjacent1") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        bool isEquals(true);

        vector<Case*> adjacents;
        vector<Case*> supposedAdjactents;

        adjacents.push_back(&(board.getBoard()[1][0]));
        adjacents.push_back(&(board.getBoard()[1][1]));
        adjacents.push_back(&(board.getBoard()[2][1]));
        adjacents.push_back(&(board.getBoard()[3][1]));
        adjacents.push_back(&(board.getBoard()[3][0]));

        supposedAdjactents = board.getAdjacent(board.getBoard()[2][0]);

        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});
        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});

        if (adjacents.size() == supposedAdjactents.size()) {
            for (int i = 0; i < adjacents.size(); i++) {
                if(!(adjacents[i] == supposedAdjactents[i])) {
                    isEquals = false;
                }
            }
        } else {
            isEquals = false;
        }
    }*/

    /*SECTION("Méthode getAdjacent2") {
        BoardType boardType(Dimension(5,5),3);
        Board board{boardType};

        bool isEquals(true);

        vector<Case*> adjacents;
        vector<Case*> supposedAdjactents;

        adjacents.push_back(&(board.getBoard()[4][1]));
        adjacents.push_back(&(board.getBoard()[3][1]));
        adjacents.push_back(&(board.getBoard()[3][0]));

        supposedAdjactents = board.getAdjacent(board.getBoard()[4][0]);

        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});
        sort(supposedAdjactents.begin(), supposedAdjactents.end(), [](Case* a, Case * b) -> bool{return a < b;});

        if (adjacents.size() == supposedAdjactents.size()) {
            for (int i = 0; i < adjacents.size(); i++) {
                if(!(adjacents[i] == supposedAdjactents[i])) {
                    isEquals = false;
                }
            }
        } else {
            isEquals = false;
        }
    }*/
}

TEST_CASE("Test of class Game") {
    SECTION("Méthode init") {
        Game game(9,9,10);
        game.init(1,2);

        REQUIRE(game.isInstantiated()== true);

    }
}
