#include "../src/3diag.h"
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

TEST(Matrix_3diag, solve1) {
    std::vector<double> c = {3., 1., -2.};
    std::vector<double> b = {5., 6., 4., -3.};
    std::vector<double> a = {3., 1., 1.};
    std::vector<double> d = {8., 10., 3., -2.};
    Matrix_3diag A = {a, b, c};
    std::vector<double> x = answer(A, d);
    std::vector<double> correct = {1., 1., 1., 1.};
	for(size_t i = 0; i < x.size(); i++){
		EXPECT_DOUBLE_EQ(x[i], correct[i]);
	}
};

TEST(Matrix_3diag, solve2){
    std::vector<double> a = {2.0, 5.0, 8.0, 2.0};
    std::vector<double> b = {11.0, 14.0, 17.0, 11.0, 14.0};
	std::vector<double> c = {7, 0, 2, 5, 6, 9, 3, 4, 1, 6, 7, 9, 1};
    Matrix_3diag A = {a, b, c};
	std::vector<double> d = {3, 2, 3, 0, 3, 7, 8, 3, 4, 3, 9, 10, 5, 8};
	std::vector<double> result;
	std::vector<double> x = answer (A, d);
	std::vector<double> correct = {0.19323671497584541, 0.01449275362318841, 0.17465193371758323, -0.15919337031704065, 0.22997569106639693, -0.01893664942392408, 0.64098923900152257, -0.26780650040199976, 0.43168833295333478, -0.10903399383201836, 0.61051654129026458, 0.12698634246633848, 0.35407304018237538, 0.47026484566217846};
	for(size_t i = 0; i < x.size(); i++){
		ASSERT_NEAR(x[i], correct[i], 0.000001);
	}
};

TEST(Matrix_3diag, solve3) {
    std::vector<double> b = {8.0, 8.0, 1.0};
    std::vector<double> a = {0.0, -1.0, 6.0};
    std::vector<double> c = {4.0, 3.0, 0.0};
    Matrix_3diag A = {a, b, c};
    std::vector<double> d = {7.0, 7.0, 7.0};
    std::vector<double> x = answer(A, d);
    std::vector<double> correct = { 35.0 / 106.0, 231.0 / 212.0, -49.0 / 106.0};
    for (size_t i = 0; i < x.size(); i++) {
        EXPECT_NE(x[i], correct[i]);
    }
};