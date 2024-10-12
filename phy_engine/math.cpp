#include "math.h"
#include <cmath>

vector_t::vector_t()
{
    this->x = 0.0;
    this->y = 0.0;
}

vector_t::vector_t(double x, double y)
    : x(x), y(y)
{
}

vector_t::~vector_t()
{
}

vector_t
vector_t::operator+(vector_t &v)
{
    vector_t nv(v.x + this->x, v.y + this->y);
    return nv;
}

vector_t
vector_t::operator-(vector_t &v)
{
    vector_t nv(this->x - v.x, this->y - v.y);
    return nv;
}

vector_t
vector_t::operator*(vector_t &v)
{
    vector_t nv(this->x * v.x, this->y * v.y);
    return nv;
}

double
vector_t::modulus()
{ return sqrt(this->x * this->x + this->y * this->y); }

