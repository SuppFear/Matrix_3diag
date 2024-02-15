#include <iostream>
#include <vector>

class Matrix_3diag{
public:
    std::vector<double> a; // below the main diagonal
    std::vector<double> b; // the main diagonal
    std::vector<double> c; // above the main diagonal
};

std::vector<double> answer(const Matrix_3diag& A, const std::vector<double>& d);