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

/// \brief Permet la lecture d'un fichier ligne par ligne, et les ajoute à la suite dans un vecteur de type string
/// \param strNomDuFichier : contient le nom du fichier à chercher avec son extension (ex: fichier.txt)
/// \return Retourne le vecteur contenant les lignes du fichier qui a été lu
vector<string> lecture(const string& strNomDuFichier);

void insertScore(const string& newScore, const string& username, const string& strNomDuFichier);

vector<string> sortScores(vector<string>& vNumbers, vector<string>& vScore);

vector<string> getOnlyScores(const vector<string>& vScore);

#endif //LAB10_SCORE_H
