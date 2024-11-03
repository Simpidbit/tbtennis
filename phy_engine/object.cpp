#include "object.h"


object_pointer_t::object_pointer_t()
{

}

object_pointer_t::~object_pointer_t()
{

}

template <typename shape_data_t>
object_t<shape_data_t>::object_t(double         mass,           object_shape_e        shape,
                                 shape_data_t   shape_data,     vector_t              pos)
    : mass(mass),               shape(shape),
    shape_data(shape_data),   pos(pos)
{
}


template <typename shape_data_t>
object_t<shape_data_t>::~object_t()
{
}


ball_t::ball_t(double         mass,         object_shape_e      shape,
               double         shape_data,   vector_t            pos)
    : object_t<double>::object_t(   mass,           shape,
                                 shape_data,     pos     )
{
}
