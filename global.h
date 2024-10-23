#ifndef GLOBAL_H
#define GLOBAL_H



//#define TEST

#include <stdint.h>

#define SHAPE_T     uint8_t
#define CIRCLE      (0)
#define RECTANGLE   (1)
#define LINE        (2)

#define COLOR_T     uint8_t
// TODO: 定义COLOR_T的具体取值

typedef struct {
    char b1:1, b2:1, b3:1, b4:1,
        b5:1, b6:1, b7:1, b8:1;
} byte_t;



#endif // GLOBAL_H
