// Main Tetris program
// 2014 Chris Claoue-Long

// Comment this out to stop DEBUG over serial
#define DEBUG

// include the needed subparts
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>

using namespace std;


// Include all files here to ensure that they are compiled properly by the Arduino IDE
#include "TETROMINOES.h"
#include "MinoFactory.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"

/*
intrupt with left button function(){
    //movePiece('L');
    Serial.println("Left button pressed");
}
*/

Controller* control;
View* view;
Model* model;



void setup(){

    #ifdef DEBUG
    Serial.begin(115200); // "Fast" serial to reduce time spent sending debug info during real time gameplay
    while(!Serial){} // Wait for Serial port to connect
    Serial.println("Debugging TETRIS by Jack Carey");
    #endif
    model = new Model();
    view = new View(model);
    control = new Controller(model,view);

    // Set up the timer
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;
    OCR1A = 1042; // 1041.66666... Has to be a whole number -- compare match register 16MHz clock/256 prescaler/60Hz to fire every ~1/60th of a second
    TCCR1B |= (1 << WGM12);   // CTC mode (clears timer after reaching OCR1A value)
    TCCR1B |= (1 << CS12);    // 256 prescaler
    TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
    interrupts();             // enable all interrupts again

}

ISR(TIMER1_COMPA_vect){          // timer interrupt service routine

    #ifdef DEBUG
    Serial.print("!"); // Symbol over Serial for the timer interrupt firing
    #endif

//    control->movePiece('D');
    control->redraw();
}

void loop(){
//     ONLY WORKS OFF INTERRUPTS, nothing to see here!
}

