#include "physics.h"

#include "global.h"
#include "message.h"

#include <mutex>
#include <condition_variable>
#include <thread>

// 物理引擎线程和逻辑线程间的互斥锁
std::mutex mtx_phy_engine_interact;

// 是否有新消息
std::condition_variable cv_phy_engine;

// 逻辑线程向物理引擎线程申请添加/删除元素的接口
std::queue<message_t> logic_thread_request_msg;


#ifdef TEST
#include <iostream>
#endif

physics_machine_t::physics_machine_t()
{
}

physics_machine_t::~physics_machine_t()
{
    this->interact_thread->join();
    this->calculate_thread->join();

    delete this->interact_thread;
    delete this->calculate_thread;

    this->interact_thread = nullptr;
    this->calculate_thread = nullptr;
}


void
physics_machine_t::interact_loop(physics_machine_t * parent)
{
    while (true) {
        // 检查逻辑线程是否有增添物体申请
        {   // 这个块是为了在块结束时调用lock_guard的析构函数，及时解锁
            std::unique_lock<std::mutex> interact_lock(::mtx_phy_engine_interact);
            ::cv_phy_engine.wait(interact_lock);

            // condition_variable wait()函数会自动将lock解锁
            // 重新加锁
            interact_lock.lock();

            if (!::logic_thread_request_msg.empty()) {      // 有消息
                auto msg = ::logic_thread_request_msg.front();
                {   // 内部锁上锁
                    std::unique_lock<std::mutex> inner_lock(parent->mtx_inner);
                    switch (msg.msgtype) {
                    case MSG_OBJ_ADD: {         // 添加新物体
                        // 解析物体类型
                        object_pointer_t * objptr = static_cast<object_pointer_t *>(msg.attach);
                        switch (objptr->shape) {
                        case BALL: {        // 球
                            ball_t * ballptr = static_cast<ball_t *>(objptr->objdata);
                            parent->balls.push_back(*ballptr);
                        }
                        break;
                        case LINE_WALL: {   // 墙
                            // TODO...
                        }
                        break;
                        }
                    }
                    break;
                    }
                }
            }
            ::logic_thread_request_msg.pop();
        }
    }
}

void
physics_machine_t::calculate_loop(physics_machine_t * parent)
{
    { std::unique_lock<std::mutex> inner_lock(parent->mtx_inner);

    }
}

void
physics_machine_t::start_loops()
{
    this->calculate_thread = new std::thread(physics_machine_t::calculate_loop, this);
    this->interact_thread = new std::thread(physics_machine_t::interact_loop, this);
}
