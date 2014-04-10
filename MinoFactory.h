// Tetromino Factory Header
// 2014 Abbie Wade

#include "Tetromino/TETROMINOES.h"

class MinoFactory{

    ///////////////////////// PUBLIC ATTRIBUTES ////////////////////////////////
    public:
	
    ///////////////////////// PROTECTED ATTRIBUTES /////////////////////////////
    protected:
        Tetromino newPiece();

    ///////////////////////// PRIVATE ATTRIBUTES ///////////////////////////////
    private:
        Tetromino[] generatedPieces = {new I_Tetromino(),
		new J_Tetromino(), new L_Tetromino(), new O_Tetromino(), 
		new T_Tetromino(), new S_Tetromino(), new Z_Tetromino()};
        
	int counter;
        void shuffleIntArray();
		int[] generation = {0,1,2,3,4,5,6};
    ///////////////////////// CONSTRUCTOR //////////////////////////////////////
    MinoFactory(){
        counter = 0;
    }


};
