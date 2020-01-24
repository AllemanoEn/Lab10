#include "gameEngine.h"


void fruitSpawn(const std::vector<std::vector<int>>& vectorObstacles, int& fruitX, int& fruitY, const int width, const int height)
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
            bool SameValues = false;
            //Tant que la position X,Y est trouvée dans le vecteur, on en régénère une.
            do
            {
                int fruitPosX = rand() % width;
                int fruitPosY = rand() % height;
                std::vector<int> positions = {{fruitPosX,fruitPosY}};
                if(std::find(vectorObstacles.begin(),vectorObstacles.end(), positions) != vectorObstacles.end())
                {
                    SameValues = true;
                }

            } while (!SameValues);
            fruitX = fruitPosX;
            fruitY = fruitPosY;

        }
    //}

}

void obstacleSpawn(const int nbObstacles, std::vector<std::vector<int>>& vectorObstacles, int& fruitPosX, int& fruitPosY, const int width, const int height)
{

    for(unsigned i=0;i<nbObstacles;i++)
    {
        int obstacleX = rand() % width;
        int obstacleY = rand() % height;
            if (fruitPosX != obstacleX && fruitPosY != obstacleY && obstacleX < width && obstacleY < height) {
                vectorObstacles.push_back({obstacleX,obstacleY});
            }
            else
            {
                i--;
            }
    }


}

void logic(const std::vector<std::vector<int>>& vecteurObstacles, const int width,const int height, int& snakePosX, int& snakePosY, int& fruitPosX, int& fruitPosY, int& snakeSize, int tailX[], int tailY[], const eDirection direction, bool& gameover)
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