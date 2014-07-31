#ifndef TETROMINOES
#define TETROMINOES

// COLOUR
#define BLACK   0
#define RED     1
#define CYAN    2
#define BLUE    3
#define ORANGE  4
#define YELLOW  5
#define GREEN   6
#define PURPLE  7

// Shape size
#define SHAPESIZE 4

// Z (red)
#define Z1 { \
    {1, 1, 0, 0}, \
    {0, 1, 1, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define Z2 { \
    {0, 0, 1, 0}, \
    {0, 1, 1, 0}, \
    {0, 1, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define Z3 { \
    {0, 0, 0, 0}, \
    {1, 1, 0, 0}, \
    {0, 1, 1, 0}, \
    {0, 0, 0, 0}, \
}
#define Z4 { \
    {0, 1, 0, 0}, \
    {1, 1, 0, 0}, \
    {1, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}

// I (cyan)
#define I1 { \
    {0, 0, 0, 0}, \
    {2, 2, 2, 2}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define I2 { \
    {0, 0, 2, 0}, \
    {0, 0, 2, 0}, \
    {0, 0, 2, 0}, \
    {0, 0, 2, 0}, \
}
#define I3 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {2, 2, 2, 2}, \
    {0, 0, 0, 0}, \
}
#define I4 { \
    {0, 2, 0, 0}, \
    {0, 2, 0, 0}, \
    {0, 2, 0, 0}, \
    {0, 2, 0, 0}, \
}

// J (blue)
#define J1 { \
    {3, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define J2 { \
    {0, 3, 3, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define J3 { \
    {0, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 3, 0}, \
    {0, 0, 0, 0}, \
}
#define J4 { \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
    {3, 3, 0, 0}, \
    {0, 0, 0, 0}, \
}

// L (orange)
#define L1 { \
    {0, 0, 4, 0}, \
    {4, 4, 4, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define L2 { \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 4, 0}, \
    {0, 0, 0, 0}, \
}
#define L3 { \
    {0, 0, 0, 0}, \
    {4, 4, 4, 0}, \
    {4, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define L4 { \
    {4, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 0, 0, 0}, \
}

// O (yellow)
#define O1 { \
    {0, 5, 5, 0}, \
    {0, 5, 5, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}

// S (green)
#define S1 { \
    {0, 6, 6, 0}, \
    {6, 6, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define S2 { \
    {0, 6, 0, 0}, \
    {0, 6, 6, 0}, \
    {0, 0, 6, 0}, \
    {0, 0, 0, 0}, \
}
#define S3 { \
    {0, 0, 0, 0}, \
    {0, 6, 6, 0}, \
    {6, 6, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define S4 { \
    {6, 0, 0, 0}, \
    {6, 6, 0, 0}, \
    {0, 6, 0, 0}, \
    {0, 0, 0, 0}, \
}

// T (purple)
#define T1 { \
    {0, 7, 0, 0}, \
    {7, 7, 7, 0}, \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define T2 { \
    {0, 7, 0, 0}, \
    {0, 7, 7, 0}, \
    {0, 7, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define T3 { \
    {0, 0, 0, 0}, \
    {7, 7, 7, 0}, \
    {0, 7, 0, 0}, \
    {0, 0, 0, 0}, \
}
#define T4 { \
    {0, 7, 0, 0}, \
    {7, 7, 0, 0}, \
    {0, 7, 0, 0}, \
    {0, 0, 0, 0}, \
}

#endif


