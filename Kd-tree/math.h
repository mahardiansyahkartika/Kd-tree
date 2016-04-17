/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_MATH_H
#define UBER_EXERCISE_MATH_H

#include <vector>

namespace uber
{
namespace exercise
{
namespace math
{
/// comment this out to allow double-precision arithmetic
#define REAL_FLOAT 1

#ifdef REAL_FLOAT
typedef float real_t;
#else
typedef double real_t;
#endif

/// N-dimensional vectors (points)
class VectorN
{
public:
    VectorN(std::vector<real_t>& vals);
    VectorN(VectorN* point);
    ~VectorN();

    /// set the value to specific index
    void set_val(size_t idx, real_t val);

    /// return the value from specific index
    real_t get_val(size_t idx);

    /// return vector dimension
    size_t get_n();

private:
    /// vector dimension
    size_t n = 0;

    /// components of this vector
    real_t* vals = NULL;
};
}
}
}

#endif /// UBER_EXERCISE_MATH_H