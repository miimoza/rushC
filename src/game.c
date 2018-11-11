#include "structs.h"
#include "entity.h"
#include "map.h"

struct GameContext *init_game()
{
    struct GameContext *game = malloc(sizeof(struct GameContext));

    char *maps[] =
    {
        "maps/lvl0.ez",
        "maps/lvl1.ez",
        "maps/lvl2.ez",
        "maps/lvl3.ez"
    };

    char *textures[] =
    {
        "maps/lvl1_textures/",
        "maps/lvl1_textures/",
        "maps/lvl1_textures/",
        "maps/lvl1_textures/"
    };

    game->cur_map = 0;
    game->nb_maps = 4;
    game->maps = parse_maps(maps, game->nb_maps, textures);
    game->map = game->maps[game->cur_map];
    game->is_playing = 1;

    return game;
}

void update_frame(struct map *map)
{


    for(int entity_i = 0; entity_i < map->nbentities; entity_i++)
    {
        update_entity(&map->entities[entity_i], 1);
        if(is_outside_map(map->entities[entity_i], map->width, map->height))
            delete_entity(map, entity_i);
    }
}

void go_next_map(struct GameContext *game)
{
    game->map = game->maps[++game->cur_map];
}
