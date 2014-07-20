// Tetromino Factory Header
// 2014 Abbie Wade

#ifndef MINOFACTORY_HEADER
#define MINOFACTORY_HEADER

// Comment this out to stop DEBUG over serial
#define DEBUG

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
        Tetromino* newPiece(); // will return a tetromino subclass

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
        MinoFactory(){

            #ifdef DEBUG
            Serial.println("Constructing new MinoFactory");
            #endif

            counter = 0;
            // Initialise the generation array for reshuffling each time
            int i;
            for (i = 0; i < 7; i++){
                generation[i] = i;
            }
            shuffleIntArray();
        };

        ~MinoFactory(){

            #ifdef DEBUG
            Serial.println("Destroying MinoFactory");
            #endif

        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int counter;
        void shuffleIntArray();
        int generation[7];

};

#endif


