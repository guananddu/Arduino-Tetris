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

#include "Controller.h"
//#include "ModelBoard.cpp" // TODO model 
#include "View.h"


Controller* control; 

ISR (TIMER_1_COMPA_vect){
	control->movePiece();  
}

void setup(){
	noInterrupts(); 
	TCCR1A = 0; 
	TCCR1B = 0; 
	TCNT1 = 0; 

	OCR1A = 31250; 
	TCCR1B |= (1 << WGM12); 
	TCCR1B |= (1 << CS12); 
	TIMSK1 |= (1 << OCR1A); 

	control = new Controller(); 

}

void loop(){
//     DO STUFF HERE
}


