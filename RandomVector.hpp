#include <iostream>
#include <random>
#include <vector>

#ifndef RANDOM_VECTOR
#define RANDOM_VECTOR

class RandomVector {
    public:
        std::random_device rnd_device;

        std::vector<int> random_int_vector_generater(int num, int low, int high);
        std::vector<double> random_double_vector_generater_uniform(int num, double low, double high);
        std::vector< std::vector<int> > random_int_matrix_generator (int row, int col, int low, int high);
        std::vector< std::vector <double> > random_double_matrix_generator_uniform (int row, int col, double low, double high);
        std::vector< std::vector <double> > random_double_matrix_generator_gaussian (int row, int col, double mean, double std);

};

#endif