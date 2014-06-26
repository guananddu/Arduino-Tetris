// Tetromino Factory Class Functions
// 2014 Abbie Wade

#include "MinoFactory.h"
#include <vector>
#include <algorithm>

//  This method is called by controller to get a new piece when I need one.
Tetromino MinoFactory::newPiece(){
    counter ++;
    if(counter > 7) { // finished up all the pieces!
    	counter = 0;
    	shuffleIntArray(); // now have a new generation of pieces
    }
    return generatedPieces[generation[counter-1]];
    
}

void MinoFactory::shuffleIntArray(){
    vector<int> randomiser(generation, generation+7);
    random_shuffle(randomiser.begin(), randomiser.end()); 
    int i = 0;
    for (vector<int>::const_iterator it = randomiser.begin(); it != randomiser.end(); ++it ){
    	generation[i] = it;
    	i++;
    }

}

