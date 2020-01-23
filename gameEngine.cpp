#include "gameEngine.h"


void fruitSpawn(std::vector<std::vector<int>>& vectorObstacles, int& fruitX, int& fruitY, const int width, const int height)
 {
    srand ( time(NULL) );
    int fruitPosX = rand() % width;
    int fruitPosY = rand() % height;
    if(vectorObstacles.empty())
    {
        fruitX=fruitPosX;
        fruitY=fruitPosY;
    }
    else {
        for (size_t j = 0; j < vectorObstacles.size(); j++) { // Empêche le spawn d'obstacle sur le fruit
            if (fruitPosX != vectorObstacles.at(j).at(0) && fruitPosY != vectorObstacles.at(j).at(1)) {
                fruitX = fruitPosX;
                fruitY = fruitPosY;
            } else fruitSpawn(vectorObstacles, fruitX, fruitY, width, height);

        }
    }

}

void obstacleSpawn(const int& nbObstacles, std::vector<std::vector<int>>& vectorObstacles, int& fruitPosX, int& fruitPosY, const int width, const int height)
{
    for(unsigned i=0;i<nbObstacles;i++)
    {
        //srand ( time(NULL) );
        int obstacleX = rand() % width;
        int obstacleY = rand() % height;
            if (fruitPosX != obstacleX && fruitPosY != obstacleY) {
                vectorObstacles.push_back({obstacleX,obstacleY});
            }
            else
            {
                obstacleSpawn(nbObstacles,vectorObstacles,fruitPosX,fruitPosY,width,height);
            }
    }


}

void logic(std::vector<std::vector<int>>& vecteurObstacles, const int width,const int height, int& snakePosX, int& snakePosY, int& fruitPosX, int& fruitPosY, int& snakeSize, int tailX[], int tailY[], const eDirection direction, bool& gameover)
 {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakePosX;
    tailY[0] = snakePosY;

    for (int i = 1; i < snakeSize; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction)
    {
        case LEFT:
            snakePosX--;
            break;

        case RIGHT:
            snakePosX++;
            break;

        case UP:
            snakePosY--;
            break;

        case DOWN:
            snakePosY++;
            break;
    }

    // Test si la tête du serpent touche un bord.
    if (snakePosX > width || snakePosX < 0 || snakePosY > height || snakePosY < 0) {
        gameover = true;
    }

   // Test si le serpent se mord la queue
    for (int i = 0; i < snakeSize; i++) {
        if (tailX[i] == snakePosX && tailY[i] == snakePosY)
            gameover = true;
    }

    // Test si le serpent mange un Fruit
    if (snakePosX == fruitPosX && snakePosY == fruitPosY) {
        snakeSize++;
        fruitSpawn(vecteurObstacles,fruitPosX,fruitPosY,width,height);
    }

    // Test si le serpent touche un obstacle
     for(size_t i = 0; i < vecteurObstacles.size();i++)
     {

         if (snakePosX == vecteurObstacles.at(i).at(0) && snakePosY == vecteurObstacles.at(i).at(1))
         {
             gameover = true;
         }

     }

}