#ifndef TBT_PHYSICS_H
#define TBT_PHYSICS_H

#include "macro.h"
#include "math.h"

#include <mutex>
#include <vector>

/*
    object_t: 物理对象类，基类，被具体物理对象类继承
    类模板参数: 保存具体形状数据的类
*/
template <typename shape_data_t>
class object_t {
    public:
        double          mass;           // 质量
        SHAPE_T         shape;          // 形状
        shape_data_t    shape_data;     // 由形状决定的具体形状数据

        vector_t    pos;                // 坐标
        vector_t    speed;              // 速度

    public:
        object_t(double         mass,         SHAPE_T   shpae,
                 shape_data_t   shape_data,   vector_t  pos);
        ~object_t();
};


/*
    ball_t: 台球类
*/

class ball_t : object_t<double> {
    public:
        COLOR_T         color;          // 球的颜色
};


/*
    line_wall_t: 直线型边界类，用于限制台球的运动区域
                 可以是空心多边形，边由line_t对象描述
*/
class line_wall_t : object_t<std::vector<line_t>> {
};


/*
    physics_machine_t: 物理引擎类，由线程调用的启动函数实例化，
        并负责物理对象的运动模拟.启动函数启动时接收一个二级指针，
        表示储存与逻辑线程共享的物体运动状态数据的内存地址，
        这个指针指向存储存储物理对象的容器的指针，并在
        实例化physics_machine_t时被传入构造函数

    logic_thread_request_area: 当逻辑线程需要向物理引擎申请增加物体时，
        申请信息写入logic_thread_request_area，需要加锁.
*/
class physics_machine_t {
    public:
        // 台球
        std::vector<ball_t>             balls;

        // 直线型边界
        std::vector<line_wall_t>        line_walls;

        // 重力加速度
        double                          gravity;

        // 滚动摩擦因数
        double                          fric_coeff;

        // 指向存储物理对象的容器
        std::vector<ball_t> *           obj_container;

    public:
        physics_machine_t(std::vector<ball_t> ** obj_container_pptr);
        ~physics_machine_t();

        // 主循环
        void main_loop();
};


#endif
