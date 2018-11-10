#include "input.h"
#include <SDL2/SDL.h>

#if 0
struct input
{
    int[NUMBER_KEYS] inputs;
};

enum keys =
{
    NOTHING = 0,
    QUIT = 1,
    SPACE = 2,
    LEFT = 3,
    RIGHT = 4
};
#endif

struct input get_inputs()
{
    SDL_PumpEvents();
    struct input input;
    for (int i = 0; i < NUMBER_KEYS; i++)
    {
        input.inputs[i] = 0;
    }
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE])
        input.inputs[QUIT] = 1;
    if (state[SDL_SCANCODE_SPACE])
        input.inputs[SPACE] = 1;
    if (state[SDL_SCANCODE_LEFT])
        input.inputs[LEFT] = 1;
    if (state[SDL_SCANCODE_RIGHT])
        input.inputs[RIGHT] = 1;
    /*printf("Inputs:\n");
    /printf("QUIT: %d, SPACE: %d, LEFT: %d, RIGHT: %d\n",
            input.inputs[QUIT],
            input.inputs[SPACE],
            input.inputs[LEFT],
            input.inputs[RIGHT]);*/
    return input;
}
