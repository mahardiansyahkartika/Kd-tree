/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#ifndef UBER_EXERCISE_TREE_H
#define UBER_EXERCISE_TREE_H

#include "math.h"

namespace uber
{
namespace exercise
{
#define MAX_TREE_DEPTH 30

enum KdTreeNodeType { BRANCH, LEAF };

class KdTreeNode
{
public:
    union Child
    {
        KdTreeNode* node;
        size_t* data_ref;
        size_t data_size;
    };

    KdTreeNode();
    ~KdTreeNode();

    /// node type
    KdTreeNodeType type;
    /// an axis or dimension of the vector to split on
    size_t split_axis;
    /// a threshold that defines the splitting hyperplane
    math::real_t threshold;
    /// pointer to left children for branch-node
    /// size of points for leaf-node
    Child left;
    /// pointer to right children for branch-node
    /// list of points for leaf-node
    Child right;
};

class KdTree
{
public:
    KdTree();
    KdTree(std::vector<math::VectorN*>& points);
    ~KdTree();

    /// root of the tree
    KdTreeNode* root;
    /// list of point
    std::vector<math::VectorN*> data_list;

    /// find the corresponding closest index of the sample data 
    /// for each query point and put the result on closest_index_list
    void search_closest_index(std::vector<size_t>& closest_index_list, 
        const std::vector<uber::exercise::math::VectorN*>& query_list);

private:
    /// search for the nearest neighbor in the tree given a query point
    void search_nearest_neighbor(math::VectorN* point, KdTreeNode* node, 
        size_t& ref_point, math::real_t& dist);

    /// delete tree
    void delete_tree(KdTreeNode* node);

    /// recursively build the tree
    KdTreeNode* build(size_t* index_list, size_t index_size, size_t depth);
    
    /// finding the axis with the largest range
    size_t find_longest_axis(size_t* index_list, size_t index_size);
    
    /// finding the split point to be the median
    math::real_t find_threshold(size_t* index_list, size_t index_size, 
        size_t split_axis);
};
}
}

#endif /// UBER_EXERCISE_TREE_H