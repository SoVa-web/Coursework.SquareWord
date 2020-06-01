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
        ui->tableWidget->setRowHeight(i, 70);
        ui->tableWidget->setColumnWidth(i, 20);
        for(int j =0; j < ui->tableWidget->columnCount();j++){
            QTableWidgetItem *itm = new QTableWidgetItem(Pole::instance()->gameMatrix[i][j]);
            ui->tableWidget->setItem(i, j, itm);
            //ui->tableWidget->resizeColumnsToContents();
           //  ui->tableWidget->resizeRowsToContents();
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

void gameBoard::checkingProcess(){
    bool win = true;
    QString a;
            for(int i =0; i< Pole::instance()->sizeBoard; i++){
                for(int j=0; j <Pole::instance()->sizeBoard; j++){
                    a = ui->tableWidget->item(i,j)->text();
                    a = a.toLower();
                    a = Pole::instance()->deleteSpace(a);
                    if(a.length()==1)
                     {
                       if(a[0]==' '||Pole::instance()->checkSetOfLLitters(a[0])){
                             Pole::instance()->gameMatrix[i][j] = a[0];
                       }else{
                          QMessageBox::about(this,"Rules", " You entered the wrong litter ");
                             Pole::instance()->gameMatrix[i][j] = a[0];
                             win = false;
                       }
                    }
                    else
                         {
                           Pole::instance()->gameMatrix[i][j] = ' ';
                       QMessageBox::about(this,"Rules", " You entered en extra litter ");
                       win = false;
                    }
                }
            }
    bool rowColumn = true;
            for(int i =0; i < Pole::instance()->sizeBoard;i++){
                for(int j =0; j < Pole::instance()->sizeBoard; j++){
                    if(Pole::instance()->checkRowColumns(i,j,Pole::instance()->gameMatrix[i][j])){
                    }else{
                          QMessageBox::about(this,"Rules", " You entered the wrong litter in row or column ");
                          win = false;
                          rowColumn = false;
                          break;
                    }
                }
                if(!rowColumn){
                    break;
                }
            }
            if(!Pole::instance()->checkDiagonal()){
                 QMessageBox::about(this,"Rules", " You entered the wrong litter on diagonal ");
                 win = false;
            }
            if( win == true){
                QMessageBox::about(this, " Congratulation!", "You don`t have mistakes!");
            }
            for(int i =0; i < Pole::instance()->sizeBoard;i++){
                for(int j =0; j <Pole::instance()->sizeBoard; j++){
                    if(Pole::instance()->gameMatrix[i][j] == ' '){
                        win = false;
                    }
                }
            }
            if( win == true){
                QMessageBox::about(this, " Done!", "Congratulations, you won!");
            }

}

void gameBoard:: keyPressEvent(QKeyEvent* event)
{
     if(event->key()==Qt::Key_Return){
   checkingProcess();
}
}

void gameBoard::on_pushButton_clicked()
{
    checkingProcess();
}

void gameBoard::on_pushButton_2_clicked()
{
    QWidget::close();
}
