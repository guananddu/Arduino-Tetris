// s-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_O_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_O_TETROMINO

#include "Tetromino.h"

class S_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'S';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{1,1},{2,1},{0,2},{1,2}};
		int i1[4][2] = {{0,0},{0,1},{1,1},{1,2}};
		int i2[4][2] = {{1,1},{2,1},{0,2},{1,2}};
		int i3[4][2] = {{0,0},{0,1},{1,1},{1,2}};


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    S_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
    }

};

#endif
