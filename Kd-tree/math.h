/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

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
    VectorN();
    ~VectorN();

    void SetVal(size_t idx, real_t val);
    real_t GetVal(size_t idx);

private:
    /// vector dimension
    size_t n;

    /// components of this vector
    real_t *val;
};
};
}
}