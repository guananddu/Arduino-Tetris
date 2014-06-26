// L-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_L_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_L_TETROMINO

#include "Tetromino.h"

class L_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'L';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{0,1},{0,2},{1,1},{2,1}};
		int i1[4][2] = {{0,0},{1,0},{1,1},{1,2}};
		int i2[4][2] = {{2,0},{2,1},{2,2},{1,2}};
		int i3[4][2] = {{1,0},{1,1},{1,2},{2,2}};
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    L_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
    }

};

#endif
