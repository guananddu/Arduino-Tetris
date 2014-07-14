// Tetromino Factory Header
// 2014 Abbie Wade

#ifndef MINOFACTORY
#define MINOFACTORY

#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include "TETROMINOES.h"

class MinoFactory{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
        Tetromino* newPiece(); //defins a new functioin that will return a tetromino

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    MinoFactory(){
        counter = 0;
        int i;
        for (i = 0; i < 7; i++){
            generation[i] = i;
        }
        shuffleIntArray();
    }


    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
        Tetromino generatedPieces[7];
        
    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        
	int counter;
    void shuffleIntArray();
	int generation[7];


};

#endif

