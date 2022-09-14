#include "Vector.h"

std::ostream& operator<< (std::ostream& s, Vector& vec)
{
    return s << "(" << vec.GetX() << ", " << vec.GetY() << ")";
}

double Vector::CalcLen (void)
{
    if (std::isnan (len_))
    {
        len_ = sqrt (x_ * x_ + y_ * y_);
    }

    return len_;
}
