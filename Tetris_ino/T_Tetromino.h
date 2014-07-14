// T-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments

#ifndef TETROMINO_T_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_T_TETROMINO

#include "Tetromino.h"

class T_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'T';
        }

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    T_Tetromino(){
        startPosition = 3;
        shape = (int**) t0;

    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

                static int t0[4][2];
		static int t1[4][2];
		static int t2[4][2];
		static int t3[4][2];
                int** shape;



};

int T_Tetromino::t0[4][2] = {{0,1},{1,1},{2,1},{1,2}};
int T_Tetromino::t1[4][2] = {{0,1},{1,0},{1,1},{1,2}};
int T_Tetromino::t2[4][2] = {{1,1},{0,2},{1,2},{2,2}};
int T_Tetromino::t3[4][2] = {{2,1},{1,0},{1,1},{1,2}};

#endif
