#include <SDL.h>
#include <stdio.h>


int main(int argc, char** argv)
{

    struct GameContext game = init_game();

    while (game.is_playing)
    {
        //struct Input event = get_current_input();
        // compute new positions, sates, etc
        //update(&game, event);
        // draw the changes on the screen
        render_frame(game);
        SDL_Delay(3000);
    }

    return 0;
}
