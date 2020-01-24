/// \file display.h
/// \authors Yann Lederrey, Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 20.01.2019
///
/// \brief \b Laboratoire \b 10, Snake
/// \brief Fonction ayant pour rôle d'afficher des éléments du jeu SNAKE.
///
/// Compilateur : MinGw-g++ 6.3.0

#ifndef DISPLAY
#define DISPLAY

#include <iostream>
#include <algorithm>
#include "textConst.h"
#include <vector>

/// \brief Fonction affichant les informations du menu au terminal.
/// \param score score actuel du joueur.
void displayMenu(int score);

/// \brief Fonction affichant les informations des instructions au terminal.
void displayInstructions();

/// \brief Fonction affichant les meilleurs scores du meilleurs au moins bon.
void displayHighScore();

/// \brief Fonction affichant la demande du nom d'utilisateur du joueur.
void displayUsernameRequest();

/// \brief Fonction affichant le score d'un joueur.
void displayPlayerScore();

/// \brief Fonction affichant le plateau de jeu.
/// \param width largeur du plateau de jeu.
/// \param height hauteur du plateau de jeu.
/// \param snakePosX position X de la tête du serpent.
/// \param snakePosY position Y de la tête du serpent.
/// \param fruitPosX position X du fruit.
/// \param fruitPosY position Y du fruit.
/// \param snakeSize longueur du serpent.
/// \param tailX tableau de positions X correspondant aux coordonnées X de la queue du serpent
/// \param tailY tableau de positions Y correspondant aux coordonnées Y de la queue du serpent
void draw(int width, int height, int snakePosX, int snakePosY, int fruitPosX, int fruitPosY, int snakeSize, int tailX[], int tailY[], std::vector<std::vector<int>>& vecteurObstacles);
#endif