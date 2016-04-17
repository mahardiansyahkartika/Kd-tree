#include <iostream>

#include "importer.h"
#include "tree.h"

int main(int argc, char* argv[])
{
    /// import csv file
    std::vector<uber::exercise::math::VectorN*> data_list =
        uber::exercise::Importer::csv_to_vector("sample_data.csv");
    std::vector<uber::exercise::math::VectorN*> query_list =
        uber::exercise::Importer::csv_to_vector("query_data.csv");
    std::vector<size_t> closest_index_list;

    uber::exercise::KdTree* tree = new uber::exercise::KdTree(data_list);

    // find the corresponding closest index of the sample data for each query point
    for (size_t i = 0; i < query_list.size(); ++i)
        closest_index_list.push_back(tree->search_nearest_neighbor(query_list[i]));

    size_t index = 500;
    printf("index: %lu\n", index);
    printf("query: %f %f %f\n", 
        query_list[index]->get_val(0), 
        query_list[index]->get_val(1),
        query_list[index]->get_val(2));
    printf("neigh: %f %f %f\n", 
        tree->data_list[closest_index_list[index]]->get_val(0),
        tree->data_list[closest_index_list[index]]->get_val(1),
        tree->data_list[closest_index_list[index]]->get_val(2));

    std::cout << "square_dist: " << uber::exercise::math::VectorN::squared_distance(
        *(query_list[index]), *(tree->data_list[closest_index_list[index]])) << 
        std::endl;
    std::cout << "dist: " << uber::exercise::math::VectorN::distance(
        *(query_list[index]), *(tree->data_list[closest_index_list[index]])) << 
        std::endl;

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