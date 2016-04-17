/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_EXPORTER_H
#define UBER_EXERCISE_EXPORTER_H

#include <vector>

namespace uber
{
namespace exercise
{
class Exporter
{
public:
    /// export data to .csv file from list
    static void vector_to_csv(const char* filename, 
        std::vector<size_t>& nearest_index_list);
};
}
}

#endif /// UBER_EXERCISE_EXPORTER_H