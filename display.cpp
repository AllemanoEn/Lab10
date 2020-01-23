/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : display.cpp
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Implémentation des fonctions du fichier display.h
 -----------------------------------------------------------------------------------
 */

#include "display.h"
#include "score.h"

void displayMenu(int score){
    std::cout << MENU_WELCOME << std::endl;
    std::cout << MENU_START << std::endl;
    std::cout << MENU_QUIT << std::endl;
    std::cout << MENU_INSTRUCTION << std::endl;
    std::cout << MENU_SEARCHPLAYER << std::endl;
    std::cout << MENU_HIGHSCORE << std::endl;
    std::cout << MENU_SCORE << std::to_string(score) << std::endl;
}

void displayInstructions(){
    std::cout << INSTR_UP << std::endl;
    std::cout << INSTR_LEFT << std::endl;
    std::cout << INSTR_DOWN << std::endl;
    std::cout << INSTR_RIGHT << std::endl;
    std::cout << INSTR_EXIT << std::endl;
    std::cout << INSTR_MENU << std::endl;   
}

void displayUsernameRequest(){
    cout << USERNAME_REQUEST;
}

void displayHighScore(){

    for(const auto& a : lecture(SCOREFILEPATH)){
        cout << a << endl;
    }
    
    cout << INSTR_MENU << endl;
}

void displayPlayerScore(){

    string player;
    bool UNKNOW_PLAYER = true;

    cout << "Player name : ";
    cin >> player;
    cout << endl;

    vector<string> v = lecture(SCOREFILEPATH);
    for(const auto& a : v){
        if(a.find(player)!=string::npos){
            UNKNOW_PLAYER = false;
            cout << player << "'s score is ";

            for (int i = 0; i < a.find(':'); ++i) {
                cout << a.at(i);
            }

            cout << endl;
        }
    }
    if(UNKNOW_PLAYER){
        cout << "Unknow player :(" << endl;
    }

    cout << INSTR_MENU << endl;
}

void draw(int width, int height, int snakePosX, int snakePosY, int fruitPosX, int fruitPosY, int snakeSize, int tailX[], int tailY[], std::vector<std::vector<int>>& vecteurObstacles)
 {
    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << BORDER;

            std::vector<int> coord = {j, i};

            if (i == snakePosY && j == snakePosX)
                std::cout << SNAKE_HEAD;
            else if (i == fruitPosY && j == fruitPosX)
                std::cout << FRUIT;
            else if (std::find(vecteurObstacles.begin(), vecteurObstacles.end(), coord) != vecteurObstacles.end())
                std::cout << OBSTACLE;




            else {

                bool print = false;

                for (int k = 0; k < snakeSize; k++) {

                    if (tailX[k] == j && tailY[k] == i) {

                        std::cout << SNAKE_TAIL;
                        print = true;
                    }
                }

                if (!print)
                    std::cout << " ";
            }

            if (j == width - 1)

                std::cout << BORDER;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    std::cout << ACTUAL_SCORE << snakeSize << std::endl;

}