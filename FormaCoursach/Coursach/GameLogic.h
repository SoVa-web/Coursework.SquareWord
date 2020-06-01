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
  static Pole*instance(){
      static Pole pole;
      return &pole;
  }

    void init(int lines, int columns, QChar**& matrix);
    void createGameMatrix();
    bool checkRowColumns(int row, int columns, QChar temp);
    bool checkSizeText(QString temp);
    QString deleteSpace(QString temp);
    bool checkDiagonal();
    bool checkStatusMatrix();
    bool//for check wet of litters
    QString word;
    QChar** gameMatrix;
    int sizeBoard= word.length();

    private:
    Pole(){}
};



