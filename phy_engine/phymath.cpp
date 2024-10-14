#include "phymath.h"
#include <math.h>


/////////////////////////////////////////////////////
// vector_t begin
/////////////////////////////////////////////////////
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

double
vector_t::operator*(vector_t &v)
{
    return this->x * v.x + this->y * v.y;
}

vector_t
vector_t::operator*(double &n)
{
    vector_t nv(this->x * n, this->y * n);
    return nv;
}

vector_t
vector_t::operator*(int &n)
{
    vector_t nv( this->x * static_cast<double>(n), 
                 this->y * static_cast<double>(n) );
    return nv;
}

double
vector_t::modulus()
{ return sqrt(this->x * this->x + this->y * this->y); }

/////////////////////////////////////////////////////
// vector_t end, line_t begin
/////////////////////////////////////////////////////

line_t::line_t()
{
}

line_t::~line_t()
{
}
