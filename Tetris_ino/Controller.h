// Controller Header
// Copyright 2014 Abbie Wade

#ifndef CONTROLLER_HEADER // prevents errors from including it multiple times
#define CONTROLLER_HEADER

#include <Arduino.h>
#include "TETROMINOES.h"
#include "MinoFactory.h"

#define ROWSIZE 21
#define COLUMNSIZE 9
#define PREVIEWROWSIZE 2
#define PREVIEWCOLUMNSIZE 4
#define SHAPESIZE 4

#define BLACK 0

class Controller {

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
        void movePiece(char letter);
        void printBoard();
        

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    Controller(){
        prepInterrupts();
        gameOver = false;
        pieceGen = new MinoFactory();
        reset(); // reset all the items back to original values
    }
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
        char* deadBlockArray[20][10];


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        bool gameOver;
        int r, c, x, i, y, topCoord;
        int topRow[10];//Top row of the Deadblocks
        //private Color[][] deadBlockArray = new Color [22][10];
        Tetromino* currPiece;
        MinoFactory* pieceGen;

        bool isLegal(int** blocks);
        bool collisionCheck(/*INPUT HERE*/);
        bool isGameOver();
        void reset();
        bool belowTopRow(int** blocks);
        void placePiece(int** blocks);
        bool hasLanded(int** blocks);
        bool outOfBounds(/*INPUT HERE*/);
        void getPiece();

        bool checkBelow(int** blocks);
        bool checkRight(int** blocks);
        bool checkLeft(int** blocks);
        void prepInterrupts();
        
        



};

#endif



