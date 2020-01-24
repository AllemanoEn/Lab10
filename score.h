/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : score.h
 Auteur(s)   :
 Date        : 20.01.2019

 Compilateur : g++ (GCC) 9.2.0

 Brief       : Fonctions permettant la lecture et l'ecriture des scores dans un fichier texte
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

/// \brief Rajoute les noms d'utilisateur des joueurs au classement général
/// \param newScore : Le score de la partie terminée à insérer dans le classement
/// \param username : Le nom d'utilisateur du joueur
/// \param strNomDuFichier : contient le nom du fichier à chercher avec son extension (ex: fichier.txt)
void insertScore(const string& newScore, const string& username, const string& strNomDuFichier);

/// \brief Fonction de triage du classement du meilleur score au pire
/// \param vNumbers : Vecteur contenant uniquement les scores des joueurs, sans leurs pseudo
/// \param vScore : Vecteur correspondant aux classements des joueurs avec leurs scores
/// \return Retourne le classement trié du meilleur au moins bon sous forme de vecteur
vector<string> sortScores(vector<string>& vNumbers, vector<string>& vScore);

/// \brief Permet de séparer, dans un nouveau vecteur, les différents scores des joueurs et leurs noms d'utilisateur
/// \param vScore : Vecteur correspondant aux classements des joueurs avec leurs scores
/// \return Retourne le classement trié du meilleur au moins bon sous forme de vecteur
vector<string> getOnlyScores(const vector<string>& vScore);

#endif //LAB10_SCORE_H
