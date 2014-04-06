// Z-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_Z_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_Z_TETROMINO

#include "Tetromino.h"

class T_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'Z';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{0,0},{0,1},{1,1},{1,2}}; // top piece -= 1 for 0 and -=22 for 2
        int** shape;
        int offset;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    Z_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
        offset = 0;
    }

};

#endif
