#ifndef UPDATE_H_
#define UPDATE_H_
#include "structs.h"

void update_player(struct entity *player, struct map *map, struct input input);
void update_map_entities(struct map *map);

#endif /* !UPDATE_H_ */
