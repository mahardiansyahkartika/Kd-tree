/// KDTree Exercise
///
/// author:
/// Mahardiansyah Kartika - mkartika@andrew.cmu.edu

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "importer.h"

namespace uber
{
namespace exercise
{
std::vector<math::VectorN*> Importer::csv_to_vector(const char* filename)
{
    std::vector<math::VectorN*> res;

    std::ifstream data(filename);
    std::string line;

    if (data.is_open())
    {
        // temporary container to hold value per line
        std::vector<math::real_t> temp;

        while (std::getline(data, line))
        {
            std::stringstream line_stream(line);
            std::string cell;

            // clear the container
            temp.clear();
            while (std::getline(line_stream, cell, ','))
            {
#ifdef REAL_FLOAT
                temp.push_back(std::stof(cell));
#else
                temp.push_back(std::stod(cell));
#endif
            }

            // create point
            math::VectorN* point = new math::VectorN(temp);
            // insert to list
            res.push_back(point);
        }

        data.close();

        std::cout << "Successfully import '" << filename << "' file" << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        exit(1);
    }

    return res;
}

KdTree* Importer::file_to_tree(const char* filename)
{
    KdTree* tree = new KdTree();

    std::ifstream data(filename);
    std::string line;

    if (data.is_open())
    {
        // read number of points
        int points_size = 0;
        if (std::getline(data, line))
            points_size = std::stoi(line);
        else
        {
            std::cout << "file is corrupted" << std::endl;
            exit(1);
        }

        // temporary container to hold value per line
        std::vector<math::real_t> temp;
        // read points data
        for (int i = 0; i < points_size; ++i)
        {
            if (std::getline(data, line))
            {
                std::stringstream line_stream(line);
                std::string cell;

                // clear the container
                temp.clear();
                while (std::getline(line_stream, cell, ','))
                {
#ifdef REAL_FLOAT
                    temp.push_back(std::stof(cell));
#else
                    temp.push_back(std::stod(cell));
#endif
                }

                // create point
                math::VectorN* point = new math::VectorN(temp);
                // insert to list
                tree->data_list.push_back(point);                
            }
            else
            {
                std::cout << "file is corrupted" << std::endl;
                exit(1);
            }
        }

        // create all nodes
        deserialize(tree->root, data);

        data.close();

        std::cout << "Successfully built tree from '" << filename << 
            "' file" << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        exit(1);
    }    

    return tree;
}

void Importer::deserialize(KdTreeNode*& node, std::ifstream& data)
{
    std::string line;

    if (std::getline(data, line))
    {
        std::stringstream line_stream(line);
        std::string cell;

        if (std::getline(line_stream, cell, ','))
        {
            // leaf
            if (std::stoi(cell) == KdTreeNodeType::LEAF)
            {
                node = new KdTreeNode();
                // set node type
                node->type = KdTreeNodeType::LEAF;

                if (std::getline(line_stream, cell, ','))
                {
                    // store data size
                    node->left.data_size = std::stoi(cell);
                    node->right.data_ref = new size_t[node->left.data_size];

                    // store references
                    if (std::getline(line_stream, cell, ','))
                    {
                        int data_size = 0;
                        std::stringstream cell_stream(cell);
                        std::string ref;

                        while (std::getline(cell_stream, ref, ' '))
                        {
                            // store each reference
                            node->right.data_ref[data_size] = std::stoi(ref);
                            data_size++;
                        }

                        if (data_size != node->left.data_size)
                        {
                            std::cout << "file is corrupted" << std::endl;
                            exit(1);
                        }
                    }
                    else
                    {
                        std::cout << "file is corrupted" << std::endl;
                        exit(1);
                    }
                }
                else
                {
                    std::cout << "file is corrupted" << std::endl;
                    exit(1);            
                }

                return;
            }
            // branch
            else if (std::stoi(cell) == KdTreeNodeType::BRANCH)
            {
                node = new KdTreeNode();
                // set node type
                node->type = KdTreeNodeType::BRANCH;

                if (std::getline(line_stream, cell, ','))
                {
                    // split axis
                    node->split_axis = std::stoi(cell);

                    if (std::getline(line_stream, cell, ','))
                    {
                        // threshold
#ifdef REAL_FLOAT
                        node->threshold = std::stof(cell);
#else
                        node->threshold = std::stod(cell);
#endif
                    }
                    else
                    {
                        std::cout << "file is corrupted" << std::endl;
                        exit(1);
                    }
                }
                else
                {
                    std::cout << "file is corrupted" << std::endl;
                    exit(1);
                }

                // recursive
                deserialize(node->left.node, data);
                deserialize(node->right.node, data);
            }
            // format error
            else
            {
                std::cout << "file is corrupted" << std::endl;
                exit(1);                
            }
        }
        else
        {
            std::cout << "file is corrupted" << std::endl;
            exit(1);
        }
    }
}
}
}