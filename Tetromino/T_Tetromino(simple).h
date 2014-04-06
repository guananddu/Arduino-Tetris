// T-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_T_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_T_TETROMINO

#include "Tetromino.h"

class T_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'T';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{0,0},{1,0},{2,0},{1,1}}; // top piece -= 1 for 0 and -=22 for 2
        int** shape;
        int offset;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    T_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
        offset = 0;
    }

};

#endif
