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

#include "score.h"

#include <fstream>
#include <iostream>

vector<string> lecture(const string& strNomDuFichier){
    vector<string> vScores;

    string line;
    ifstream inputFile;
    inputFile.open(strNomDuFichier);

    if(inputFile.fail()){
        cerr << "Le fichier n'a pas pu s'ouvrir";
        inputFile.close();
        return vScores;
    }

    while (!inputFile.eof()){

        getline(inputFile,line);

        if(!line.empty()){
            vScores.push_back(line);
        }
    }

    inputFile.close();

    return vScores;
}

void insertScore(const string& newScore, const string& username, const string& strNomDuFichier)
{
    vector<string> vScore = lecture(strNomDuFichier);

    ofstream outputFile;
    outputFile.open(strNomDuFichier);

    string highScore;
    string formatedScore = newScore + ":" + username;

    bool FIND = false;
    int cnt = 0;

    ///Vérifie si un joueur existe déjà, si oui, uniquement le meilleur score est sauvegardé
    for(auto vs : vScore)
    {
        if(vs.find(username) != string::npos){
            ///Compare les noms d'utilisateur
            for (int i = 0; i < vs.find(':'); ++i) {
                highScore += vs.at(i);
            }

            if(highScore.size() < newScore.size()){
                vScore.at(cnt) = formatedScore;
            }
            else if (highScore.size() == newScore.size() && highScore < newScore){
                vScore.at(cnt) = formatedScore;
            }
            FIND = true;
            break;
        }
        cnt++;
    }

    ///Si le nom d'utilisateur n'existe pas, on le rajoute dans le vecteur des scores
    if(!FIND)
    {
        vScore.push_back(formatedScore);
    }

    ///Permet de trier les scores
    vector<string> vScoresOnly = getOnlyScores(vScore);
    sortScores(vScoresOnly,vScore);

    ///Copie les valeurs du vecteur ligne par ligne dans le fichier texte
    for(const auto & k : vScore) {
        outputFile << k << endl;
    }
    outputFile.close();
}

vector<string> sortScores(vector<string>& vNumbers, vector<string>& vScore){

    ///Triage par rapport à la taille du score, puis par ordre inverse de grandeur
    for (int i = 0; i < vNumbers.size()-1; i++) {

        ///Vérifie la taille du score
        if(vNumbers.at(i).size()<vNumbers.at(i+1).size()) {
            swap(vScore.at(i), vScore.at(i + 1));
            swap(vNumbers.at(i), vNumbers.at(i + 1));
            ///Permet de recommencer la boucle, tant que tout n'est pas correctement trié
            i = -1;
        }
        ///Si la taille est égale, on compare la valeur ASCII des chiffres
        else if (vNumbers.at(i).size() == vNumbers.at(i+1).size() && vNumbers.at(i) < vNumbers.at(i + 1)) {
            swap(vScore.at(i), vScore.at(i + 1));
            swap(vNumbers.at(i), vNumbers.at(i + 1));
            ///Aanalogue ligne 101
            i = -1;
        }
    }

    return vScore;
}

vector<string> getOnlyScores(const vector<string>& vScore){
    vector<string> vNumbers;

    ///Récupère uniquement le score des joueurs, sans leurs pseudos, cela sert pour le trie
    for(string s : vScore)
    {
        vNumbers.push_back(s.substr(0,s.find(':')));
    }
    return vNumbers;
}