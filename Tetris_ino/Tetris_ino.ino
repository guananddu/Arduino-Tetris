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

ISR (TIMER_1_COMPA_vect){
    control->movePiece('D');
}

void setup(){


    control = new Controller();

}

void loop(){
//     ONLY WORKS OFF INTERRUPTS, nothing to see here!
}




