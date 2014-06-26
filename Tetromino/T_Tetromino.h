// T-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments

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

        int i0[4][2] = {{0,1},{1,1},{2,1},{1,2}};
		int i1[4][2] = {{0,1},{1,0},{1,1},{1,2}};
		int i2[4][2] = {{1,1},{0,2},{1,2},{2,2}};
		int i3[4][2] = {{2,1},{1,0},{1,1},{1,2}};
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    T_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
    }

};

#endif
