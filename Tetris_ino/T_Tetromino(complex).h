// T-shaped tetromino
// Copyright 2014 Christopher Claoue-Long

#ifndef TETROMINO_T_TETROMINO // prevents errors from including it multiple times
#define TETROMINO_T_TETROMINO

#include "Tetromino.h"

class T_Tetromino : protected Tetromino{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char blockLetter(){
            return 'T';
        }

    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:

        int rotate() {
            rotCounter++;
            rotateHelper(); // do the shape changing etc in a separate function (more modular)
            return offset;
        }

        int unrotate(){
            int oldOffset = offset; // used rarely, no need to declare globally
            rotCounter--;
            rotateHelper();
            return -oldOffset;
        }


        int wallkick(int testNum){
            switch(rotCounter%4){ // what rotation are we at?
                case 0: switch(testNum){
                    case 0: return -1;
                    case 1: return -11;
                    case 2: return 20;
                    case 3: return 19;
                }
                break;

                case 1: switch(testNum){
                    case 0: return -1;
                    case 1: return 9;
                    case 2: return -20;
                    case 3: return -21;
                }
                break;

                case 2: switch(testNum){
                    case 0: return 1;
                    case 1: return 9;
                    case 2: return 20;
                    case 3: return 21;
                }
                break;

                case 3: switch(testNum){
                    case 0: return 1;
                    case 1: return 11;
                    case 2: return -20;
                    case 3: return 19;
                }
            }
            return 0; // if no ability to kick, should reach this
        }

        int** getShape() {
            return shape;
        }

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        int t0[4][2] = {{1,0},{0,1},{1,1},{1,2}}; // top piece stays the same no matter what
        int t1[4][2] = {{0,0},{1,0},{2,0},{1,1}}; // top piece += 1
        int t2[4][2] = {{0,0},{0,1},{1,1},{0,2}}; // top piece -= 11
        int t3[4][2] = {{1,0},{0,1},{1,1},{2,1}}; // top piece += 10
        int** shape;
        int rotCounter, offset;

        void rotateHelper(){
            switch(rotCounter%4){
                case 0:
                    shape = (int**) t0;
                    offset = 0;
                    break;
                case 1:
                    shape = (int**) t1;
                    offset = 1;
                    break;
                case 2:
                    shape = (int**) t2;
                    offset = -11;
                    break;
                case 3:
                    shape = (int**) t3;
                    offset = 10;
                    break;
            }
        }

    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    T_Tetromino(){
        startPosition = 3;
        int tshape[4][2] = {{0,1},{1,0},{1,1},{1,2}};
        shape = (int**) tshape;
        offset = 0;
        rotCounter = 0;
    }

};

#endif
