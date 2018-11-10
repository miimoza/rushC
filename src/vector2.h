#ifndef VECTOR2_H_
#define VECTOR2_H_

struct vector2
{
    float x;
    float y;
};

struct vector2 add_vect(struct vector2 vec1, struct vector2 vec2);
struct vector2 scale_vect(float scalar, struct vector2 vec);

#endif /* !VECTOR2_H_ */
