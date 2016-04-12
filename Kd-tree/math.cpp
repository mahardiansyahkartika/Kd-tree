/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include <assert.h>
#include <iostream>
#include <new>

#include "math.h"

namespace uber
{
namespace exercise
{
namespace math
{
    VectorN::VectorN(std::vector<real_t>& vals)
    {
        this->vals = new (std::nothrow) real_t[vals.size()];
        if (this->vals == nullptr)
        {
            std::cout << "[Error] memory could not be allocated" << std::endl;
            exit(EXIT_FAILURE);
        }

        /// set size
        n = vals.size();

        /// copy the values
        for (size_t i = 0; i < n; ++i)
            this->vals[i] = vals[i];
    }

    VectorN::~VectorN()
    {
        if (vals != NULL)
            delete[] vals;
    }

    void VectorN::SetVal(size_t idx, real_t val)
    {
        assert(("[Error] index out of range", (idx >= 0 && idx < n)));
        vals[idx] = val;
    }

    real_t VectorN::GetVal(size_t idx)
    {
        assert(("[Error] index out of range", (idx >= 0 && idx < n)));
        return vals[idx];
    }

    size_t VectorN::GetN()
    {
        return n;
    }
};
}
}