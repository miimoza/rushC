#ifndef ENTITY_H_
#define ENTITY_H_

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
};

#endif /* !ENTITY_H_ */
