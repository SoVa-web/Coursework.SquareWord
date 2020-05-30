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
            QTableWidgetItem *itm = new QTableWidgetItem(pole.gameMatrix[i][j]);
            ui->tableWidget->setItem(i,j,itm);
            ui->tableWidget->resizeColumnsToContents();
            itm->setBackgroundColor(Qt::blue);
            itm->setTextColor(Qt::white);
           if(pole.gameMatrix[i][j]!=' '){
                ui->tableWidget->item(i,j)->setFlags(itm->flags() & ~Qt::ItemIsEditable);
               //ui->tableWidget->setItemSelected(itm, false);
                 itm->setBackgroundColor(Qt::green);
                 itm->setTextColor(Qt::black);
           }

           // qDebug(pole.gameMatrix[i]);
        }

    }
    on_tableWidget_cellEntered(1,0);

}

gameBoard::~gameBoard()
{
    delete ui;
}


void gameBoard::on_tableWidget_cellEntered(int row, int column)
{

     qDebug("kuku");
}
