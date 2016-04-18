/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_EXPORTER_H
#define UBER_EXERCISE_EXPORTER_H

#include "tree.h"

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
    /// export tree to file
    static void tree_to_file(const char* filename, KdTree* tree);

private:
    static void serialize(KdTreeNode* node, std::ofstream& data);
};
}
}

#endif /// UBER_EXERCISE_EXPORTER_H