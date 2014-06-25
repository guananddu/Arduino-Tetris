// Controller Header
// Copyright 2014 Abbie Wade

#ifndef CONTROLLER_HEADER // prevents errors from including it multiple times
#define CONTROLLER_HEADER

#include "Tetromino/TETROMINOES.h"
#include "MinoFactory.cpp"

#define int ROWSIZE = 21;
#define int ROWSIZE = 21;
#define int COLUMNSIZE = 9;
#define int PREVIEWROWSIZE = 2;
#define int PREVIEWCOLUMNSIZE = 4;
#define int SHAPESIZE = 4;

#define int BLACK = 0;

class Controller {

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
        char* deadBlockArray[20][10];

        void movePiece(/*INPUT HERE*/);

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        bool gameOver = false;
        int r, c, x, i, y, topCoord;
        int[] topRow = new int[10];//Top row of the Deadblocks
		//private Color[][] deadBlockArray = new Color [22][10];
        Tetromino currPiece;
        MinoFactory pieceGen = new MinoFactory();    
    
        bool isLegal(/*INPUT HERE*/);
        bool collisionCheck(/*INPUT HERE*/);
        bool gameOver();
        void reset();
        bool belowTopRow(/*INPUT HERE*/);
        void placePiece();
        bool hasLanded();
        bool outOfBounds(/*INPUT HERE*/);
        void getPiece();
		
		bool checkBelow();
		bool checkRight();
		bool checkLeft();
	

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    Controller(){
        gameOver = false;
        pieceGen = new PieceFactory();
        reset(); // reset all the items back to original values
        placePiece(); // place first tetromino
    }

};

#endif
