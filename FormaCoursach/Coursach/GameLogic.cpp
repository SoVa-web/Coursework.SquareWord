#include"GameLogic.h"

Pole::Pole(string input){
    this->word=input;
    sizeBoard = word.length();
    init(sizeBoard, sizeBoard, gameMatrix);
}

//checking of game word with litters that can be repite
bool Word::checkingRepitsOfLitters(string input){
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
bool Word::checkSize(string input){
    if(input.length()>=5&&input.length()<=10)
        return true;
    else
        return false;
}

void Pole::init(int lines, int columns, char **&matrix){
    matrix=new char*[lines];
    for(int i =0; i < lines; i++){
        matrix[i]=new char[columns];
    }

}

void Pole::createGameMatrix(){
    int a = this->word.length();
    for(int i =0; i < a; i++){
        this->gameMatrix[0][i] = word[i];
    }
    for(int i =1; i < a; i++){
        for(int j =0; j<a; j++){
            this->gameMatrix[i][j] = ' ';
        }
    }
}


Pole::~Pole(){
    delete gameMatrix;
}
