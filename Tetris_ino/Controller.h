// Game logic "Controller".
// Copyright 2014 Abbie Wade

#ifndef CONTROLLER_HEADER // prevents errors from including it multiple times
#define CONTROLLER_HEADER

// Comment this out to stop DEBUG over serial
#define DEBUG

#include <Arduino.h>
#include "Model.h"
#include "View.h"

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
        void redraw();


    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
    Controller(Model* data, View* ui){

        #ifdef DEBUG
        Serial.println("Creating new Controller");
        #endif

        gameOver = false;
        model = data;
        view = ui;
    }

    ~Controller(){
        #ifdef DEBUG
        Serial.println("Destroying Controller");
        #endif

    }



    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
        char* deadBlockArray[20][10];


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        bool gameOver;
        int r, c, x, i, y, topCoord;
        int topRow[10];//Top row of the Deadblocks

        bool isLegal(int** blocks);
        bool collisionCheck(/*INPUT HERE*/);
        bool isGameOver();
        void reset();
        bool belowTopRow(int** blocks);
        bool hasLanded(int** blocks);
        bool outOfBounds(/*INPUT HERE*/);
        void getPiece();

        bool checkBelow(int** blocks);
        bool checkRight(int** blocks);
        bool checkLeft(int** blocks);
        Model* model;
        View* view;
        void insertPiece();





};

#endif





