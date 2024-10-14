#include "physics.h"

#ifdef TEST
#include <iostream>
#endif

///////////////////////////////////////////////
// object_t begin
///////////////////////////////////////////////

template <typename shape_data_t>
object_t<shape_data_t>::object_t(double         mass, 
                                 SHAPE_T        shpae, 
                                 shape_data_t   shape_data,
                                 vector_t       pos)
: mass(mass),               shape(shape),
  shape_data(shape_data),   pos(pos)
{
}


template <typename shape_data_t>
object_t<shape_data_t>::~object_t()
{
}


ball_t::ball_t(double         mass,         SHAPE_T   shpae,
               double         shape_data,   vector_t  pos)
    : object_t<double>::object_t(   mass,           shape,
                                    shape_data,     pos     )
{
}

///////////////////////////////////////////////
// object_t end, physics_machine_t begin
///////////////////////////////////////////////
std::mutex mtx;
void * logic_thread_request_msg;
physics_machine_t::physics_machine_t(std::vector<ball_t> ** obj_container_pptr)
{
    this->obj_container = new std::vector<ball_t>();
    *obj_container_pptr = this->obj_container;
}

physics_machine_t::~physics_machine_t()
{
    delete this->obj_container;
}


void
physics_machine_t::main_loop()
{
    while (true) {
        // 检查逻辑线程是否有增添物体申请
        {   // 这个块是为了在块结束时调用lock_guard的析构函数，及时解锁
            std::lock_guard<std::mutex> lock(mtx);
            byte_t * first_byte = static_cast<byte_t *>(::logic_thread_request_msg);
            if (first_byte->b1 & 0b1) {
                first_byte->b1 = 0;
                // 有申请
#ifdef TEST
                std::cout << "We received a request" << std::endl;
                std::cout << "Size of obj_container: " << this->obj_container->size() << std::endl;
                for (auto iter = this->obj_container->begin(); iter != this->obj_container->end(); iter++) {
                    std::cout << "mass: " << iter->mass << std::endl;
                }
                break;
#else
#endif
            }
        }
    }
}
