#include <stdio.h>

#include "map.h"
#include "game.h"
#include "display.h"
#include "input.h"


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

    int jump_count = 0;

    while (game->is_playing)
    {
        //INPUT
        input = get_inputs();
        game->is_playing = !input.inputs[QUIT];

        //UPDATE
        map->entities[1].spd.x = 0;
        if (input.inputs[RIGHT])
            map->entities[1].spd.x = 0.15;
        if (input.inputs[LEFT])
            map->entities[1].spd.x = -0.15;
        apply_gravity(&map->entities[1], 1);
        update_entity(&map->entities[1], 1, map);

        if (is_on_floor(&map->entities[1], map))
            jump_count = 1;

        if (input.inputs[SPACE] && jump_count > 0)
        {
            jump(&map->entities[1], 1);
            jump_count--;
        }
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
