// Main Tetris program
// 2014 Chris Claoue-Long

// include the needed subparts
#include <stdlib.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

// Comment this out to stop DEBUG over serial
#define DEBUG

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
    // Set up the timer
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;

    OCR1A = 31250;            // compare match register 16MHz/256/2Hz
    TCCR1B |= (1 << WGM12);   // CTC mode
    TCCR1B |= (1 << CS12);    // 256 prescaler
    TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
    interrupts();             // enable all interrupts

    #ifdef DEBUG
    Serial.begin(115200); // "Fast" serial to reduce time spent sending debug info during real time gameplay
    while(!Serial){} // Wait for Serial port to connect

    Serial.println("Debugging TETRIS by Jack Carey");

    #endif
//    model = new Model();
//    view = new View(model);
//    control = new Controller(model,view);

}

ISR(TIMER1_COMPA_vect){          // timer interrupt service routine
    Serial.println("TIMER INTERRUPT");
//    control->movePiece('D');
//    view->printBoard();
}

void loop(){
//     ONLY WORKS OFF INTERRUPTS, nothing to see here!
}



