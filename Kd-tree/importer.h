/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_IMPORTER_H
#define UBER_EXERCISE_IMPORTER_H

#include "tree.h"

namespace uber
{
namespace exercise
{
class Importer
{
public:
    /// import data from .csv file to list of VectorN
    static std::vector<math::VectorN*> csv_to_vector(const char* filename);
    /// import tree data
    static KdTree* file_to_tree(const char* filename);

private:
    static void deserialize(KdTreeNode* &node, std::ifstream& data);
};
}
}

#endif /// UBER_EXERCISE_IMPORTER_H