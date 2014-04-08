// Tetromino Factory Class Functions
// 2014 Abbie Wade

#include "MinoFactory.h" 

//  This method is called by controller to get a new piece when I need one.
Tetromino MinoFactory::newPiece(){
    counter ++;
    return shuffledPieces[counter-1];
}

//  This generates a new set of tetrominoes to pass to the controller when it is needed. This is
//  where run newSet() and then shuffle the constant array.
void MinoFactory::shuffleTetrominoes(){
	for (/*i in generation*/){
		//Put i into shuffled Pieces
}

void MinoFactory::shuffleIntArray()
    //randomise "generation" array
    
}

//  This function resets the counter to 0 and copies the constant array to your shuffle array.
void MinoFactory::newSet(){
    if (counter >= 6){
        shuffleTetrominoes();
        counter = 0;
    }
	
}