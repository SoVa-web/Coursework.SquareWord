#ifndef INPUTGAMEWORD_H
#define INPUTGAMEWORD_H

#pragma once

#include <QGuiApplication>
#include <QWidget>
#include"GameLogic.h"
#include<QMessageBox>
#include<QDebug>
#include<string>
#include"gameboard.h"


using namespace std;

namespace Ui {
class inputGameWord;
}

class inputGameWord : public QWidget
{
    Q_OBJECT

public:
    explicit inputGameWord(QWidget *parent = nullptr);
    gameBoard *window;
    ~inputGameWord();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inputGameWord *ui;
};

#endif // INPUTGAMEWORD_H
