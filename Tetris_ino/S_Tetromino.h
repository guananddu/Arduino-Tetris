// s-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_S_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_S_TETROMINO

#include "Tetromino.h"

class S_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'S';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    S_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new S_Tetromino");
        #endif

        startPosition = 3;
        shape = (int**) s0;
        colour = "green";
    }

    ~S_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying S_Tetromino");
        #endif

    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int** shape;
        static int s0[4][2];
        static int s1[4][2];
        static int s2[4][2];
        static int s3[4][2];

};

#endif


