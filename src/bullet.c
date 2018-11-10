#include "bullet.h"
#include "entity.h"

void shot_bullet(struct map *map, struct entity *player)
{
    struct entity bullet =
    {
        .type = BULLET,
        .pos = player->pos,
        .spd = {1, 0},
        .acc = {0, 0}
    };

    add_entity(map, bullet);
}
