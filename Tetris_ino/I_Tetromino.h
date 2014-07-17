// I-shaped tetromino
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_I_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_I_TETROMINO

#include "Tetromino.h"

class I_Tetromino : public Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'I';
        }
        int** getShape() {
            return shape;
        }

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    I_Tetromino(){
        startPosition = 5;
        shape = (int**) i0;
        colour = "cyan";
    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        static int i0[4][2];
        static int i1[4][2];
        static int i2[4][2];
        static int i3[4][2];
        int** shape;

};

#endif
