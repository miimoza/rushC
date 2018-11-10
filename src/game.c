#include "SDL.h"
#include "map.h"
#include "display.h"
#include "game.h"

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
