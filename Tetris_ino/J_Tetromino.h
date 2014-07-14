// J-shaped tetromino
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_J_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_J_TETROMINO

#include "Tetromino.h"

class J_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'J';
        }

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    J_Tetromino(){
        startPosition = 3;
        shape = (int**) j0;
        colour = "blue";
    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int j0[4][2];
		static int j1[4][2];
		static int j2[4][2];
		static int j3[4][2];
        int** shape;



};

int J_Tetromino::j0[4][2] = {{0,1},{1,1},{2,1},{2,2}};
int J_Tetromino::j1[4][2] = {{0,2},{1,0},{1,1},{1,2}};
int J_Tetromino::j2[4][2] = {{0,1},{0,2},{1,2},{2,2}};
int J_Tetromino::j3[4][2] = {{1,0},{1,1},{1,2},{2,0}};

#endif

