#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#endif // GAMELOGIC_H

#pragma once

#include<iostream>
#include<string>
#include<QString>
#include<QFile>
#include<QStringList>
#include <QCoreApplication>
#include <QDateTime>

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
    void createGameMatrix(Word&input);
    bool checkRowColumns(int row, int columns, QChar temp);
    bool checkSizeText(QString temp);
    QString deleteSpace(QString temp);
    bool checkDiagonal();
    bool checkStatusMatrix();
    bool checkSetOfLLitters(QChar temp);
    void readingFile();
    //varieties
    QString word;
    QChar** gameMatrix;
    int sizeBoard= word.length();
    QStringList mass;

    private:
    Pole(){}
};



