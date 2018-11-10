#include "input.h"
#include <SDL2/SDL.h>

#if 0
struct input
{
    int[NUMBER_KEYS] inputs;
};

enum inputtype =
{
    NOTHING = 0,
    PRESSED = 1,
    RELEASE = -1
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
    struct input input;
    SDL_Event e;
    if (SDL_PollEvent(&e))
    {
        for (int i = 0; i < NUMBER_KEYS; i++)
        {
            input.inputs[i] = NOTHING;
        }
        //QUIT
        if (e.type == SDL_QUIT)
	        input.inputs[QUIT] = PRESSED;
		else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
            input.inputs[QUIT] = RELEASE;

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            input.inputs[SPACE] = PRESSED;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE)
            input.inputs[SPACE] = RELEASE;

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
            input.inputs[LEFT] = PRESSED;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LEFT)
            input.inputs[LEFT] = RELEASE;

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
            input.inputs[RIGHT] = PRESSED;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RIGHT)
            input.inputs[RIGHT] = RELEASE;
	}
}
