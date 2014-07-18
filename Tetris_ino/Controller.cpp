// Controller class
// Copyright 2014 Christopher Claoue-Long and Abbie Wade

#include "Controller.h"


// This method controls the movement of a piece. This method is called by another .ccp file when it is time to move the piece down to the next row.
//      It first checks if a piece has landed.
//  If this is the case, it places the piece and gets a new piece.
//  If the piece hasn't landed it checks the move is legal and if it is places the piece.

void Controller::movePiece(char letter) {  //just worrying about gravity (moving down for the moment)
    int** blocks = currPiece->getShape();
    if (hasLanded(blocks)){
        placePiece(blocks);
        currPiece = pieceGen->newPiece();
        topCoord = currPiece->startPosition;
    }
    else{
        if (isLegal(blocks)){
            topCoord += 10;
        }
    }
}


//      This method checks if a piece can move to the next place it needs to move by testing whether the piece will
//  go out of bounds or if the place it wants to move into is empty
bool Controller::isLegal(int** blocks) {
    //TODO   write helper functions for left and right - check deadblockarray, and boundaries.
    return checkBelow(blocks);
}

/* if there is a piece in deadBlockArray below currPiece, it will return false */
bool Controller::checkBelow(int** blocks){
    for (i = 0; i < 4; i++){
        if (deadBlockArray[blocks[i][0] + (topCoord/10) + 10][blocks[i][1] + (topCoord%10) + 10] != BLACK){
            return false;
        }
    }
    return true;


}

bool Controller::checkRight(int** blocks){
    for (i = 0; i<4; i++){
        if (deadBlockArray[blocks[i][0] + (topCoord/10) + 1][blocks[i][1] + (topCoord%10) + 1] != BLACK){
            return false;
        }
    }
    return true;
}

bool Controller::checkLeft(int** blocks){
    for (i = 0; i<4; i++){
        if (deadBlockArray[(blocks[i][0] + (topCoord/10) - 1)] [(blocks[i][1] + (topCoord%10) -1 )] != BLACK){
            return false;
        }
    }
    return true;
}

//  This method checks if the board is in a game over situation or not and returns the appropriate boolean.
bool Controller::isGameOver() {

}


//  reset all the variables back to base value so you can start a new game
void Controller::reset() {
    gameOver = false;
    r = c = x = i = y = topCoord = 0;
    //topRow = {0,0,0,0,0,0,0,0,0,0};
    //recreate deadBlockArray?
        //get new piece
}

//  This method spawns a piece when required.
void Controller::placePiece(int** blocks) {
    for (i=0; i<4; i++){
        deadBlockArray[(blocks[i][0] + (topCoord/10))][(blocks[i][1] + (topCoord%10))] = currPiece->colour;
        }
}

//  * This method checks if a piece has landed, and returns the appropriate boolean. (CLUE: Use belowTopRow)
bool Controller::hasLanded(int** blocks) {
    return (!checkBelow(blocks));
}


void Controller::prepInterrupts(){
    
    

   
}

void Controller::printBoard(){
   int i,j;
   for(i = 0; i < 20; i++){
     for(j = 0; j < 10; j++){
         Serial.print(deadBlockArray[j][i]);
     }
     Serial.println();
   }
}

