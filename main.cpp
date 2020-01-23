/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : main.cpp
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Implémentation d'un jeu de snake en console
 Sources     : https://code.sololearn.com/c8ubSKG6fX73/#cpp
 -----------------------------------------------------------------------------------
 */

#include <string>


#include "sysFunc.h"
#include "display.h"
#include "gameEngine.h"
#include "score.h"

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const int START_POS_X_SNAKE = WIDTH / 2;
const int START_POS_Y_SNAKE = HEIGHT / 2;
const int SPEED = 500000;
const int NBOBSTACLES = 3;

/**
* @brief Fonction affichant le menu et supprimant l'affichage du terminal.
* @param score score actuel du joueur.
*/
void restart(int score);

/**
* @brief Fonction affichant le menu d'instructions et supprimant l'affichage du terminal.
* Cette fonction permet aussi de quitter le menu d'instructions.
* @param score score actuel du joueur.
*/
void getInstructions(int score);

/**
* @brief Fonction pour ajouter les scores du joueur.
*/
void setNewScore(int score);

/**
* @brief Fonction affichant les scores du meilleurs au moins bon et en supprimant l'affichage du terminal.
* Cette fonction permet aussi de quitter ce menu.
*/
void getHighScore(int score);

/**
* @brief Fonction affichant le score d'un joueur donné et en supprimant l'affichage du terminal.
* Cette fonction permet aussi de quitter ce menu.
*/
void getPlayerScore(int score);

/**
* @brief Fonction faisant la traduction entre la direction entrée par l'utilisateur et la direction du serpent.
* @param direction direction proposée par l'utilisateur
* @param oldDirection Direction actuelle du serpent
* @param gameover [out] définis si l'utilisateur arrête la partie.
* @return nouvelle direction du serpent.
*/
eDirection manageDirection(char direction, eDirection oldDirection, bool& gameover);

/**
* @brief Fonction remettant les variables de jeu par défaut.
* @param posSnakeX [out] position X de la tête du serpent.
* @param posSnakeY [out] position Y de la tête du serpent.
* @param direction [out] direction initiale du serpent.
* @param gameover [out] définis si le joueur arrête ou perd la partie.
*/
void reload(int& posSnakeX, int& posSnakeY, int& length, eDirection& direction, bool& gameover);

int main()
 {
    // CONFIGURATIONS VARIABLES
    bool gameover = false;
    bool shutDown = false;
    int tailX[400], tailY[400];
    char actualDirection = KEY_UP;
    vector<vector<int>> vecteurObstacles;

    int posSnakeX;
    int posSnakeY;
    int snakeSize;
    eDirection dir;
    reload(posSnakeX, posSnakeY, snakeSize, dir, gameover);

    int posFruitX;
    int posFruitY;
    fruitSpawn(vecteurObstacles,posFruitX,posFruitY, WIDTH, HEIGHT);

    obstacleSpawn(NBOBSTACLES,vecteurObstacles, posFruitX, posFruitY, WIDTH, HEIGHT);

    // BOUCLE DU MENU.
    do {
        restart(snakeSize);

        string input;
        cin >> input;
        if (input.at(0) == KEY_START)
        {
            reload(posSnakeX, posSnakeY, snakeSize, dir, gameover);

            // BOUCLE DE JEU
            while (!gameover) {

                clearScreen();

                // dessine le pleateau de jeu
                draw(WIDTH, HEIGHT, posSnakeX, posSnakeY, posFruitX, posFruitY, snakeSize, tailX, tailY,vecteurObstacles);

                // detecte une entrée sur le clavier et récupère le charactère.
                char newDirection;
                if (kbhit()) {
                    newDirection = getch();
                }
                if ((newDirection != actualDirection)) {
                    actualDirection = newDirection;
                }

                // Convertis la direction donnée par l'utilisateur pour le serpent.
                dir = manageDirection(actualDirection, dir, gameover);

                // Ordonne le mouvement au serpent et définis si il meurt.
                logic(vecteurObstacles,WIDTH, HEIGHT, posSnakeX, posSnakeY, posFruitX, posFruitY, snakeSize, tailX, tailY, dir, gameover);

                // met en pause le système définissant la vitesse du serpent.
                mySleep(SPEED);
            }

            // Enregistrer le score du joueur
            setNewScore(snakeSize);
        }
        // test si on souhaite afficher le menu
        else if (input.at(0) == KEY_INSTRUCTION)
            getInstructions(snakeSize);
        // test si on souhaite arrêter de jouer.
        else if (input.at(0) == KEY_QUIT)
            shutDown = true;
        else if (input.at(0) == KEY_SEARCHPLAYER){
            getPlayerScore(snakeSize);
        }
        else if (input.at(0) == KEY_HIGHSCORE)
            getHighScore(snakeSize);

    } while (shutDown == false);
    return 0;
}

void restart(int score)
 {
    clearScreen();
    displayMenu(score);
}

void getInstructions(int score)
 {
    clearScreen();
    displayInstructions();

    string input;
    cin >> input;
    if (input.at(0) == KEY_MENU)
        restart(score);
}

void setNewScore(int score)
{
    clearScreen();
    displayUsernameRequest();

    string username;
    cin >> username;

    insertScore(to_string(score), username, SCOREFILEPATH);
}

void getHighScore(int score)
{
    clearScreen();
    displayHighScore();

    string input;
    cin >> input;
    if (input.at(0) == KEY_MENU)
        restart(score);
}

void getPlayerScore(int score)
{
    clearScreen();
    displayPlayerScore();

    string input;
    cin >> input;
    if (input.at(0) == KEY_MENU)
        restart(score);
}

eDirection manageDirection(char direction, eDirection oldDirection, bool& gameover)
 {
    eDirection dir;
    bool error = false;
    switch (direction)
    {
        case KEY_LEFT:
            dir = LEFT;
            break;

        case KEY_UP:
            dir = UP;
            break;

        case KEY_DOWN:
            dir = DOWN;
            break;

        case KEY_RIGHT:
            dir = RIGHT;
            break;

        case KEY_QUIT:
            dir = STOP;
            gameover = true;
            break;
        default:
            dir=oldDirection;
            break;
    }
    return dir;
}

void reload(int& posSnakeX, int& posSnakeY, int& length, eDirection& direction, bool& gameover){
    posSnakeX = START_POS_X_SNAKE;
    posSnakeY = START_POS_Y_SNAKE;
    length = 0;
    direction = UP;
    gameover=false;
}
