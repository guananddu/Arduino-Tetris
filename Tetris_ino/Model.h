// View (UI) header
// 2014 Jack Carey

#ifndef MODEL
#define MODEL

// Comment this out to stop DEBUG over serial
#define DEBUG

#include "TETROMINOES.h"
#include "MinoFactory.h"

// Size of the board
#define ROWS 22 // there are 2 "invisible" rows at the top where pieces start
#define COLS 10


class Model{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:

        char board[ROWS][COLS];         // The 2D board that acts as the data interface for the View

        void movePiece(char direction); // move the current piece's coordinates
        void updateBoard();             // update the board for the View
        void placePiece();              // place the current piece into the dead blocks
        
        void incrementCounter(){ 
            counter++;
            #ifdef DEBUG
            Serial.print(counter);
            #endif
        };
        int getCounter(){ return counter; };
        void resetCounter(){ counter = 0; };
        int getGravity(){return gravity; };
        void fasterGravity(){}; // TODO


    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
        Model(){

            #ifdef DEBUG
            Serial.println("Constructing new Model");
            #endif

            pieceGenerator = new MinoFactory();
            
            // Initialise the blank board
            int i, j;
            for(i = 0; i < ROWS; i++){
                for(j = 0; j < COLS; j++){
                    board[i][j]='.';
                }
            }
            
            currentPiece = pieceGenerator->newPiece();
            gravity = 60; // 1 second gravity delay to begin with
            counter = 0;

        }

        ~Model(){
            #ifdef DEBUG
            Serial.println("Destroying Model");
            #endif

            delete pieceGenerator;

        }


    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:




    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:

        MinoFactory* pieceGenerator;
        Tetromino* currentPiece;         // Holds its current coordinates internally

        char deadPieces[ROWS][COLS];    // all the "placed" blocks that can never move again
        
        volatile int gravity;
        volatile int counter;

};


#endif


