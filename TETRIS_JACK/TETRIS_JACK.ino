// TETRIS by Jack Carey

// External includes
#include <Arduino.h>
#include <PinChangeInt.h>

// Comment to disable debugging
#define DEBUG

// Tetrominoes -----------------------------------------------------------------
#include "tetrominoes.h" // defines Tetromino colours and matrices
// Tetromino list
char tetrominoes[25][4][4]   = {O1, Z1,Z2,Z3,Z4, I1,I2,I3,I4, J1,J2,J3,J4, L1,L2,L3,L4, S1,S2,S3,S4, T1,T2,T3,T4};
// Piece index list
byte pieceIndex[25]          = {0,  1, 2, 3, 4,  5, 6, 7, 8,  9, 10,11,12, 13,14,15,16, 17,18,19,20, 21,22,23,24};
// Piece generation list (randomly shuffled for each bag)
byte pieceGenerationIndex[7] = {0,  1,           2,           3,           4,           5,           6,          };
// Letters to use when debugging
char* tetromino_letters      = "OZIJLST.";

// Board description -----------------------------------------------------------
#define ROWS 22
#define COLS 10
int deadBlocks[ROWS][COLS]; // Dead blocks that will never move again
int board[ROWS][COLS]; // The view combining piece and dead blocks
byte currentPiece; // will store the index of the currently used piece
byte currentRotation;
int currentPieceArray[4][4];
int currentPieceRow, currentPieceCol; // Top left of piece is tracked

// PIECE GENERATION AND ROTATION -----------------------------------------------
int counter = 0; // Initially choose first piece out of bag

// Shuffle the bag of tetrominoes
void shuffleBag(){
    #ifdef DEBUG
    Serial.println("Shuffling");
    for(int i = 0; i < 7; i++){
       Serial.print(tetromino_letters[pieceGenerationIndex[i]]);
    }
    Serial.println();
    #endif

    randomSeed(millis());

    for (int i = 6; i > 0; i--){
        int j = random(i+1);
        byte temp = pieceGenerationIndex[j];
        pieceGenerationIndex[j] = pieceGenerationIndex[i];
        pieceGenerationIndex[i] = temp;
    }

    #ifdef DEBUG
    Serial.println("Done!");
    for(int i = 0; i < 7; i++){
       Serial.print(tetromino_letters[pieceGenerationIndex[i]]);
    }
    Serial.println();

    #endif
}

// Grab a new piece
void newPiece(){
    #ifdef DEBUG
    Serial.println("NP");
    #endif

    currentPieceRow = 0;
    currentPieceCol = 3;

    if (counter > 6){
        counter = 0;
        shuffleBag();
    }

    switch(pieceGenerationIndex[counter]){
        case 0:
            currentPiece = currentRotation = pieceIndex[0];
            break;
        case 1:
            currentPiece = currentRotation = pieceIndex[1];
            break;
        case 2:
            currentPiece = currentRotation = pieceIndex[5];
            break;
        case 3:
            currentPiece = currentRotation = pieceIndex[9];
            break;
        case 4:
            currentPiece = currentRotation = pieceIndex[13];
            break;
        case 5:
            currentPiece = currentRotation = pieceIndex[17];
            break;
        case 6:
            currentPiece = currentRotation = pieceIndex[21];
            break;
    }

    for(int i = 0; i < SHAPESIZE; i++){
       for(int j = 0; j < SHAPESIZE; j++){
           currentPieceArray[i][j] = tetrominoes[currentPiece][i][j];

       }
    }

    counter++;


}

// Check the left boundary
bool checkLeft(){

    return true;
}

// Check the right boundary
bool checkRight(){

    return true;
}

// Check below (true = fine to drop, false = can't)
bool checkBelow(){
    // do any blocks overlap?
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if (deadBlocks[i][j] != BLACK && currentPieceArray[i][j] != BLACK)
                return false;
        }
    }

    // does the piece fall below the board?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (currentPieceArray[i][j] != BLACK && i+currentPieceRow+1 >= ROWS)
                return false;
        }
    }

    // all good!
    return true;
}

// Rotate the piece
void rotate(){
    #ifdef DEBUG
    Serial.println("ROT");
    #endif
}

// Game Logic ------------------------------------------------------------------
#define LEFT 0
#define RIGHT 1
#define DOWN 2

