// TETRIS by Jack Carey - Huge credit to Chris Claoue-Long and Abbie Wade

// Comment to disable debugging
//#define DEBUG
//#define DEBUG2
#define DEBUG3
#define DEBUG4


// Button pins
#define RESET 10
#define ROTBUTTON 13
#define DBUTTON 12
#define LBUTTON 8
#define RBUTTON  9

#define BLOCKSIZE 12 // block size on the lcd in px

#include <UTFT.h>
extern uint8_t BigFont[]; // TODO Declares font for LCD.
UTFT display(ITDB28,A5,A4,A3,A2);





// Tetrominoes -----------------------------------------------------------------
#include "tetrominoes.h" // defines Tetromino colours and matrices
// Tetromino list
char tetrominoes[25][SHAPESIZE][SHAPESIZE]   = {O1, Z1,Z2,Z3,Z4, I1,I2,I3,I4, J1,J2,J3,J4, L1,L2,L3,L4, S1,S2,S3,S4, T1,T2,T3,T4};
// Piece index list
byte pieceIndex[25]                          = {0,  1, 2, 3, 4,  5, 6, 7, 8,  9, 10,11,12, 13,14,15,16, 17,18,19,20, 21,22,23,24};
// Piece generation list (randomly shuffled for each bag)
byte pieceGenerationIndex[7]                 = {0,  1,           2,           3,           4,           5,           6,          };

bool lineClear =true;

#ifdef DEBUG
char* tetromino_letters      = ".ZIJLOST"; // Pieces printed over serial according to their colour
char* tetrominoDebug         = "OZIJLST";
#endif

bool gameOver = false;

// Board description -----------------------------------------------------------
#define ROWS 22
#define COLS 10
char deadBlocks[ROWS][COLS]; // Dead blocks that will never move again
char board[ROWS][COLS]; // The view combining piece and dead blocks
char oldBoard[ROWS][COLS]; // The previous frame
byte currentPiece; // will store the index of the currently used piece
byte currentRotation;
char currentPieceArray[4][4];
char oldPieceArray[4][4];
volatile int currentPieceRow, currentPieceCol; // Top left of piece is tracked
volatile int oldPieceRow, oldPieceCol;

// PIECE GENERATION AND ROTATION -----------------------------------------------
int counter = 0; // Initially choose first piece out of bag

// Shuffle the bag of tetrominoes
void shuffleBag(){
    #ifdef DEBUG
    Serial.println("Shuffling");
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

    #endif
}

// Grab a new piece
void newPiece(){
    
    oldPieceCol = currentPieceCol;
    oldPieceRow = currentPieceRow;

    memcpy(oldPieceArray, currentPieceArray, GRIDSIZE);

    
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
    // do any blocks overlap?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (deadBlocks[currentPieceRow+i][j+currentPieceCol-1] != BLACK && currentPieceArray[i][j] != BLACK)
                return false;
        }
    }

    // does the piece go too far left?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (currentPieceArray[i][j] != BLACK && j+currentPieceCol-1 < 0)
                return false;
        }
    }

    // all good!
    return true;
}

// Check the right boundary
bool checkRight(){
    // do any blocks overlap?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (deadBlocks[currentPieceRow+i][j+currentPieceCol+1] != BLACK && currentPieceArray[i][j] != BLACK)
                return false;
        }
    }

    // does the piece go too far right?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (currentPieceArray[i][j] != BLACK && j+currentPieceCol+1 >= COLS)
                return false;
        }
    }

    // all good!
    return true;
}

