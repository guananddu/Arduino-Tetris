// Tetromino superclass, containing all items each tetromino MUST have.
// 2014 Christopher Claoue-Long

#ifndef TETROMINO_SUPERCLASS // prevents errors from including it multiple times
#define TETROMINO_SUPERCLASS

class Tetromino {
    public:
        virtual char blockLetter() = 0;

    protected:
        virtual int** getShape() = 0; // returns a pointer to an int[][]
        int startPosition;
        int offset;

    private:
};

#endif
