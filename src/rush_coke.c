#include <stdio.h>

#include "structs.h"
#include "display.h"
#include "game.h"
#include "input.h"
#include "entity.h"
#include "map.h"
#include "update.h"

int main(void)
{
    printf("test\n" );
    struct GameContext *game = init_game();
    struct map *map = game->map;
    struct display *display = init_display(map->width, map->height);

    load_textures(display, map->texture_path);


    struct input input;
    display_menu(display->renderer);

    while(1)
    {
        input = get_inputs();
        if(input.inputs[SPACE])
            break;
        if(input.inputs[QUIT])
            exit(0);
    }

    while (game->is_playing)
    {
        SDL_RenderClear(display->renderer);
        //INPUT
        printf("frame\n" );
        input = get_inputs();
        game->is_playing = !input.inputs[QUIT];

        //UPDATE
        printf("x: %f y: %f\n", map->player.pos.x, map->player.pos.y);
        if(is_outside_map(map->player, map->width, map->height))
        {
            go_next_map(game);
            map = game->map;
            load_textures(display, map->texture_path);
        }

        update_frame(map);
        update_map_entities(map);
        update_player(&map->player, map, input);

        //printf("PLAYER X: %f, PLAYER Y: %f", .pos.x, player.pos.y);

        //DRAW
        display_map(display, map);
        display_life(display);

        SDL_RenderPresent(display->renderer);
        SDL_Delay(20);
    }

    //free
    //free game
    free(game);
    //free display
    //TODO

    return 0;
}
