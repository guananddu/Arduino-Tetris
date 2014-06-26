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

        int i0[4][2] = {{0,1},{1,1},{2,1},{2,2}};
		int i1[4][2] = {{0,2},{1,0},{1,1},{1,2}};
		int i2[4][2] = {{0,1},{0,2},{1,2},{2,2}};
		int i3[4][2] = {{1,0},{1,1},{1,2},{2,0}};
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    J_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
    }

};

#endif