// Check below (true = fine to drop, false = can't)
bool checkBelow(){
    // do any blocks overlap?
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if (deadBlocks[currentPieceRow+i+1][j+currentPieceCol] != BLACK && currentPieceArray[i][j] != BLACK)
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

    oldPieceCol = currentPieceCol;
    oldPieceRow = currentPieceRow;
    
    memcpy(oldPieceArray, currentPieceArray, GRIDSIZE);
    
    #ifdef DEBUG
    Serial.println("ROT");
    #endif

    byte newRotation;

    switch(currentPiece){
        case 0: return; //"O" Piece - no need to rotate
        case 1:         // "Z" Piece
            if(currentRotation < 4) newRotation = currentRotation+1;
            else                    newRotation = 1;
            break;
        case 5:
            if(currentRotation < 8) newRotation = currentRotation+1;
            else                    newRotation = 5;
            break;
        case 9:
            if(currentRotation < 12) newRotation = currentRotation+1;
            else                    newRotation = 9;
            break;
        case 13:
            if(currentRotation < 16) newRotation = currentRotation+1;
            else                    newRotation = 13;
            break;
        case 17:
            if(currentRotation < 20) newRotation = currentRotation+1;
            else                    newRotation = 17;
            break;
        case 21:
            if(currentRotation < 24) newRotation = currentRotation+1;
            else                    newRotation = 21;
            break;
    }


    // Now apply rotation and check if it worked!
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            currentPieceArray[i][j] = tetrominoes[newRotation][i][j];
        }
    }

    if(!checkLeft() || !checkRight() || !checkBelow()){  //Checking if rotation overlaps or goes of the board - if true, revert.

        #ifdef DEBUG
        Serial.println("Rotate unsuccessful");
        #endif

        for(int i = 0; i < SHAPESIZE; i++){
            for(int j = 0; j < SHAPESIZE; j++){
                currentPieceArray[i][j] = tetrominoes[currentRotation][i][j];
            }
        }
    }

    else{

        #ifdef DEBUG
        Serial.println("Rotate successful");
        #endif

        currentRotation = newRotation;
    }


}


// Game Logic ------------------------------------------------------------------
#define MOVE_LEFT 0
#define MOVE_RIGHT 1
#define MOVE_DOWN 2
#define MOVE_ROTATE 3

volatile int timer = 0; // Tick counter, stored in RAM
volatile int lockdelay = 0; // lock delay counter, stored in RAM
int lock = 20; // TODO right value? lock delay never changes
int gravity = 60; // gravity delay starts at 1 drop / second

// Initialise the game
void initialise(){
    
    #ifdef DEBUG
    Serial.println("INIT");
    #endif
    
    display.setBrightness(16);//set to highest brightness

    oldPieceCol = currentPieceCol;
    oldPieceRow = currentPieceRow;

    memcpy(oldPieceArray, currentPieceArray, GRIDSIZE);

    //display picture
    display.clrScr();
    display.fillScr(200,0,50);






    

    int x1, x2, y1, y2;
    for(int i = 2; i < ROWS; i++){ // top 2 rows are hidden!
        for(int j = 0; j < COLS; j++){
            x1 = BLOCKSIZE*j + j;
            x2 = x1 + BLOCKSIZE;
            y1 = BLOCKSIZE*i + i;
            y2 = y1 + BLOCKSIZE;
            // draw the outline
            display.setColor(VGA_SILVER);
            display.drawRect(x1,y1,x2,y2); // draw a grey blank square
        }
    }


    pinMode(LBUTTON,INPUT);
    pinMode(RBUTTON,INPUT);
    pinMode(DBUTTON,INPUT);
    pinMode(RESET,INPUT);
    pinMode(ROTBUTTON,INPUT);

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            deadBlocks[i][j] = BLACK;
        }
    }
    gameOver = false;

    shuffleBag();
    newPiece();


}

// place a piece into the dead block array
void placePiece(){

    #ifdef DEBUG
    Serial.println("Placing piece");
    #endif


    if(!gameOver){
        for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            if(currentPieceArray[i][j] != BLACK){
                deadBlocks[i+currentPieceRow][j+currentPieceCol] = currentPieceArray[i][j];
            }
                
        }
    }

    }


    
    checkLineClear();
    checkGameOver();


}

// Move a piece
void movePiece(int direction){

    oldPieceCol = currentPieceCol;
    oldPieceRow = currentPieceRow;

    memcpy(oldPieceArray, currentPieceArray, GRIDSIZE);


    #ifdef DEBUG
    Serial.println();
    Serial.print("Moving piece ");
    #endif

    switch(direction){
        case MOVE_LEFT:
            if(checkLeft()){
                currentPieceCol--;
            }
            else{
//                #ifdef DEBUG
//                Serial.println("ILLEGAL (Left)");
//                #endif
            

            }
            break;
        case MOVE_RIGHT:
            if(checkRight()){
                currentPieceCol++;
            }
            else{
//                #ifdef DEBUG
//                Serial.println("ILLEGAL (Right)");
//                #endif
            }
            break;
        case MOVE_DOWN:
            if(checkBelow()){
                currentPieceRow++;
                timer = 0;
            }
            else{
                placePiece();
                newPiece();
            }
            break;
        case MOVE_ROTATE:
            rotate();
            break;
    }
                redraw();
}

