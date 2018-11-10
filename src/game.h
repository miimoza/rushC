#ifndef GAME_H_
#define GAME_H_

#include "structs.h"

struct GameContext *init_game();
//void update(struct GameContext *game, struct Input event);
void update_frame(struct map *map);
#endif /* !GAME_H_ */
