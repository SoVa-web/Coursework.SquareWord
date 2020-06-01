#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#pragma once

#include <QGuiApplication>
#include <QWidget>
#include<QMessageBox>
#include<QDebug>
#include<string>
#include"GameLogic.h"
#include<QApplication>

namespace Ui {
class gameBoard;
}

class gameBoard : public QWidget
{
    Q_OBJECT

public:
     gameBoard( QWidget *parent = nullptr  );
    ~gameBoard();

public:
void  keyPressEvent(QKeyEvent* event);
void checkingProcess();
private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::gameBoard *ui;
    //void keyPressEvent(QKeyEvent* event);
};

#endif // GAMEBOARD_H
