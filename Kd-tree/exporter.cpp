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

        std::cout << "Successfully create " << filename << " file" << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        exit(1);
    }
}
}
}