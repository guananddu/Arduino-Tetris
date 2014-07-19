#include "Tetromino.h"

char Tetromino::blockLetter(){}
int** Tetromino::getShape(){}


Tetromino::Tetromino(){

    #ifdef DEBUG
    Serial.prinln("Creating base Tetromino class instance");
    #endif
}


Tetromino::~Tetromino(){

    #ifdef DEBUG
    Serial.println("Destroying base Tetromino class instance");
    #endif
}



