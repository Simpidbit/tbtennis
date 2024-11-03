#ifndef TBT_PHYSICS_H
#define TBT_PHYSICS_H


#include "object.h"

#include <vector>
#include <thread>


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

        // 物理引擎线程内部计算线程和交互线程之间的互斥锁
        std::mutex mtx_inner;

        std::thread * calculate_thread;
        std::thread * interact_thread;


    public:
        physics_machine_t();
        ~physics_machine_t();

        // 计算循环线程
        static void calculate_loop(physics_machine_t * parent);

        // 交互循环线程
        static void interact_loop(physics_machine_t * parent);

        void start_loops();
};


#endif
