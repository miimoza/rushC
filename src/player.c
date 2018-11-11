#include "player.h"
#include "entity.h"
#include "bullet.h"

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
        jump_count = 1;

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
