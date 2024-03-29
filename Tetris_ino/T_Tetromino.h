// T-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_T_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_T_TETROMINO

#include "Tetromino.h"
#include <Arduino.h>

class T_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'T';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    T_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new T_Tetromino");
        #endif

        startPosition = 3;
        shape = (int**) t0;
        colour = "purple";
    }

    ~T_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying T_Tetromino");
        #endif


    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int t0[4][2];
        static int t1[4][2];
        static int t2[4][2];
        static int t3[4][2];
        int** shape;

};

#endif


