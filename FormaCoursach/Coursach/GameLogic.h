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
    bool checkingRepitsOfLitters(QString input);
    bool checkSize(QString input);
    //varieties

};

class Pole{
public:
    //prototypes
    Pole(QString input);
    ~Pole();
    void init(int lines, int columns, QChar**& matrix);
    void createGameMatrix();
    bool checkRowColumns(int row, int columns, QChar temp);
    bool checkSizeText(QString temp);
    QString deleteSpace(QString temp);
    bool checkDiagonal();
    QString word;
    QChar** gameMatrix;
    int sizeBoard= word.length();
};



