#include <stdio.h>

#include "structs.h"
#include "display.h"
#include "game.h"
#include "input.h"
#include "entity.h"
#include "map.h"
#include "player.h"

int main(void)
{
    printf("test\n" );

    struct map *map = parse_map("maps/lvl1.ez", "maps/lvl1_textures/");
    struct display *display = init_display(map->width, map->height);
    load_textures(display, map->texture_path);
    //display_map(display, map);
    //SDL_Delay(10000);

    struct GameContext *game = init_game();
    struct input input;

    while (game->is_playing)
    {
        //INPUT
        printf("frame\n" );
        input = get_inputs();
        game->is_playing = !input.inputs[QUIT];

        //UPDATE
        update_frame(map, input);
        update_player(&map->player, map, input);
        //printf("PLAYER X: %f, PLAYER Y: %f", .pos.x, player.pos.y);

        //DRAW
        display_map(display, map);
        SDL_Delay(20);
    }

    //free
    //free game
    free(game);
    //free display
    //TODO

    return 0;
}
