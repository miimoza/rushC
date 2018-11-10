#include <stdio.h>

#include "map.h"
#include "game.h"
#include "display.h"

int main(int argc, char** argv)
{
    printf("test\n" );

    struct map *map = parse_map("maps/lvl1.ez", "maps/lvl1_textures/");
    printf("test\n" );
    struct display *display = init_display(map->width, map->height);
    printf("test\n" );
    load_textures(display, map->texture_path);
    printf("test\n" );
    display_map(display, map);
    printf("test\n" );
    SDL_Delay(10000);
    printf("test\n" );
/*
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
*/
    return 0;
}
