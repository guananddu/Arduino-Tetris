// L-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_L_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_L_TETROMINO

#include "Tetromino.h"

class L_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'L';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    L_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new L_Tetromino");
        #endif

        startPosition = 3;
        shape = (int**) l0;
        colour = "orange";
    }

    ~L_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying L_Tetromino");
        #endif


    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int l0[4][2];
        static int l1[4][2];
        static int l2[4][2];
        static int l3[4][2];
        int** shape;

};

#endif


