// Tetromino Factory Class Functions
// 2014 Abbie Wade

#include "MinoFactory.h"
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

//  This method is called by controller to get a new piece when I need one.
Tetromino* MinoFactory::newPiece(){
    if(counter >= 7) { // finished up all the pieces!
    	counter = 0;
    	shuffleIntArray(); // now have a new generation of pieces
    }
    switch(generation[counter-1]){
        case 0: return new I_Tetromino();
        case 1: return new J_Tetromino();
        case 2: return new L_Tetromino();
        case 3: return new S_Tetromino();
        case 4: return new Z_Tetromino();
        case 5: return new T_Tetromino();
        case 6: return new O_Tetromino();
        default: break;  
    }
    
}

void MinoFactory::shuffleIntArray(){
    random_shuffle(&generation[0],&generation[6]);
//    vector<int> randomiser(generation, generation+7);
//    random_shuffle(randomiser.begin(), randomiser.end()); 
//    int i = 0;
//    for (vector<int>::const_iterator it = randomiser.begin(); it != randomiser.end(); ++it ){
//    	generation[i] = it;
//    	i++;
//    }
}



