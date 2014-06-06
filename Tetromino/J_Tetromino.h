// J-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_J_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_J_TETROMINO

#include "Tetromino.h"

class J_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'J';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{1,0},{1,1},{1,2},{0,2}}; // top piece -= 1 for 0 and -=22 for 2
        int** shape;
        int offset;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    J_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
        offset = 0;
    }

};

#endif
