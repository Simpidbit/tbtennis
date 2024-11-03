#ifndef GLOBAL_H
#define GLOBAL_H

//#define TEST

#include <stdint.h>
#include <mutex>
#include <queue>
#include <condition_variable>


#define COLOR_T     uint8_t
// TODO: 定义COLOR_T的具体取值


typedef struct {
    char b1:1, b2:1, b3:1, b4:1,
        b5:1, b6:1, b7:1, b8:1;
} byte_t;


// 物理引擎线程和逻辑线程间的互斥锁
extern std::mutex mtx_phy_engine_interact;

// 逻辑线程向物理引擎线程申请添加/删除元素的接口
class message_t;
extern std::queue<message_t> logic_thread_request_msg;

// 是否有新消息
extern std::condition_variable cv_phy_engine;

#endif // GLOBAL_H
