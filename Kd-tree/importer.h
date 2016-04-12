/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include "math.h"

namespace uber
{
namespace exercise
{
class Importer
{
public:
    /// export data from .csv file to list of VectorN
    static std::vector<math::VectorN> csv_to_vector(const char* filename);
};
}
}