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
char deadBlocks[ROWS][COLS]; // Dead blocks that will never move again
char board[ROWS][COLS]; // The view combining piece and dead blocks
byte currentPiece; // will store the index of the currently used piece
byte currentRotation;
char currentPieceArray[4][4];
int currentPieceRow, currentPieceCol; // Top left of piece is tracked

// PIECE GENERATION AND ROTATION -----------------------------------------------
int counter = 0; // Initially choose first piece out of bag

// Shuffle the bag of tetrominoes
void shuffleBag(){
    #ifdef DEBUG
    Serial.println("Shuffling");
    #endif
}

// Grab a new piece
void newPiece(){
    #ifdef DEBUG
    Serial.println("NP");
    #endif
}

// Check the left boundary
void checkLeft(){
}

// Check the right boundary
void checkRight(){
}

// Check below
void checkBelow(){
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
}

// place a piece into the dead block array
void placePiece(){
}

// Move a piece
void movePiece(int direction){
}

// Increment the timer, and if reached gravity delay, move the piece down
void tick(){
    #ifdef DEBUG
    Serial.print("!");
    #endif
}

// LCD -------------------------------------------------------------------------
#include <UTFT.h>
extern uint8_t SmallFont[]; // TODO Declares font for LCD. Small font currently, need medium font?
UTFT display(ITDB24E_8,A5,A4,A3,A2);

// Redraw the screen
void redraw(){
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
    redraw();
}

// LOOP ------------------------------------------------------------------------
void loop(){
    // All interrupt based, nothing to see here! (until music)
}
