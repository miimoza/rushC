#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"
#include "map.h"
#include "display.h"

struct GameContext
{
    struct map **maps;
    struct map *map;
    int is_playing;
    int nb_maps;
    int cur_map;
};

struct GameContext init_game();
//void update(struct GameContext *game, struct Input event);
void end_game(struct GameContext game);

#endif /* !GAME_H_ */
