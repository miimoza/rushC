//#ifndef ENTITY_H_
//#define ENTITY_H_
#include "vector2.h"
#include "map.h"

#define GRAVITY_FORCE 0.1
#define JUMP_FORCE 1

#define NB_ENT_TYPES 5

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

void update_entity(struct entity *entity, float delta);
void apply_gravity(struct entity *entity, float delta);
int is_on_floor(struct entity *entity, struct map *map);
void jump(struct entity *entity, float delta);

//#endif /* !ENTITY_H_ */
