#include "RandomVector.hpp"
#include <algorithm>

using namespace std;

vector<int> RandomVector::random_int_vector_generater(int num, int low, int high){

    mt19937 m_generator(rnd_device());
    vector<int> output(num);
	uniform_int_distribution<int> dist_i(low, high);
	auto gen = [&dist_i, &m_generator](){
		return dist_i(m_generator);
	};
	generate(begin(output), end(output), gen);

	return output;
}

vector<double> RandomVector::random_double_vector_generater_uniform(int num, double low, double high){
    mt19937 mersenne_engine(rnd_device());
    vector<double> output(num);
	uniform_real_distribution<double> dist_d {low, high};
	auto gen = [&dist_d, &mersenne_engine](){
		return dist_d(mersenne_engine);
	};
	generate(begin(output), end(output), gen);
	return output;
}

vector< vector<int> > RandomVector::random_int_matrix_generator (int row, int col, int low, int high){
    mt19937 mersenne_engine(rnd_device());
    vector< vector<int> > output(row);
    vector<int> one_row(col);

    uniform_int_distribution<int> dist_i {low, high};
    auto gen = [&dist_i, &mersenne_engine](){
        return dist_i(mersenne_engine);
    };

    for(int i = 0; i < row; i++){
        generate(begin(one_row), end(one_row), gen);
        output.push_back(one_row);
    }
    return output;
}

vector< vector <double> > RandomVector::random_double_matrix_generator_uniform (int row, int col, double low, double high){
    mt19937 mersenne_engine(rnd_device());
    vector< vector<double> > output(row);
    vector<double> one_row(col);

    uniform_real_distribution<double> dist_d {low, high};
    auto gen = [&dist_d, &mersenne_engine](){
        return dist_d(mersenne_engine);
    };

    for(int i = 0; i < row; i++){
        generate(begin(one_row), end(one_row), gen);
        output.push_back(one_row);
    }
    return output;
}

vector< vector<double> > RandomVector::random_double_matrix_generator_gaussian (int row, int col, double mean, double std){
    mt19937 mersenne_engine(rnd_device());
    vector< vector<double> > output(row);
    vector<double> one_row(col);

    normal_distribution<double> dist_d(mean, std);
    auto gen = [&dist_d, &mersenne_engine](){
        return dist_d(mersenne_engine);
    };

    for(int i = 0; i < row; i++){
        generate(begin(one_row), end(one_row), gen);
        output.push_back(one_row);
    }
    return output;
}