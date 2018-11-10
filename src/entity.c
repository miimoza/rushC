#ifndef ENTITY_H_
#define ENTITY_H_
#include "entity.h"
#include "map.h"

#if 0
enum entitytype
{
    PLAYER,
    ENEMY,
    BULLET,
    GUN_PICKUP,
    DOUBLE_JUMP_PICKUP
};

struct entity
{
    enum entitytype type;
    struct vector2 pos;
    struct vector2 spd;
    struct vector2 acc;
};
#endif

void update_entity(struct entity *entity, float delta)
{
    entity->pos = add_vect(entity->pos, scale_vect(delta, entity->spd));
    entity->spd = add_vect(entity->spd, scale_vect(delta, entity->acc));
}

void apply_gravity(struct entity *entity, float delta)
{
    struct vector2 gravity =
    {
        0,
        GRAVITY_FORCE
    };
    entity->acc = add_vect(entity->acc, scale_vect(delta, gravity));
}

int is_on_floor(struct entity *entity, struct map *map)
{
    struct vector2 gravity_orientation =
    {
        0,
        1
    };
    enum blocktype block =
        get_block(map, add_vect(entity->pos, gravity_orientation);
    if (block == AIR || block == SPIKE)
            return 0;
    return 1;
}

void jump(struct entity *entity, float delta)
{
    struct vector2 =
    {
        0,
        JUMP_FORCE
    };
    entity->spd = add_vect(entity->spd, scale_vect(delta, vector2));

}

#endif /* !ENTITY_H_ */
