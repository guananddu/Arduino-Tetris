// View (UI) header
// 2014 Jack Carey

#ifndef MODEL
#define MODEL

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


    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
        Model(){

            #ifdef DEBUG
            Serial.println("Constructing new Model");
            #endif

            pieceGenerator = new MinoFactory();
            // When constructing a new Model(), initialise pieceGenerator and other stuff here!
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
        Tetromino currentPiece;

        char deadPieces[ROWS][COLS];    // all the "placed" blocks that can never move again

};


#endif


