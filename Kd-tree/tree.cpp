/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include "tree.h"

namespace uber
{
namespace exercise
{
    KdTreeNode::KdTreeNode() { }

    KdTreeNode::~KdTreeNode() { }

    KdTree::KdTree(std::vector<math::VectorN*>& points)
    {
        // copy points
        data_list = std::vector<math::VectorN*>(points);

        // store data_list size
        size_t index_size = data_list.size();
        // create references to data_list
        size_t* index_list = new size_t[index_size];
        for (size_t i = 0; i < index_size; ++i)
            index_list[i] = i;

        // build tree recursively
        root = build(index_list, index_size);

        delete[] index_list;
    }

    KdTree::~KdTree() { }

    KdTreeNode* KdTree::build(size_t* index_list, size_t index_size)
    {
        // end of recursion
        if (index_size == 0)
            return NULL;

        // create new node
        KdTreeNode* node = new KdTreeNode();

        // only one point left then set as leaf

        return node;
    }
}
}