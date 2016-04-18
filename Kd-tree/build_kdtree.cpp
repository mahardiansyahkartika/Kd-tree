#include <iostream>

#include "importer.h"
#include "exporter.h"
#include "tree.h"

void usage(char* fname)
{
    std::cout << "Usage: " << fname << 
        " [dataset_file] [exported_tree_location]" << std::endl;

    exit(0);
}

int main(int argc, char* argv[])
{
    if (argc != 3)
        usage(argv[0]);

    // BUILD_KDTREE
    // import data file
    std::vector<uber::exercise::math::VectorN*> data_list =
        uber::exercise::Importer::csv_to_vector(argv[1]);
    // build tree
    uber::exercise::KdTree* tree = new uber::exercise::KdTree(data_list);
    // export tree
    uber::exercise::Exporter::tree_to_file(argv[2], tree);
    // delete tree
    delete tree;

    return 0;
}