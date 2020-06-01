#include "inputgameword.h"
#include "ui_inputgameword.h"
#include<iomanip>

inputGameWord::inputGameWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputGameWord)
{
    ui->setupUi(this);
}

inputGameWord::~inputGameWord()
{
    delete ui;
}



void inputGameWord::on_pushButton_clicked()
{
    //setlocale(LC_ALL, ".UTF-8");
    Word input;
  QString gameWord = ui->lineEdit->text();
  QString boof = gameWord;
  boof = boof.toLower();
  if(!input.checkingRepitsOfLitters(boof)||!input.checkSize(boof)){
      QMessageBox::about(this, "Rules",
                               " Enter a word without repetitions and spaces, from 5 to 10 letters");
  }else{
      Pole::instance()->word = boof;
      Pole::instance()->sizeBoard = boof.length();
      Pole::instance()->init(boof.length(), boof.length(), Pole::instance()->gameMatrix);
      Pole::instance()->createGameMatrix();
      hide();
      gameBoard *window = new gameBoard();
      window->show();
  }
}
