// I-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_I_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_I_TETROMINO

#include "Tetromino.h"

class I_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'I';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    I_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new I_Tetromino");
        #endif

        startPosition = 5;
        shape = (int**) i0;
        colour = "cyan";
    }

    ~I_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying I_Tetromino");
        #endif


    }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int i0[4][2];
        static int i1[4][2];
        static int i2[4][2];
        static int i3[4][2];
        int** shape;

};

#endif


