// O-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_O_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_O_TETROMINO

#include "Tetromino.h"

class O_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'O';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    O_Tetromino(){

        #ifdef DEBUG
        Serial.println("Constructing new O_Tetromino");
        #endif

        startPosition = 5;
        shape = (int**) o0;
        colour = "yellow";
    }

    ~O_Tetromino(){

        #ifdef DEBUG
        Serial.println("Destroying O_Tetromino");
        #endif

    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int o0[4][2];
        int** shape;




};

#endif


