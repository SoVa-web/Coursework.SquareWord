#include "gameboard.h"
#include "ui_gameboard.h"
#include<QTableWidget>
#include<QKeyEvent>

gameBoard::gameBoard( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameBoard)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(Pole::instance()->sizeBoard);
    ui->tableWidget->setColumnCount(Pole::instance()->sizeBoard);
    for(int i =0; i < ui->tableWidget->rowCount();i++){
        for(int j =0; j < ui->tableWidget->columnCount();j++){
            QTableWidgetItem *itm = new QTableWidgetItem(Pole::instance()->gameMatrix[i][j]);
            ui->tableWidget->setItem(i, j, itm);
            ui->tableWidget->resizeColumnsToContents();
            itm->setBackgroundColor(Qt::blue);
            itm->setTextColor(Qt::white);
           if(Pole::instance()->gameMatrix[i][j]!=' '){
                ui->tableWidget->item(i,j)->setFlags(itm->flags() & ~Qt::ItemIsEditable);
               //ui->tableWidget->setItemSelected(itm, false);
                 itm->setBackgroundColor(Qt::green);
                 itm->setTextColor(Qt::black);
           }
        }

    }
    //qDebug()<<Pole::instance()->sizeBoard;
}



gameBoard::~gameBoard()
{
    delete ui;
}

/*void gameBoard:: keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Return){
            QString a = (ui->tableWidget->item(1,0)->text());
             a = (ui->tableWidget->item(1,0)->text());
            qDebug()<<a;
    }
}*/

void gameBoard::on_pushButton_clicked()
{
QString a;
        for(int i =0; i< Pole::instance()->sizeBoard; i++){
            for(int j=0; j <Pole::instance()->sizeBoard; j++){
                a = ui->tableWidget->item(i,j)->text();
                a = a.toLower();
qDebug()<<a;
            }
        }

}
