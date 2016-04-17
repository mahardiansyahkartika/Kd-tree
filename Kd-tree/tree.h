/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include "importer.h"

namespace uber
{
namespace exercise
{
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
    size_t axis_split;
    /// a threshold that defines the splitting hyperplane
    math::real_t treshold;

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
    KdTree(std::vector<math::VectorN*>& points);
    ~KdTree();
    
    /// root of the tree
    KdTreeNode* root;

    /// list of point
    std::vector<math::VectorN*> data_list;
    
private:
    KdTreeNode* build(size_t* index_list, size_t index_size);
};
}
}