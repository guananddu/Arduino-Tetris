// I-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_I_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_I_TETROMINO

#include "Tetromino.h"

class I_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'I';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int i0[4][2] = {{0,1},{1,1}{2,1},{3,1}}; 
		int i1[4][2] = {{3,0},{3,1}{3,2},{3,3}};
		int i2[4][2] = {{0,2},{1,2}{2,2},{3,2}};
		int i3[4][2] = {{2,0},{2,1}{2,2},{2,3}};
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    I_Tetromino(){
        startPosition = 5;
        shape = (int**) i0;
    }

};

#endif
