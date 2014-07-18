// View (UI) header
// 2014 Jack Carey

#ifndef MODEL
#define MODEL

class Model{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
      Model(){
         int i,j;
         for(i = 0; i < 20; i++){
           for(j = 0; j < 10; j++){
               gameBoard[j][i] = '.';
           }
         }
      }
      char gameBoard[10][20];      



    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:



    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
    static char emptyBoard[10][20];

};


#endif
