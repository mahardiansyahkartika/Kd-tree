#include <iostream>

#include "importer.h"
#include "exporter.h"
#include "tree.h"

int main(int argc, char* argv[])
{
    /*
    // BUILD_KDTREE
    // import data file
    std::vector<uber::exercise::math::VectorN*> data_list =
        uber::exercise::Importer::csv_to_vector("sample_data.csv");
    // build tree
    uber::exercise::KdTree* tree = new uber::exercise::KdTree(data_list);
    // export tree
    uber::exercise::Exporter::tree_to_file("tree", tree);
    // delete tree
    delete tree;
    */

    // QUERY_KDTREE
    // import query file
    std::vector<uber::exercise::math::VectorN*> query_list =
        uber::exercise::Importer::csv_to_vector("query_data.csv");
    // import tree
    uber::exercise::KdTree* tree = uber::exercise::Importer::file_to_tree("tree");
    // find the corresponding closest index of the sample data for each query point
    std::vector<size_t> closest_index_list;
    for (size_t i = 0; i < query_list.size(); ++i)
    {
        size_t ref;
        uber::exercise::math::real_t dist = 
            std::numeric_limits<uber::exercise::math::real_t>::infinity();
        tree->search_nearest_neighbor(query_list[i], tree->root, ref, dist);
        closest_index_list.push_back(ref);
    }
    // export to csv
    uber::exercise::Exporter::vector_to_csv("result new.csv", closest_index_list);
    // delete tree
    delete tree;

    return 0;
}