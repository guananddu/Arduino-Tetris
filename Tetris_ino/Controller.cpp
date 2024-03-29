// Controller class
// Copyright 2014 Christopher Claoue-Long and Abbie Wade

#include "Controller.h"

//Is there a varible to see the shape (not letter) of current piece?


// This is called every 1/60th of a second as per official Tetris guidelines
// You need to modify this to redraw when the counter is over gravity delay OR when a button has been pressed
// Which would signal the screen needs redrawing
// Think about adding a volatile int that can be updated accordingly as 0 or 1 to check if a redraw is necessary
// This volatile int will be quick and easy to set during an interrupt!
void Controller::redraw(){
    model->incrementCounter();
    #ifdef DEBUG
    #endif
    if (model->getCounter() >= model->getGravity()){
//        movePiece('D');
        #ifdef DEBUG
        Serial.println(); // Clear the screen before printing the board
        #endif
        view->printBoard();
        model->resetCounter();
    }
}

// This method controls the movement of a piece. This method is called by another .ccp file when it is time to move the piece down to the next row.
//      It first checks if a piece has landed.
//  If this is the case, it places the piece and gets a new piece.
//  If the piece hasn't landed it checks the move is legal and if it is places the piece.

void Controller::movePiece(char letter) {  //just worrying about gravity (moving down for the moment)

    #ifdef DEBUG
    Serial.println("Controller moving piece DOWN");
    #endif
    
    int** blocks = model->getShape();
    if (hasLanded(blocks)){
        model->placePiece();
        currPiece = model->newPiece();
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

//  * This method checks if a piece has landed, and returns the appropriate boolean. (CLUE: Use belowTopRow)
bool Controller::hasLanded(int** blocks) {
    return (!checkBelow(blocks));
}

void insertPiece()
{
  //deadblockarray[pos of shape]=currPiece
}
  
  
  
  
  
