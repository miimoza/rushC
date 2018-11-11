#include "structs.h"
#include "entity.h"
struct GameContext *init_game()
{
    struct GameContext *game = malloc(sizeof(struct GameContext));
    //game.maps = parse_maps(&game.nb_maps);
    //game.map = game.maps[game.cur_map];

    game->is_playing = 1;
    //game.cur_map = 0;

    //game.display = init_display(game.map->width, game.map->height);
    //load_textures(game.display, game.map->texture_path);

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
