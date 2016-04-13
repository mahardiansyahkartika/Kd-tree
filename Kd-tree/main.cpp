#include <iostream>

#include "importer.h"

int main(int argc, char* argv[])
{
    /// import csv file
    std::vector<uber::exercise::math::VectorN*> data_list =
        uber::exercise::Importer::csv_to_vector("sample_data.csv");

    // print value
    for (size_t i = 0; i < data_list.size(); ++i)
    {
        std::cout << i + 1 << ": ";
        for (size_t j = 0; j < data_list[i]->get_n(); ++j)
            std::cout << data_list[i]->get_val(j) << " ";
        std::cout << std::endl;
    }


    std::cout << "Hello World!" << std::endl;

    return 0;
}