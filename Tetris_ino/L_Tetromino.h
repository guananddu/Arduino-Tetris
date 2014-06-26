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

        static int l0[4][2];
		static int l1[4][2];
		static int l2[4][2];
		static int l3[4][2];
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    L_Tetromino(){
        startPosition = 3;
        shape = (int**) l0;
    }

};

int L_Tetromino::l0[4][2] = {{0,1},{0,2},{1,1},{2,1}};
int L_Tetromino::l1[4][2] = {{0,0},{1,0},{1,1},{1,2}};
int L_Tetromino::l2[4][2] = {{2,0},{2,1},{2,2},{1,2}};
int L_Tetromino::l3[4][2] = {{1,0},{1,1},{1,2},{2,2}};


#endif

