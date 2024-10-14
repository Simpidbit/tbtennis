#ifndef TBT_PHYSICS_MACRO_H
#define TBT_PHYSICS_MACRO_H

#include <cstdint>

#define SHAPE_T     uint8_t
#define CIRCLE      (0)
#define RECTANGLE   (1)
#define LINE        (2)

#define COLOR_T     uint8_t

typedef struct {
    char b1:1, b2:1, b3:1, b4:1,
         b5:1, b6:1, b7:1, b8:1;
} byte_t;

#endif