//Test if a deadblock goes above the visible board

void checkGameOver(){
    if(!gameOver){

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < COLS; j++){
                if(deadBlocks[i][j] != BLACK){
                    gameOver = true;
                    #ifdef DEBUG
                    Serial.println("!GAME OVER!");
                    #endif
                    display.clrScr();
                    display.fillScr(6,101,255);
                    display.setBackColor(6,101,255);
                    delay(200);
                    // say game over!
                    display.setColor(255,90,40);
                    display.print("GAME OVER", CENTER,0); 
                    display.print("Please press", CENTER, 50); 
                    display.print("reset.", CENTER, 80); 
                    delay(1000);
                }

            }
        }
    }
}


//reinitialises the game

void reset(){
    gameOver = true;
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
            board[i][j] = BLACK;
            oldBoard[i][j] = BLACK;
        }
    }
    display.clrScr();
    display.fillScr(255,0,0);
    display.setColor(VGA_LIME);
    display.setBackColor(255,0,0);
    display.print("RESET", CENTER,50);
    delay(830);
    display.clrScr();
    delay(400);

    initialise();

}


void checkLineClear(){
    #ifdef DEBUG3
    Serial.println("Starting to check line!");
    #endif
    
    lineClear = true;
    for(int i = 0; i < SHAPESIZE; i++){
        for(int j = 0; j < SHAPESIZE; j++){
 
            if(oldPieceArray[i][j] != BLACK){
                

                // #ifdef DEBUG3
                // Serial.println("IT'S TRUE");
                // #endif
                
                    
                for(int a = 0; a < COLS; a++){
                    lineClear = true;
                    if(deadBlocks[oldPieceRow+i][a] == BLACK){
                        Serial.println("Yep - don't line clear this time.");
                        lineClear = false;
                        break;
                    }

                }

                //breaks to here

                if(lineClear == true){
                    
                    #ifdef DEBUG3
                    Serial.println("LINE CLEARING");
                    #endif
                    
                    for(int b = 0; b < COLS; b++){
                        deadBlocks[oldPieceRow+i][b] = BLACK;
                    }
                }



            }

        }
    }
    
}







// Increment the timer, and if reached gravity delay, move the piece down
void tick(){
    #ifdef DEBUG
    Serial.print("!");
    #endif

    timer++;

    if ((timer > gravity) && (gameOver == false)){
        movePiece(MOVE_DOWN);
        timer = 0;
    }

}

// LCD -------------------------------------------------------------------------






// Redraw the screen
void redraw(){

    #ifdef DEBUG2
    Serial.println("OLD PIECE");
    for(int i = 0; i<SHAPESIZE;i++){
        for(int j = 0; j<SHAPESIZE;j++){
            Serial.print(int(oldPieceArray[i][j]));
        }
        Serial.println();
    }
    Serial.println();
    Serial.println("NEW PIECE");
    for(int i = 0; i<SHAPESIZE;i++){
        for(int j = 0; j<SHAPESIZE;j++){
            Serial.print(int(currentPieceArray[i][j]));
        }
        Serial.println();
    }
    Serial.println();
    #endif
    #ifdef DEBUG4
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.print("old Row: ");
    Serial.println(oldPieceRow);
    Serial.println();
    Serial.print("old Col: ");
    Serial.println(oldPieceCol);
    Serial.println();
    Serial.print("curr Row: ");
    Serial.println(currentPieceRow);
    Serial.println();
    Serial.print("curr Col: ");
    Serial.println(currentPieceCol);
    Serial.println();
    #endif

    //make the oldBoard = board.
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            oldBoard[i][j] = board[i][j];
        }
    }

    // update the board
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
    Serial.print("Current piece is: ");
    switch(currentPiece){
        case 0: Serial.println("O"); break;
        case 1: Serial.println("Z"); break;
        case 5: Serial.println("I"); break;
        case 9: Serial.println("J"); break;
        case 13: Serial.println("L"); break;
        case 17: Serial.println("S"); break;
        case 21: Serial.println("T"); break;
    }
    Serial.print("Current row is: ");
    Serial.println(currentPieceRow);
    Serial.print("Current column is: ");
    Serial.println(currentPieceCol);
    for(int i = 2; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            Serial.print(tetromino_letters[board[i][j]]);
        }
        Serial.println();

    }
    #endif







    // draw to the LCD
    int x1, x2, y1, y2;
    for(int i = 2; i < ROWS; i++){ // top 2 rows are hidden!
        for(int j = 0; j < COLS; j++){

            if(oldBoard[i][j] != board[i][j]){  //only update lcd if something changed from oldBoard (last frame)
                x1 = BLOCKSIZE*j + j;
                x2 = x1 + BLOCKSIZE;
                y1 = BLOCKSIZE*i + i;
                y2 = y1 + BLOCKSIZE;


                // dumb way to begin with (constantly refreshing EVERYTHING!!!)
                if(board[i][j] == BLACK){
                    // clear the block
                    display.setColor(200,0,50);
                    display.fillRect(x1, y1, x2, y2);
                    
                    // draw the outline
                    display.setColor(VGA_SILVER);
                    display.drawRect(x1,y1,x2,y2); // draw a grey blank square
                }
                else{
                    switch(board[i][j]){
                        case RED: display.setColor(VGA_RED); break;
                        case CYAN: display.setColor(VGA_AQUA); break;
                        case BLUE: display.setColor(VGA_BLUE); break;
                        case ORANGE: display.setColor(255, 180, 0); break;
                        case YELLOW: display.setColor(VGA_YELLOW); break;
                        case GREEN: display.setColor(VGA_LIME); break;
                        case PURPLE: display.setColor(VGA_FUCHSIA); break;
                    }
                    

                    display.fillRect(x1,y1,x2,y2); // draw a filled square of the right colour
                }

            }
        }
    }

}


