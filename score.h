/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : score.h
 Auteur(s)   :
 Date        : 20.01.2019

 Compilateur : g++ (GCC) 9.2.0

 Brief       : Fonction pour lire/ecrire les scores dans un fichier texte
 -----------------------------------------------------------------------------------
 */
#ifndef LAB10_SCORE_H
#define LAB10_SCORE_H

#include <vector>
#include <string>
using namespace std;

vector<string> lecture(const string& strNomDuFichier);

void insertScore(const string& newScore, const string& username, const string& strNomDuFichier);

#endif //LAB10_SCORE_H
