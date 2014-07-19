// Z-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_Z_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_Z_TETROMINO

#include "Tetromino.h"

class Z_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){ //returns the block letter of the tetromino
            return 'Z';
        }
        int** getShape() { //this returns the actual shape of the tetromino, eg a T "shape" no the letter
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    Z_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new Z_Tetromino");
        #endif

        startPosition = 3;
        shape = (int**) z0;
        colour = "red";
    }

    ~Z_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying Z_Tetromino");
        #endif

    }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        /*these define shapes of the tetromino*/
        static int z0[4][2];
        static int z1[4][2];
        static int z2[4][2];
        static int z3[4][2];
        int** shape;

};

#endif


