#include <stdio.h>

#include "map.h"
#include "game.h"
#include "display.h"

int main(void)
{
    printf("test\n" );

    struct map *map = parse_map("maps/lvl1.ez", "maps/lvl1_textures/");
    struct display *display = init_display(map->width, map->height);
    load_textures(display, map->texture_path);
    //display_map(display, map);
    //SDL_Delay(10000);

    struct GameContext *game = init_game();

    while (game->is_playing)
    {
        display_map(display, map);
        //struct Input event = get_current_input();
        // compute new positions, sates, etc
        //update(&game, event);
        // draw the changes on the screen
        //render_frame(game);
        //SDL_Delay(3000);
        SDL_Delay(10000);
        game->is_playing = 0;
    }

    //free
    //free game
    free(game);
    //free display
    //TODO

    return 0;
}
