#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>


using namespace std;

template<typename T>
void saveVectorToFile(const vector<T>& vec, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    copy(vec.begin(), vec.end(), ostream_iterator<T>(file, "\n"));
    file.close();
}

template<typename T>
vector<T> loadVectorFromFile(const string& filename) {
    vector<T> vec;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return vec;
    }

    T value;
    while (file >> value) {
        vec.push_back(value);
    }

    file.close();
    return vec;
}