// View (UI) header
// 2014 Chris Claoue-Long

#ifndef VIEW
#define VIEW

#include "Model.h"

class View{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
      void printBoard();

    ///////////////////////// CONSTRUCTOR/DESTRUCTOR ///////////////////////////
        View(Model* data){

            #ifdef DEBUG
            Serial.println("Creating new View");
            #endif

            model = data;
        };

        ~View(){

            #ifdef DEBUG
            Serial.println("Destroying View");
            #endif

        };


    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
      Model* model;


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:


};

#endif



