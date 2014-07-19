// Tetromino superclass, containing all items each tetromino MUST have.
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_SUPERCLASS // prevents errors from including it multiple times
#define TETROMINO_SUPERCLASS

class Tetromino{

    public:
        virtual char blockLetter();
        virtual int** getShape(); // returns a pointer to an int[][]
        int startPosition;
        char* colour;

        // Constructor and destructor
        Tetromino();
        virtual ~Tetromino(); // Virtual so it gets called after destroying all subclass attributes

    protected:
        int offset;

    private:
};

#endif