volatile int timer = 0; // Tick counter, stored in RAM
volatile int lockdelay = 0; // lock delay counter, stored in RAM
int lock = 20; // TODO right value? lock delay never changes
int gravity = 60; // gravity delay starts at 1 drop / second

// Initialise the game
void initialise(){
    #ifdef DEBUG
    Serial.println("INIT");
    #endif

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            deadBlocks[i][j] = 0;
        }
    }

    counter = 0;
    shuffleBag();
    newPiece();


}

// place a piece into the dead block array
void placePiece(){
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if(currentPieceArray[i][j] != BLACK)
                deadBlocks[i+currentPieceRow][j+currentPieceCol] = currentPieceArray[i][j];
        }
    }
}

// Move a piece
void movePiece(int direction){

    #ifdef DEBUG
    Serial.println();
    Serial.print("Moving piece ");
    switch(direction){
        case LEFT: Serial.println("LEFT"); break;
        case RIGHT: Serial.println("RIGHT"); break;
        case DOWN: Serial.println("DOWN"); break;
    }
    #endif

    switch(direction){
        case LEFT:
            break;
        case RIGHT:
            break;
        case DOWN:
            if(checkBelow())
                currentPieceRow++;
            else{
                placePiece();
                newPiece();
            }
            break;
    }
    redraw();

}

// Increment the timer, and if reached gravity delay, move the piece down
void tick(){
    #ifdef DEBUG
    Serial.print("!");
    #endif

    timer++;

    if (timer > 60){
        movePiece(DOWN);
        timer = 0;
    }

}

// LCD -------------------------------------------------------------------------
#include <UTFT.h>
extern uint8_t SmallFont[]; // TODO Declares font for LCD. Small font currently, need medium font?
UTFT display(ITDB24E_8,A5,A4,A3,A2);

// Redraw the screen
void redraw(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = deadBlocks[i][j];
        }
    }

    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if(currentPieceArray[i][j] != BLACK)
                board[i+currentPieceRow][j+currentPieceCol] = currentPieceArray[i][j];
        }
    }

    #ifdef DEBUG
    Serial.println();
    for(int i = 2; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            Serial.print(board[i][j]);
        }
        Serial.println();

    }
    #endif

}


// BUTTON INTERRUPTS GO HERE ---------------------------------------------------
// Button pins
#define downbutton   XYZ
#define rotatebutton XYZ
#define leftbutton   XYZ
#define rightbutton  XYZ

// Interrupt service routines
void downButton(){
}

void rotateButton(){
}

void leftButton(){
}

void rightButton(){
}

// SETUP -----------------------------------------------------------------------
void setup(){

    #ifdef DEBUG
    Serial.begin(115200); // "Fast" serial to reduce time spent sending debug info during real time gameplay
    while(!Serial){} // Wait for Serial port to connect
    Serial.println("Debugging TETRIS by Jack Carey");
    #endif

    // Start the LCD
    display.InitLCD();
    display.setFont(SmallFont);
    // Initialise game
    initialise();
    // attach interrupts (rising means they will only fire when button is first pressed)
//    PCint::attachInterrupt(downbutton,downButton,RISING);
//    PCint::attachInterrupt(rotatebutton,rotateButton,RISING);
//    PCint::attachInterrupt(leftbutton,leftButton,RISING);
//    PCint::attachInterrupt(rightbutton,rightButton,RISING);
    // Set up the timer for 1/60th of a second
    #ifdef DEBUG
    Serial.println("Setting up timer...");
    #endif
    noInterrupts();           // disable all interrupts to set this up!
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;
    OCR1A = 1042; // 1041.66666... Has to be a whole number -- 16MHz clock/256 prescaler/60Hz, fires every ~1/60th of a second
    TCCR1B |= (1 << WGM12);   // CTC mode (clears timer after reaching compare value)
    TCCR1B |= (1 << CS12);    // 256 prescaler
    TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
    interrupts();             // enable all interrupts again
}

// TIMER INTERRUPT SERVICE ROUTINE ---------------------------------------------
ISR(TIMER1_COMPA_vect){
    tick();
}

// LOOP ------------------------------------------------------------------------
void loop(){
    // All interrupt based, nothing to see here! (until music)
}
