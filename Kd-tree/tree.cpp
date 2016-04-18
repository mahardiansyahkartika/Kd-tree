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
    root = build(index_list, index_size, 1);

    delete[] index_list;
}

KdTree::~KdTree() 
{ 
    // delete all nodes in the tree
    delete_tree(root);

    // delete all data_list
    for (size_t i = 0; i < data_list.size(); ++i)
        delete data_list[i];
}

void KdTree::delete_tree(KdTreeNode* node)
{
    if (node != NULL)
    {
        if (node->type == KdTreeNodeType::BRANCH)
        {
            // delete the node post order
            delete_tree(node->left.node);
            delete_tree(node->right.node);
        }
        else if (node->type == KdTreeNodeType::LEAF)
        {
            delete[] node->right.data_ref;
        }

        delete node;
    }
}

KdTreeNode* KdTree::build(size_t* index_list, size_t index_size, size_t depth)
{
    // end of recursion
    if (index_size == 0)
        return NULL;

    // create new node
    KdTreeNode* node = new KdTreeNode();

    // reach max depht or only one point left 
    // then set as leaf
    if (index_size == 1 || depth >= MAX_TREE_DEPTH)
    {
        // set node type
        node->type = KdTreeNodeType::LEAF;

        // store references or points
        node->left.data_size = index_size;
        node->right.data_ref = new size_t[index_size];
        for (size_t i = 0; i < index_size; ++i)
            node->right.data_ref[i] = index_list[i];

        return node;
    }

    // set node type
    node->type = KdTreeNodeType::BRANCH;
    // find splitting axis
    node->split_axis = find_longest_axis(index_list, index_size);
    // find the threshold
    node->threshold = find_threshold(index_list, index_size, node->split_axis);

    // find reference data for left and right nodes
    std::vector<size_t> left_data_list;
    std::vector<size_t> right_data_list;
    
    for (size_t i = 0; i < index_size; ++i)
    {
        if (data_list[index_list[i]]->get_val(node->split_axis) < node->threshold)
            left_data_list.push_back(index_list[i]);
        else
            right_data_list.push_back(index_list[i]);
    }

    // copy the size of the data
    size_t left_index_size = left_data_list.size();
    size_t right_index_size = right_data_list.size();

    // create index_list for left and right nodes
    // overwrite the index_list
    size_t* left_index_list = index_list;
    size_t* right_index_list = index_list + left_index_size;

    // copy to new value list to new data_list
    for (size_t i = 0; i < left_index_size; ++i)
        left_index_list[i] = left_data_list[i];
    for (size_t i = 0; i < right_index_size; ++i)
        right_index_list[i] = right_data_list[i];

    // recursive
    node->left.node = build(left_index_list, left_index_size, depth + 1);
    node->right.node = build(right_index_list, right_index_size, depth + 1);

    return node;
}

void KdTree::search_nearest_neighbor(math::VectorN* point, KdTreeNode* node, 
        size_t& ref_point, math::real_t& dist)
{
    // leaf case
    if (node->type == KdTreeNodeType::LEAF)
    {
        for (size_t i = 0; i < node->left.data_size; ++i)
        {
            size_t curr_res = node->right.data_ref[i];
            math::real_t new_dist = 
                math::VectorN::distance(*point, *(data_list[curr_res]));        

            if (new_dist < dist)
            {
                dist = new_dist;
                ref_point = curr_res;
            }
        }
    }
    else
    {
        bool is_search_left = false;
        if (point->get_val(node->split_axis) < node->threshold)
            is_search_left = true;

        // left
        if (is_search_left)
        {
            if (point->get_val(node->split_axis) - dist < node->threshold)
                search_nearest_neighbor(point, node->left.node, ref_point, dist);
            if (point->get_val(node->split_axis) + dist >= node->threshold)
                search_nearest_neighbor(point, node->right.node, ref_point, dist);
        }
        // right
        else
        {
            if (point->get_val(node->split_axis) + dist >= node->threshold)
                search_nearest_neighbor(point, node->right.node, ref_point, dist);
            if (point->get_val(node->split_axis) - dist < node->threshold)
                search_nearest_neighbor(point, node->left.node, ref_point, dist);
        }
    }
}

size_t KdTree::find_longest_axis(size_t* index_list, size_t index_size)
{
    math::VectorN min = math::VectorN(data_list[index_list[0]]);
    math::VectorN max = math::VectorN(data_list[index_list[0]]);

    size_t n = min.get_n();

    // find min and max for every dimension
    for (size_t i = 1; i < index_size; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            math::real_t val = data_list[index_list[i]]->get_val(j);
            // find min
            if (min.get_val(j) > val)
                min.set_val(j, val);
            // find max
            if (max.get_val(j) < val)
                max.set_val(j, val);
        }
    }

    // find the length for every dimension
    std::vector<math::real_t> vector_length = std::vector<math::real_t>(n);
    for (size_t i = 0; i < n; ++i)
        vector_length[i] = max.get_val(i) - min.get_val(i);

    // find axis with longest distance
    size_t longest_axis = 0;
    for (size_t i = 1; i < n; ++i)
        if (vector_length[longest_axis] < vector_length[i])
            longest_axis = i;

    return longest_axis;
}

math::real_t KdTree::find_threshold(size_t* index_list, size_t index_size,
    size_t split_axis)
{
    // create list of value in split axis
    std::vector<math::real_t> axis_val_list;
    // insert the value
    for (size_t i = 0; i < index_size; ++i)
        axis_val_list.push_back(data_list[index_list[i]]->get_val(split_axis));
    // sort the value
    std::sort(axis_val_list.begin(), axis_val_list.end());

    // find median value
    size_t mid_index = axis_val_list.size() / 2;
    // odd
    if (axis_val_list.size() % 2)
        return axis_val_list[mid_index];    
    // even
    return 
        (axis_val_list[mid_index - 1] + axis_val_list[mid_index]) / (math::real_t)2.0;
}
}
}