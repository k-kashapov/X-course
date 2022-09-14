#include <iostream>
#include "cmath"

#define VECTOR_OP(op)                                      \
    Vector operator op (const Vector& val) const           \
    {                                                      \
        return Vector (x_ op val.GetX(), y_ op val.GetY());\
    }                                                      \
                                                           \
    void operator op##= (const Vector& val)                \
    {                                                      \
        x_ op##= val.GetX();                               \
        y_ op##= val.GetY();                               \
                                                           \
        len_ = NAN;                                        \
    }


class Vector
{
private:
    // len_ is updated only on demand
    double len_;
    double x_, y_;

public:
    Vector (double x, double y):
        len_ (NAN),
        x_   (x),
        y_   (y)
    {}

    Vector (void):
        len_ (0),
        x_   (0),
        y_   (0)
    {}

    Vector (const Vector& src):
        len_ (NAN),
        x_   (src.GetX()),
        y_   (src.GetY())
    {}

    ~Vector ()
    {}

    inline void SetCoord (double x, double y)
    {
        x_   = x;
        y_   = y;
        len_ = NAN;

        return;
    }

    double CalcLen (void);

    inline double GetX (void) const
    { 
        return x_;
    }

    inline double GetY (void) const
    {
        return y_; 
    }

    const Vector& operator= (const Vector& vec)
    {
        x_   = vec.GetX();
        y_   = vec.GetY();
        len_ = NAN;

        return *this;
    }

    VECTOR_OP (+);
    VECTOR_OP (-);
    VECTOR_OP (*);

#undef VECTOR_OP

    bool operator== (const Vector& vec) const
    {
        return (x_ == vec.GetX() && y_ == vec.GetY());
    }

    Vector operator * (const double scale) const
    {
        return Vector (x_ * scale, y_ * scale);
    }

    void operator *= (const double scale)
    {
        x_ *= scale;
        y_ *= scale;

        len_ *= scale;
    }

    Vector operator / (const double scale) const
    {
        return Vector (x_ / scale, y_ / scale);
    }

    void operator /= (const double scale)
    {
        x_ /= scale;
        y_ /= scale;

        len_ /= scale;
    }
};

std::ostream& operator<< (std::ostream& s, Vector& vec);
