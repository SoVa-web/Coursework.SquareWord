#include "gameboard.h"
#include "ui_gameboard.h"
#include<QTableWidget>

gameBoard::gameBoard(Pole&pole, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameBoard)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(pole.sizeBoard);
    ui->tableWidget->setColumnCount(pole.sizeBoard);

    for(int i =0; i < ui->tableWidget->rowCount();i++){
        for(int j =0; j < ui->tableWidget->columnCount();j++){

        }
    }

}

gameBoard::~gameBoard()
{
    delete ui;
}
