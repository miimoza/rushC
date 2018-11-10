#include "entity.h"
#include "vector2.h"

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
        get_block(map, add_vect(entity->pos, gravity_orientation));
    if (block == AIR || block == SPIKE)
            return 0;
    return 1;
}

void jump(struct entity *entity, float delta)
{
    struct vector2 jump =
    {
        0,
        JUMP_FORCE
    };
    entity->spd = add_vect(entity->spd, scale_vect(delta, jump));

}
