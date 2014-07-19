// View Class functions
// 2014 Chris Claoue-Long

#include <Arduino.h>
#include "View.h"




//  * This method here was how i tested my entire code. This is my test method. It was way more beneficial to me to see what the controller saw the
//  * board like at specific steps in my code.
//  * This method was used as a test class to draw the current board using ascii characters. It is no longer used during the working game.
//  * It was particuarly useful when recognising errors within the interactions of the classes when the UI was not working. For example,
//  * this class found the original errors with our piece interface, and when the game wasnt reinitialising correctly.

//void Controller::displayBoard(){
    //     for (r = ROWSIZE; r > -1 ; r--){
    //         for (c = 0; c < COLUMNSIZE; c++)
    //                 System.out.print(fullColorArray[r][c]);
    //         System.out.println(fullColorArray[r][9]);
    //     }
//}



void View::printBoard(){
   int i,j;
   for(i = 0; i < ROWS; i++){
     for(j = 0; j < COLS; j++){
         Serial.print(model->board[i][j]);
     }
     Serial.println();
   }
}


