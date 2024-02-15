#include "3diag.h"

std::vector<double> answer (const Matrix_3diag& A, const std::vector<double>& d){
    unsigned int n = (unsigned int)(d.size());
    std::vector<double> p = std::vector<double>(n);
    std::vector<double> q = std::vector<double>(n);
    std::vector<double> x = std::vector<double>(n);
    p[1] = - A.c[0] / A.b[0];
    q[1] = d[0] / A.b[0];
    for(unsigned int i = 1; i < n-1; i++){
        p[i+1] = - A.c[i] / (A.a[i-1] * p[i] + A.b[i]);
        q[i+1] = (d[i] - A.a[i-1] * q[i]) / (A.a[i-1] * p[i] + A.b[i]);
    }
    x[n-1] = (d[n-1] - A.a[n-2] * q[n-1]) / (A.a[n-2] * p[n-1] + A.b[n-1]);
    for(unsigned int i = n-2; i > 0; i--){
        x[i] = p[i+1] * x[i+1] + q[i+1];
    }
    x[0] = p[1] * x[1] + q[1];
    return x;
}

int main(){
    // std::vector<double> c = {3., 1., -2.};
    // std::vector<double> b = {5., 6., 4., -3.};
    // std::vector<double> a = {3., 1., 1.};
    // std::vector<double> d = {8., 10., 3., -2.};
    // Matrix_3diag A = {a, b, c};
    // std::vector<double> x = answer(A, d);
    // std::cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3];
}