// Z-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_Z_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_Z_TETROMINO

#include "Tetromino.h"

class T_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){ //returns the block letter of the tetromino
            return 'Z';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int** getShape() { //this returns the actual shape of the tetromino, eg a T "shape" no the letter
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
		/*these define shapes of the tetromino*/
        int i0[4][2] = {{0,1},{1,1},{1,2},{2,2}};
		int i1[4][2] = {{2,0},{2,1},{1,1},{1,2}};
		int i2[4][2] = {{0,1},{1,1},{1,2},{2,2}};
		int i3[4][2] = {{2,0},{2,1},{1,1},{1,2}};
        int** shape;


    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    Z_Tetromino(){
        startPosition = 3;
        shape = (int**) i0;
    }

};

#endif
