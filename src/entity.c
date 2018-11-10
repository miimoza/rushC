#include <math.h>
#include "entity.h"
#include "vector2.h"
#include "utils.h"
#include "map.h"

void update_entity(struct entity *entity, float delta, struct map *map)
{
    entity->pos = add_vect(entity->pos, scale_vect(delta, entity->spd));
    entity->spd = add_vect(entity->spd, scale_vect(delta, entity->acc));
    if (is_on_floor(entity, map))
    {
        entity->acc.y = 0;
        entity->spd.y = 0;
        entity->pos.y = fti(entity->pos.y);
    }
    if (is_on_ceilling(entity, map))
    {
        entity->spd.y = 0;
        entity->pos.y = fti(entity->pos.y) + 1;
    }
    if (is_on_right_wall(entity, map))
    {
        entity->spd.x = 0;
        entity->pos.x = fti(entity->pos.x);
        entity->pos.y = fti(entity->pos.y) - 1;
    }
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
        get_block(map, add_vect(entity->pos, gravity_orientation));
    printf("Block: %d\n", block);
    if (block == AIR || block == SPIKE)
            return 0;
    return 1;
}

int is_on_ceilling(struct entity *entity, struct map *map)
{
    struct vector2 orientation =
    {
        0,
        -1
    };
    struct vector2 real_pos =
    {
        0,
        1
    };
    enum blocktype block =
        get_block(map, add_vect(add_vect(entity->pos, real_pos), orientation));
    printf("Block: %d\n", block);
    if (block == AIR || block == SPIKE)
            return 0;
    return 1;
}

int is_on_right_wall(struct entity *entity, struct map *map)
{
    struct vector2 orientation =
    {
        1,
        0
    };
    struct vector2 real_pos =
    {
        -1,
        0
    };
    enum blocktype block =
        get_block(map, add_vect(add_vect(entity->pos, real_pos), orientation));
    printf("Block: %d\n", block);
    if (block == AIR || block == SPIKE)
            return 0;
    return 1;
}

void jump(struct entity *entity, float delta)
{
    struct vector2 jump =
    {
        0,
        -JUMP_FORCE
    };
    //entity->spd = scale_vect(delta, jump);
    entity->spd = add_vect(entity->spd, scale_vect(delta, jump));

}
