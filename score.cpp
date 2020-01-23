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
#include <algorithm>

/// \brief Permet la lecture d'un fichier ligne par ligne, et les ajoute à la suite dans un vecteur de type string
/// \param strNomDuFichier : contient le nom du fichier à chercher avec son extension (ex: fichier.txt)
/// \return Retourne le vecteur contenant les lignes du fichier qui a été lu
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
    string highScore;
    string formatedScore = newScore + ":" + username;
    int i = 0;
    bool FIND = false;
    ofstream outputFile;
    outputFile.open(strNomDuFichier);
    int cnt = 0;

    for(auto vs : vScore)
    {
        if(vs.find(username) != string::npos){
            for (;i < vs.find(':'); ++i) {
                highScore += vs.at(i);
            }
            if(highScore < newScore){
                vScore.at(cnt) = formatedScore;
            }
            FIND = true;
            break;
        }
        cnt++;
    }


    if(!FIND)
    {
        vScore.push_back(formatedScore);
    }

    sort(vScore.rbegin(),vScore.rend());

    for(const auto & k : vScore) {
        outputFile << k << endl;
    }
    outputFile.close();
}

vector<string> sortScores(const string& strNomDuFichier){

}

void getOnlyScores(const vector<string>& vScore){


}