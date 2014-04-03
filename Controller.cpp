// Controller class
// Copyright 2014 Christopher Claoue-Long and Abbie Wade

#include "Controller.h"

// This method controls the movement of a piece. This method is called by another .ccp file when it is time to move the piece down to the next row. 
//      It first checks if a piece has landed. 
//	If this is the case, it places the piece and gets a new piece. 
//	If the piece hasn't landed it checks the move is legal and if it is places the piece. 

void Controller::movePiece(/*INPUT HERE*/) {
	// write code here
}


//  	This method checks if a piece can move to the next place it needs to move by testing whether the piece will 
// 	go out of bounds or if the place it wants to move into is empty
bool Controller::isLegal(/*INPUT HERE*/) {
	// write code here
}


//   This function returns whether a collision with another piece or a wall could occur if you moved to the new position.
bool Controller::collisionCheck(/*INPUT HERE*/) {
	// write code here
}


//  This method checks if the board is in a game over situation or not and returns the appropriate boolean.
bool Controller::gameOver() {
	if (gmaesss)
}


//  reset all the variables back to base value so you can start a new game
void Controller::reset() {
	// write code here
}


//  This method needs to return the highest piece in the current board array - this means that you can easily check if the piece can 
// drop by one because you know the highest piece in that row already. 

bool Controller::belowTopRow(/*INPUT HERE*/) {
	// write code here
}

//  This method spawns a piece when required.
void Controller::placePiece() {
	// write code here
}

//  * This method checks if a piece has landed, and returns the appropriate boolean. (CLUE: Use belowTopRow)
bool Controller::hasLanded() {
	// write code here
}

//  * This method checks if a movement will be out of bounds or not. It is a helper method for isLegal().
// Particularly good for if it is going to go out of the array sides.
bool Controller::outOfBounds(/*INPUT HERE*/) {
	// write code here
}

// this methods gets a piece when you are ready for it
void getPiece(){
    // write code here
}
