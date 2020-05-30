#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#pragma once

#include <QGuiApplication>
#include <QWidget>
#include"GameLogic.h"
#include<QMessageBox>
#include<QDebug>
#include<string>
#include"GameLogic.h"

namespace Ui {
class gameBoard;
}

class gameBoard : public QWidget
{
    Q_OBJECT

public:
     gameBoard(Pole&pole, QWidget *parent = nullptr  );
    ~gameBoard();

private slots:
     void on_tableWidget_cellEntered(int row, int column);

private:
    Ui::gameBoard *ui;
};

#endif // GAMEBOARD_H
