
#define NUMBER_KEYS 4

struct input
{
    int inputs[NUMBER_KEYS];
};

enum keys
{
    QUIT,
    SPACE,
    LEFT,
    RIGHT
};

struct input get_inputs();
