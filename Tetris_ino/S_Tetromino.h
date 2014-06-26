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

        static int s0[4][2];
		static int s1[4][2];
		static int s2[4][2];
		static int s3[4][2];


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    S_Tetromino(){
        startPosition = 3;
        shape = (int**) s0;
    }

};

int S_Tetromino::s0[4][2] = {{1,1},{2,1},{0,2},{1,2}};
int S_Tetromino::s1[4][2] = {{0,0},{0,1},{1,1},{1,2}};
int S_Tetromino::s2[4][2] = {{1,1},{2,1},{0,2},{1,2}};
int S_Tetromino::s3[4][2] = {{0,0},{0,1},{1,1},{1,2}};

#endif

