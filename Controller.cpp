// Controller class
// Copyright 2014 Christopher Claoue-Long and Abbie Wade

#include "Controller.h"

// This method controls the movement of a piece. This method is called by another .ccp file when it is time to move the piece down to the next row. 
//      It first checks if a piece has landed. 
//	If this is the case, it places the piece and gets a new piece. 
//	If the piece hasn't landed it checks the move is legal and if it is places the piece. 

void Controller::movePiece(/*INPUT HERE*/) {  //just worrying about gravity (moving down for the moment)
	/*move topCoord??*/ 
	topCoord = topCoord + 10
	if (hasLanded = false){
		if (isLegal = true){
			//do nothing?? or placePiece
		}
		else{
			//unknown
		}
	}
	else{
		placePiece;
	}
}


//  	This method checks if a piece can move to the next place it needs to move by testing whether the piece will 
// 	go out of bounds or if the place it wants to move into is empty
bool Controller::isLegal(/*INPUT HERE*/) {
	if /*place is empty&&not out of bounds*/{
		return 1;
	}
	else{
		return 0;
	}
}

//  This method checks if the board is in a game over situation or not and returns the appropriate boolean.
bool Controller::gameOver() {
	if deadBlockArray > /*board*/{
		return 1;
	}
	else{
		return 0;
	}
}


//  reset all the variables back to base value so you can start a new game
void Controller::reset() {
	gameOver = false;
	r = c = x = i = topCoord = 0;
	topRow = new int[10];
	//recreate deadBlockArray?
}


//  This method spawns a piece when required.
void Controller::placePiece() {
	// write code here
}

//  * This method checks if a piece has landed, and returns the appropriate boolean. (CLUE: Use belowTopRow)
bool Controller::hasLanded() {
	//if tetromino is belowTopRow{
		return true;
}

// this methods gets a piece when you are ready for it
void getPiece(){
    MinoFactory::newPiece();
}
