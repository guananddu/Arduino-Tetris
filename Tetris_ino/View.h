// View (UI) header
// 2014 Chris Claoue-Long

#include "Model.h"

class View{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
      View(){
         model = new Model();
      }
      void printBoard();


    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
      Model* model;


    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:


};



