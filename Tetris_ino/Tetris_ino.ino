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

#include "Controller.cpp"
#include "ModelBoard.cpp"
#include "View.cpp"

Controller control; 

ISR (TIMER_1_COMPA_vect){
	control.movePiece();  
}

void setup(){
	noInterrupts(); 
	TCCR1A = 0; 
	TCCR1B = 0; 
	TCNT1 = 0; 

	OCRIA = 31250; 
	TCCR1B |= (1 << WGM12); 
	TCCR1B |= (1 << CS12); 
	TIMSK1 |= (1 << OCIRA); 

	control = new Controller(); 

}

void loop(){
//     DO STUFF HERE
}


