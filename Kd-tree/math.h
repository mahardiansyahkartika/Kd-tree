/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_MATH_H
#define UBER_EXERCISE_MATH_H

#include <cmath>
#include <vector>
#include <algorithm>

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
    real_t get_val(size_t idx) const;

    /// return vector dimension
    size_t get_n() const;

    VectorN operator+(const VectorN& v) const;
    VectorN operator-(const VectorN& v) const;
    VectorN operator*(real_t s) const;

    /// square length of the vector
    static real_t squared_length(const VectorN& v);
    /// returns the length of the vector
    static real_t length(const VectorN& v);
    /// calculate the positive distance between two vectors
    static real_t distance(const VectorN& lhs, const VectorN& rhs);
    /// calculate squared distance between two vectors for efficiency
    static real_t squared_distance(const VectorN& lhs, const VectorN& rhs);

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