#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include "Misc.h"

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

    inline double GetX (void) const
    { 
        return x_;
    }

    inline double GetY (void) const
    {
        return y_; 
    }

    const Vector operator= (const Vector& vec)
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
        return
        (
            doubleEqual (x_, vec.GetX()) && 
            doubleEqual (y_, vec.GetY())
        );
    }

    bool isZero (void) const
    {
        return (doubleEqual (x_, 0) && doubleEqual (y_, 0));
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

    Vector operator - (void) const
    {
        return Vector (-x_, -y_);
    }

    double CalcLen (void);

    // Returns vector, rotated by PI clockwise
    Vector Normal  (void) const;
};

std::ostream& operator<< (std::ostream& s, Vector& vec);

#endif // VECTOR_H
