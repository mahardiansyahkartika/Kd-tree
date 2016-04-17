#include <iostream>

#include "tree.h"

int main(int argc, char* argv[])
{
    /// import csv file
    std::vector<uber::exercise::math::VectorN*> data_list =
        uber::exercise::Importer::csv_to_vector("sample_data.csv");

    uber::exercise::KdTree* tree = new uber::exercise::KdTree(data_list);

    // print value
    std::cout << "total_input: " << tree->data_list.size() << std::endl;

    /*
    for (size_t i = 0; i < tree->data_list.size(); ++i)
    {
        std::cout << i + 1 << ": ";
        for (size_t j = 0; j < tree->data_list[i]->get_n(); ++j)
            std::cout << tree->data_list[i]->get_val(j) << " ";
        std::cout << std::endl;
    }
    */
    
    delete tree;

    return 0;
}