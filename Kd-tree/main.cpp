#include <iostream>

#include "importer.h"

int main(int argc, char* argv[])
{
    /// import csv file
    std::vector<uber::exercise::math::VectorN> data_list =
        uber::exercise::Importer::csv_to_vector("sample_data.csv");

    std::cout << "Hello World!" << std::endl;

    return 0;
}