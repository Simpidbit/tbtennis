#ifndef OBJECT_H
#define OBJECT_H

#include "global.h"
#include "phymath.h"

enum object_shape_e {
    BALL,
    LINE_WALL
};

// 用于形状不定的一般对象
class object_pointer_t {
public:
    object_shape_e shape;
    void * objdata;
    uint64_t objsize;

    object_pointer_t();
    ~object_pointer_t();
};


/*
    object_t: 物理对象类，基类，被具体物理对象类继承
    类模板参数: 保存具体形状数据的类
*/
template <typename shape_data_t>
class object_t {
public:
    double          mass;           // 质量
    object_shape_e  shape;          // 形状
    shape_data_t    shape_data;     // 由形状决定的具体形状数据

    vector_t    pos;                // 坐标
    vector_t    speed;              // 速度

public:
    object_t(double         mass,         object_shape_e    shpae,
             shape_data_t   shape_data,   vector_t          pos);
    ~object_t();
};


/*
    ball_t: 台球类
*/

class ball_t : public object_t<double> {
public:
    COLOR_T         color;          // 球的颜色

public:
    ball_t(double         mass,         object_shape_e      shpae,
           double         shape_data,   vector_t            pos);
};


/*
    line_wall_t: 直线型边界类，用于限制台球的运动区域
                 可以是空心多边形，边由line_t对象描述
*/
class line_wall_t : object_t<std::vector<line_t>> {
};

#endif // OBJECT_H
