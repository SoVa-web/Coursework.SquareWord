#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#endif // GAMELOGIC_H

#pragma once

#include<iostream>
#include<string>
#include<QString>

using namespace std;

class Word{
public:
    //prototypes
    bool checkingRepitsOfLitters(string input);
    bool checkSize(string input);
    //varieties

};

class Pole{
public:
    //prototypes
    Pole(string input);
    ~Pole();
    void init(int lines, int columns, char**& matrix);
    void createGameMatrix();
    string word;
    char** gameMatrix;
    int sizeBoard= word.length();
};



