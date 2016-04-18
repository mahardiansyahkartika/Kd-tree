/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "exporter.h"

namespace uber
{
namespace exercise
{
void Exporter::vector_to_csv(const char* filename, 
    std::vector<size_t>& nearest_index_list)
{
    std::ofstream data(filename);

    if (data.is_open())
    {
        // write all the list
        for (size_t i = 0; i < nearest_index_list.size(); ++i)
            data << nearest_index_list[i] << "\n";

        data.close();

        std::cout << "Successfully export '" << filename << "' file" << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        exit(1);
    }
}

void Exporter::tree_to_file(const char* filename, KdTree* tree)
{
    std::ofstream data(filename);

    if (data.is_open())
    {
        // write math::real_t in scientific format
        data << std::scientific;
        // write number of points
        data << tree->data_list.size() << "\n";
        // write all of the points data with a ',' for delimiter
        for (size_t i = 0; i < tree->data_list.size(); ++i)
        {
            for (size_t j = 0; j < tree->data_list[i]->get_n(); ++j)
            {
                data << tree->data_list[i]->get_val(j);
                if (j == tree->data_list[i]->get_n() - 1)
                    data << "\n";
                else 
                    data << ",";
            }
        }
        // store all of the nodes
        serialize(tree->root, data);

        data.close();

        std::cout << "Successfully export '" << filename << "' file" << std::endl;        
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        exit(1);        
    }
}

void Exporter::serialize(KdTreeNode* node, std::ofstream& data)
{
    if (node == NULL)
        return;

    // leaf
    if (node->type == KdTreeNodeType::LEAF)
    {
        // store leaf data to file
        data << node->type << "," << node->left.data_size << ",";
        // store all of the references with a " " for delimiter
        for (size_t i = 0; i < node->left.data_size; ++i)
        {
            data << node->right.data_ref[i];
            if (i == node->left.data_size - 1)
                data << "\n";
            else
                data << " ";
        }
        return;
    }

    // store branch data to file
    data << node->type << "," << node->split_axis << "," << node->threshold << "\n";
    // recursive
    serialize(node->left.node, data);
    serialize(node->right.node, data);
}
}
}