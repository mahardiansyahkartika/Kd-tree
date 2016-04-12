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
    std::vector<math::VectorN> Importer::csv_to_vector(const char* filename)
    {
        std::vector<math::VectorN> res;

        std::ifstream data(filename);
        std::string line;

        /// temporary container to hold value per line
        std::vector<math::real_t> temp;

        while (std::getline(data, line))
        {
            std::stringstream lineStream(line);
            std::string cell;

            /// clear the container
            temp.clear();
            while (std::getline(lineStream, cell, ','))
            {
#ifdef REAL_FLOAT
                temp.push_back(std::stof(cell));
#else
                temp.push_back(std::stod(cell));
#endif
            }

            /// create point
            math::VectorN point = math::VectorN(temp);
            /// insert to list
            res.push_back(point);

            for (size_t j = 0; j < point.GetN(); ++j)
                std::cout << point.GetVal(j) << " ";
            std::cout << std::endl;
        }

        /*
        for (size_t i = 0; i < res.size(); ++i)
        {
            std::cout << i + 1 << ": ";
            for (size_t j = 0; j < res[i].GetN(); ++j)
                std::cout << res[i].GetVal(j) << " ";
            std::cout << std::endl;
        }
        */

        return res;
    }
}
}