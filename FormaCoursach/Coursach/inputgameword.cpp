#include "inputgameword.h"
#include "ui_inputgameword.h"

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
    Word input;
  QString gameWord = ui->lineEdit->text();
  string boof = gameWord.toStdString();
  if(!input.checkingRepitsOfLitters(boof)||!input.checkSize(boof)){
      cout<<boof;
      QMessageBox::about(this, "rules",
                               " Enter a word without repetitions and spaces, from 5 to 10 letters");
  }else{
      Pole pole = Pole(boof);
      hide();
      gameBoard *window = new gameBoard(pole);
      window->show();
  }
}
