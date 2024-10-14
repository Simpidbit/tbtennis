#ifndef TB_MATH_H
#define TB_MATH_H

class vector_t {
    public:
        double x;
        double y;

    public:
        vector_t();
        vector_t(double x, double y);
        ~vector_t();

        vector_t operator+(vector_t &v);
        vector_t operator-(vector_t &v);
        vector_t operator*(vector_t &v);
        double modulus();
};

class line_t {
    public:
        line_t();
        ~line_t();
};

#endif
