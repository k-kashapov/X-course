#include "Vector.h"

int main (int argc, const char **argv)
{
    Vector vec {5, 12};
    Vector vec2{5, 12};

    vec.SetCoord (3, 4);

    vec = vec + vec + vec2;

    std::cout << vec << " of len " << vec.CalcLen() << '\n';

    vec += vec;

    std::cout << vec << " of len " << vec.CalcLen() << '\n';

    vec -= vec;

    std::cout << vec << " of len " << vec.CalcLen() << '\n';

    vec = vec2;

    std::cout << vec << " of len " << vec.CalcLen() << '\n';

    Vector vec3{-10, -500};

    vec3 = (vec2 = (vec + vec2));

    std::cout << vec3 << " of len " << vec3.CalcLen() << '\n';

    Vector vec_cp (vec2 * 10);

    std::cout << vec_cp << " of len " << vec_cp.CalcLen() << '\n';

    Vector vec0{};

    std::cout << vec0 << " of len " << vec0.CalcLen() << '\n';

    std::cout << "vec_cp == vec0: " << (vec_cp == vec0) << '\n';

    return 0;
}
