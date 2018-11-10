
#define NUMBER_KEYS 4

struct input
{
    int inputs[NUMBER_KEYS];
};

enum inputtype
{
    NOTHING = 0,
    PRESSED = 1,
    RELEASE = -1
};

enum keys
{
    QUIT,
    SPACE,
    LEFT,
    RIGHT
};

struct input get_inputs();
