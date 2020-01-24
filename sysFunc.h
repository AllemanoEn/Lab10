/// \file sysFunc.h
/// \authors Yann Lederrey, Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 20.01.2019
///
/// \brief \b Laboratoire \b 10, Snake
/// \brief Fichier comportant des fonctions faisant des actions sur le terminal. Ces dernières
///                ont été programmée de telle sorte qu'elle soient compatible sur LINUX et WINOWS
///
/// Compilateur : MinGw-g++ 6.3.0

#ifndef SYSFUNC
#define SYSFUNC

#include <unistd.h>
#include <cstdlib>

#if defined(_WIN64) || defined(_WIN32)
    #include <conio.h>
    #include <windows.h>
#else
    #include <sys/select.h>
    #include <termios.h>
#endif

#if defined(_WIN64) || defined(_WIN32)
#else
    /**
     * @brief Fonction permettant de detecter sur une touche a été pressée sur le terminal.
     * Cette fonction provient initialement de WINDOWS, libraires conio et windows
     * @return Int retourne 1 en cas de touche pressée sinon 0 et -1 en cas d'erreur.
     */
    int kbhit();

    /**
     * @brief Fonction permettant de récupérer un char sur le terminal.
     * Cette fonction provient initialement de WINDOWS, libraires conio et windows
     * @return Int retourne -1 en cas de buffer vide sinon retourne le char lus.
     */
    int getch();
#endif

/// \brief Fonction permettant de supprimer les éléments affiché sur le terminal.
void clearScreen();

/// \brief Fonction permettant au terminal d'attendre (bloquer) un certain temps définis.
/// \param microseconds Temps d'attente en microsecondes
void mySleep(int microseconds);

#endif