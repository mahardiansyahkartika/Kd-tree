#include <iostream>

#include "importer.h"
#include "exporter.h"
#include "tree.h"

void usage(char* fname)
{
    std::cout << "Usage: " << fname << 
        " [query_file] [exported_tree_file] [output_file]" << std::endl;

    exit(0);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        usage(argv[0]);

    // QUERY_KDTREE
    // import query file
    std::vector<uber::exercise::math::VectorN*> query_list =
        uber::exercise::Importer::csv_to_vector(argv[1]);
    // import tree
    uber::exercise::KdTree* tree = uber::exercise::Importer::file_to_tree(argv[2]);
    // find the corresponding closest index of the sample data for each query point
    std::vector<size_t> closest_index_list;
    tree->search_closest_index(closest_index_list, query_list);
    // export to csv
    uber::exercise::Exporter::vector_to_csv(argv[3], closest_index_list);
    // delete tree
    delete tree;

    return 0;
}