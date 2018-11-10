#ifndef ENTITY_H_
#define ENTITY_H_

#define GRAVITY_FORCE 0.0025
#define JUMP_FORCE 0.25


#include "structs.h"


void update_entity(struct entity *entity, float delta, struct map *map);
void apply_gravity(struct entity *entity, float delta);
int is_on_floor(struct entity *entity, struct map *map);
int is_on_ceilling(struct entity *entity, struct map *map);
int is_on_right_wall(struct entity *entity, struct map *map);

void jump(struct entity *entity, float delta);
void add_entity(struct map *map, struct entity entity);
void update_direction(struct entity *entity);
void delete_entity(struct map *map, struct entity entity);
int entities_are_equal(struct entity ent1, struct entity ent2);
void add_entity(struct map *map, struct entity entity);

#endif /* !ENTITY_H_ */
