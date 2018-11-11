#include "bullet.h"
#include "entity.h"

void shot_bullet(struct map *map, struct entity *player)
{
    printf("shot !\n");
    struct vector2 speed = {0, 0};

    if(player->dir == DIR_LEFT)
        speed.x = -0.8;
    else
        speed.x = 0.8;

    struct entity bullet =
    {
        .type = BULLET,
        .pos = player->pos,
        .spd = speed,
        .acc = {0, 0},
        .dir = player->dir
    };

    add_entity(map, bullet);
}
