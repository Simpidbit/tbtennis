#include "physics.h"

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


///////////////////////////////////////////////
// object_t end, physics_machine_t begin
///////////////////////////////////////////////
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
        {       // 这个块是为了在块结束时调用lock_guard的析构函数，及时解锁
            std::lock_guard<std::mutex> lock(mtx);
            byte_t * first_byte = static_cast<byte_t *>(::logic_thread_request_area);
            if (first_byte->b1 & 0b1) {
                // 有申请
                ;
            }
        }
    }
}
