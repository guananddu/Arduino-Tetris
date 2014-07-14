// Tetromino superclass, containing all items each tetromino MUST have.
// 2014 Christopher Claoue-Long
// refer to Z tetromino for code info/comments
#ifndef TETROMINO_SUPERCLASS // prevents errors from including it multiple times
#define TETROMINO_SUPERCLASS

class Tetromino {
    public:
        virtual char blockLetter();
        Tetromino generate();

    protected:
        virtual int** getShape(); // returns a pointer to an int[][]
        int startPosition;
        int offset;

    private:
};

#endif