// SETUP -----------------------------------------------------------------------
void setup(){

    #ifdef DEBUG
    Serial.begin(115200); // "Fast" serial to reduce time spent sending debug info during real time gameplay
    while(!Serial){} // Wait for Serial port to connect
    Serial.println("Debugging TETRIS by Jack Carey");
    #endif

    // Start the LCD
    display.InitLCD(0); // Set as portrait mode
    display.setFont(BigFont); // Use small font for scores (if any at all!)
    display.clrScr();
    display.setBackColor(VGA_BLACK);

    // Initialise game
    initialise();
    
    //initilise pin 9 - see http://www.me.ucsb.edu/~me170c/Code/How_to_Enable_Interrupts_on_ANY_pin.pdf
    //to see list of (port?) numbers.
    // PCICR |= (1<<PCIE0);
    // PCMSK0 |= (1<<PCINT1);
    // MCUCR = (1<<ISC00) | (1<<ISC00);

    // pinMode(RBUTTON, INPUT);



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
    if(!gameOver)
        tick();
    else{

    }
}

// BUTTON INTERRUPTS GO HERE ---------------------------------------------------

// Interrupt service routines
// void downButton(){
// }

// void rotateButton(){
// }

// void leftButton(){
// }

// ISR(PCINT1_vect){
//     movePiece(MOVE_RIGHT);
// }

// LOOP ------------------------------------------------------------------------
char lastRightPress = LOW;
char lastDownPress =  LOW;
char lastLeftPress = LOW;
char lastRotPress = LOW;
char lastResPress = LOW;

void loop(){
    



    //Button Press============================================
    //Right button pressed
    if((digitalRead(RBUTTON) == HIGH) && (gameOver == false)){
        if(lastRightPress == LOW){
            movePiece(MOVE_RIGHT);
            lastRightPress = HIGH;
        }
    }

    else{
        lastRightPress = LOW;
    }

    //Left button pressed
    if((digitalRead(LBUTTON) == HIGH) && (gameOver == false)){
        if(lastLeftPress == LOW){
            movePiece(MOVE_LEFT);
            lastLeftPress = HIGH;
        }
    }

    else{
        lastLeftPress = LOW;
    }
    
    //Down button pressed
    if((digitalRead(DBUTTON) == HIGH) && (gameOver == false)){
        if(lastDownPress == LOW){
            movePiece(MOVE_DOWN);
            lastDownPress = HIGH;
        }
    }

    else{
        lastDownPress = LOW;
    }

    //Rot button pressed
    if((digitalRead(ROTBUTTON) == HIGH) && (gameOver == false)){
        if(lastRotPress == LOW){
            movePiece(MOVE_ROTATE);
            lastRotPress = HIGH;
        }
    }

    else{
        lastRotPress = LOW;
    }

    //Reset button pressed
    if(digitalRead(RESET) == HIGH){
        if(lastResPress == LOW){
            reset();
            lastResPress = HIGH;
        }
    }

    else{
        lastResPress = LOW;
    }

    //====================================================






}













