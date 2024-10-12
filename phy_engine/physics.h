#ifndef TBT_PHYSICS_H
#define TBT_PHYSICS_H

#include "macro.h"
#include "math.h"


template <typename shape_data_t>
class object_t {
    public:
        double      mass;           // 质量
        SHAPE_T     shape;          // 形状
        shape_data_t    shape_data; // 由形状决定的具体形状数据
        double      hardness;       // 硬度

        vector_t    pos;            // 坐标
        vector_t    speed;          // 速度

    public:
        object_t(double mass, SHAPE_T shpae, shape_data_t shape_data,
                 double hardness, vector_t pos)
            : mass(mass), shape(shape), shape_data(shape_data),
              hardness(hardness), pos(pos)
        {
        }

        ~object_t()
        {
        }
};

class physics_machine_t {
    public:
};


#endif
