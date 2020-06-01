#include<QDebug>
#include"GameLogic.h"



//checking of game word with litters that can be repite
bool Word::checkingRepitsOfLitters(QString input){
    int a = input.length();
    for(int  i =0; i < a; i++){
        if(input[i]==' ')
            return false;
        for(int j =0; j < a; j++){
            if(i != j&&input[i]==input[j])
                return false;
        }
    }
    return true;
}

//checking game word with number of litters, number should be more=5 and less=10
bool Word::checkSize(QString input){
    if(input.length()>=5&&input.length()<=10)
        return true;
    else
        return false;
}

void Pole::init(int lines, int columns, QChar **&matrix){
    matrix=new QChar*[lines];
    for(int i =0; i < lines; i++){
        matrix[i]=new QChar[columns];
    }

}

bool Pole::checkSetOfLLitters(QChar temp){
    for(int i =0; i <sizeBoard; i++){
        if(word[i]==temp){
            return true;
        }
    }
    return false;
}

void Pole::createGameMatrix(Word&input){
    int a = this->word.length();
    for(int i =0; i < a; i++){
        this->gameMatrix[0][i] = word[i];
    }
    for(int i =1; i < a; i++){
        for(int j =0; j<a; j++){
            this->gameMatrix[i][j] = ' ';
        }
    }
    if(a>6){
        readingFile();
        QStringList boof;
        int l =0;
        for(int i =0; i < mass.size();i++){
            int k =0;
            for(int j =0; j < mass[i].length(); j++){
                for(int h =0; h < a; h++){
                    if(mass[i][j]==word[h]){
                        k++;
                    }
                }
            }
            if(k==mass[i].length()&&input.checkingRepitsOfLitters(mass[i])){
                boof.append(mass[i]);
                qDebug()<<boof.size();
            }
        }
       for(int i =0; i < boof.size(); i++){
           int x, y, t;
           int high  = a-1-boof[i].length();
           x = qrand() % ((high + 1) - 1) + 1;
           y = qrand() % ((high + 1) - 0) + 0;
           t = y;
           for(int j =0; j < boof[i].length(); j++){
               gameMatrix[x][y] = boof[i][j];
               y++;
           }
           bool win = true;
           for(int i =0; i < a;i++){
               for(int j =0; j < a; j++){
                   if(checkRowColumns(i,j,gameMatrix[i][j])){
                   }else{
                         win = false;
                   }
               }
           }
           if(!checkDiagonal()){
                win = false;
           }
           if(!win){
               for(int j =0; j < boof[i].length(); j++){
                   gameMatrix[x][t] = ' ';
                   t++;
               }
           }else{

             l++;
             if(l ==2)
                 break;
           }
       }


    }
}


bool Pole::checkRowColumns(int row, int columns, QChar temp){
    for(int i =0; i < sizeBoard; i++){
       if(temp!=' '){
           if(gameMatrix[row][i]==temp&&i!=columns)
               return false;
           if(gameMatrix[i][columns]==temp&&i!=row)
               return false;
       }else{
           return true;
       }
    }
    return true;
}

bool Pole::checkSizeText(QString temp){
    int a = temp.length();
    if(a > 1){
        return false;
    }else{
        return true;
    }
}

QString Pole::deleteSpace(QString temp){
    int a = temp.length();
    QString newStr;
    for(int i =0; i < a; i++){
      if(temp[i] != ' '){
           newStr+=temp[i];
      }
    }
    if(newStr == ""){
        newStr = " ";
    }
qDebug()<<newStr;
return  newStr;
}

bool Pole::checkDiagonal(){
    for(int i = 0 ; i < this->sizeBoard; i++){
       for(int j = 0; j < this-> sizeBoard; j++){
        if(i != j&&gameMatrix[i][i]!=' '&&gameMatrix[j][j]!=' '){
            if(gameMatrix[i][i]==gameMatrix[j][j]){
                return  false;
            }
        }
       }
}
     for(int i = 0 ; i < this->sizeBoard; i++){
        for(int j = 0; j < this-> sizeBoard; j++){
         if(i != j&&gameMatrix[i][sizeBoard-i-1]!=' '&&gameMatrix[j][sizeBoard-j-1]!=' '){
             if(gameMatrix[i][sizeBoard-i-1]==gameMatrix[j][sizeBoard-j-1]){
                return  false;
            }
        }
       }
}
return true;
}

/* Pole::checkStatusMatrix(){
    if(!checkDiagonal())
        return  false;
    for(int i =0; i < sizeBoard; i++){
        for(int j =0; j < sizeBoard; j++){
            if(!checkRowColumns(i, j, gameMatrix[i][j]))
                return false;
        }
    }

    return true;
}*/

void Pole::readingFile(){
    QFile file("setWords.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        while (!in.atEnd())
       {
           QString line = in.readLine();
           QString b;
           for(int i =0; i  <line.length(); i++){
               if(line[i] != ' '&&line[i] != '\n'){
                   b+=line[i];
               }
           }
           mass.append( b );

        }
       qDebug() << mass[ 100 ];
}
