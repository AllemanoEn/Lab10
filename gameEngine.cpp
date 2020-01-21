#include "gameEngine.h"

void fruitSpawn(int& fruitX, int& fruitY, const int width, const int height)
 {
    srand ( time(NULL) );
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void logic(const int width,const int height, int& snakePosX, int& snakePosY, int& fruitPosX, int& fruitPosY, int& snakeSize, int tailX[], int tailY[], const eDirection direction, bool& gameover)
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
        fruitSpawn(fruitPosX,fruitPosY,width,height);
    }
}