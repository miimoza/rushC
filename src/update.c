#include "update.h"
#include "entity.h"
#include "bullet.h"
#include "map.h"
#include "utils.h"
#include "vector2.h"

static int jump_value = 1;
static int jump_count = 0;
static int reload = RELOAD_TIME;
void update_player(struct entity *player, struct map *map, struct input input)
{
    player->spd.x = 0;
    if (input.inputs[RIGHT])
        player->spd.x = 0.15;
    if (input.inputs[LEFT])
        player->spd.x = -0.15;
    apply_gravity(player, 1);
    update_entity(player, 1);
    collision(player, map);

    if (is_on_floor(player, map))
        jump_count = jump_value;

    if (input.inputs[SPACE] && jump_count > 0)
    {
        jump(player, 1);
        jump_count--;
    }

    reload -= 1;
    if(reload < 0)
    {
        reload = RELOAD_TIME;
        if (input.inputs[SHOOT])
            shot_bullet(map, player);
    }

    printf("direction : %d %d\n", player->dir, reload);
    update_direction(player);
}

void update_map_entities(struct map *map)
{
    for (int i = 0; i < map->nbentities; i++)
    {
        int xp = map->player.pos.x + 0.5;
        int yp = map->player.pos.y + 0.5;
        int x = map->entities[i].pos.x;
        int y = map->entities[i].pos.y;
        enum blocktype block = get_block(map, map->entities[i].pos);
        struct vector2 right =
        {
            map->entities[i].pos.x + 1,
            map->entities[i].pos.y
        };
        enum blocktype block_right = get_block(map, right);

        switch (map->entities[i].type)
        {
            case BULLET:
                if (block == DBLOCK)
                    map->block[x + map->width * y] = AIR;
                if (block != AIR)
                    delete_entity(map, i);
                break;
            case ENEMY:
                if (block != AIR)
                    map->entities[i].spd.x = 0.1;
                if (block_right != AIR)
                    map->entities[i].spd.x = -0.1;
                break;
            case GUN_PICKUP:
                if (fti(map->entities[i].pos.x == xp
                            && fti(map->entities[i].pos.y == yp)))
                    delete_entity(map, i);
                break;
            case DOUBLE_JUMP_PICKUP:
                if (fti(map->entities[i].pos.x == xp
                            && fti(map->entities[i].pos.y == yp)))
                {
                    delete_entity(map, i);
                    jump_value = 2;
                }
                break;
            default:
                break;
        }
    }
}

