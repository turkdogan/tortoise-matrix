#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "../tortoise_matrix.h"

TEST_CASE("Test Matrix Operator()", "[TortoiseMatrix]") {
    TortoiseMatrix<double> m1(2, 2, 2.0);

    REQUIRE(m1.rows() == 2);
    REQUIRE(m1.cols() == 2);
    REQUIRE(m1(0, 0) == 2);
    REQUIRE(m1(0, 1) == 2);
    REQUIRE(m1(1, 0) == 2);
    REQUIRE(m1(1, 1) == 2);
}

TEST_CASE("Test Matrix Dot Product", "[TortoiseMatrix]") {
    TortoiseMatrix<double> m1(3, 4, 2.0);
    TortoiseMatrix<double> m2(3, 4, 3.0);
    TortoiseMatrix<double> m3 = m1 * m2;

    REQUIRE(m3.rows() == 3);
    REQUIRE(m3.cols() == 4);
    REQUIRE(m3(0, 0) == 6);
    REQUIRE(m3(1, 1) == 6);
    REQUIRE(m3(2, 2) == 6);
    REQUIRE(m3(2, 3) == 6);
}

/*
  Dot product (matrix multiplication, same as numpy for 2d matrixes)

  Example
  [2, 2] x [3, 3].T = [12].T
 */
TEST_CASE("Test Matrix Multiplication-1", "[TortoiseMatrix]") {
    TortoiseMatrix<double> m1(1, 2, 2.0);
    TortoiseMatrix<double> m2(2, 1, 3.0);
    TortoiseMatrix<double> m3 = m1.dot(m2);

    REQUIRE(m3.rows() == 1);
    REQUIRE(m3.cols() == 1);
    REQUIRE(m3(0, 0) == 12);
}

/*
  Dot product (matrix multiplication, same as numpy for 2d matrixes)
*/
TEST_CASE("Test Matrix Multiplication-2", "[TortoiseMatrix]") {
    TortoiseMatrix<double> m1(10, 5, 1.0);
    TortoiseMatrix<double> m2(5, 20, 1.0);
    TortoiseMatrix<double> m3 = m1.dot(m2);

    REQUIRE(m3.rows() == 10);
    REQUIRE(m3.cols() == 20);
    REQUIRE(m3(0, 0) == 5);
    REQUIRE(m3(9, 19) == 5);
    REQUIRE(m3(5, 5) == 5);
}

TEST_CASE("Test Matrix Operator+", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2(2, 2, 1);
    TortoiseMatrix<int> m3 = m1 + m2;

    REQUIRE(m3.rows() == 2);
    REQUIRE(m3.cols() == 2);
    REQUIRE(m3(0, 0) == 2);
    REQUIRE(m3(0, 1) == 2);
    REQUIRE(m3(0, 0) == 2);
    REQUIRE(m3(1, 1) == 2);
}

TEST_CASE("Test Matrix Operator-", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2(2, 2, 1);
    TortoiseMatrix<int> m3 = m1 - m2;

    REQUIRE(m3.rows() == 2);
    REQUIRE(m3.cols() == 2);
    REQUIRE(m3(0, 0) == 0);
    REQUIRE(m3(0, 1) == 0);
    REQUIRE(m3(0, 0) == 0);
    REQUIRE(m3(1, 1) == 0);
}

TEST_CASE("Test Matrix Operator*", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 2);
    TortoiseMatrix<int> m2(2, 2, 3);
    TortoiseMatrix<int> m3 = m1 * m2;

    REQUIRE(m3.rows() == 2);
    REQUIRE(m3.cols() == 2);
    REQUIRE(m3(0, 0) == 6);
    REQUIRE(m3(0, 1) == 6);
    REQUIRE(m3(0, 0) == 6);
    REQUIRE(m3(1, 1) == 6);
}

TEST_CASE("Test Matrix Operator/", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 12);
    TortoiseMatrix<int> m2(2, 2, 3);
    TortoiseMatrix<int> m3 = m1 / m2;

    REQUIRE(m3.rows() == 2);
    REQUIRE(m3.cols() == 2);
    REQUIRE(m3(0, 0) == 4);
    REQUIRE(m3(0, 1) == 4);
    REQUIRE(m3(0, 0) == 4);
    REQUIRE(m3(1, 1) == 4);
}


TEST_CASE("Test Matrix Operator+=", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2(2, 2, 1);
    m2 += m1;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 2);
    REQUIRE(m2(0, 1) == 2);
    REQUIRE(m2(0, 0) == 2);
    REQUIRE(m2(1, 1) == 2);
}

TEST_CASE("Test Matrix Operator-=", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2(2, 2, 1);
    m2 -= m1;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 0);
    REQUIRE(m2(0, 1) == 0);
    REQUIRE(m2(0, 0) == 0);
    REQUIRE(m2(1, 1) == 0);
}

TEST_CASE("Test Matrix Operator*=", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 2);
    TortoiseMatrix<int> m2(2, 2, 3);
    m2 *= m1;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 6);
    REQUIRE(m2(0, 1) == 6);
    REQUIRE(m2(0, 0) == 6);
    REQUIRE(m2(1, 1) == 6);
}

TEST_CASE("Test Matrix Operator/=", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 12);
    TortoiseMatrix<int> m2(2, 2, 3);
    m1 /= m2;

    REQUIRE(m1.rows() == 2);
    REQUIRE(m1.cols() == 2);
    REQUIRE(m1(0, 0) == 4);
    REQUIRE(m1(0, 1) == 4);
    REQUIRE(m1(0, 0) == 4);
    REQUIRE(m1(1, 1) == 4);
}

TEST_CASE("Test Matrix Operator+(double)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2 = m1 + 10.0;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 11);
    REQUIRE(m2(0, 1) == 11);
    REQUIRE(m2(0, 0) == 11);
    REQUIRE(m2(1, 1) == 11);
}

TEST_CASE("Test Matrix Operator-(double)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2 = m1 - 10.0;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == -9);
    REQUIRE(m2(0, 1) == -9);
    REQUIRE(m2(0, 0) == -9);
    REQUIRE(m2(1, 1) == -9);
}
TEST_CASE("Test Matrix Operator*(double)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 1);
    TortoiseMatrix<int> m2 = m1 * 10.0;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 10);
    REQUIRE(m2(0, 1) == 10);
    REQUIRE(m2(0, 0) == 10);
    REQUIRE(m2(1, 1) == 10);
}

TEST_CASE("Test Matrix Operator/(double)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 2, 10);
    TortoiseMatrix<int> m2 = m1 / 2.0;

    REQUIRE(m2.rows() == 2);
    REQUIRE(m2.cols() == 2);
    REQUIRE(m2(0, 0) == 5);
    REQUIRE(m2(0, 1) == 5);
    REQUIRE(m2(0, 0) == 5);
    REQUIRE(m2(1, 1) == 5);
}

TEST_CASE("Test Matrix set)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 4, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 1);

    REQUIRE(m1(0, 0) == 1);
    REQUIRE(m1(0, 1) == 1);
    REQUIRE(m1(1, 2) == 2);
}

TEST_CASE("Test Matrix Swap)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> m1(2, 4, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(0, 3, 4);
    m1.swap(0, 1);

    REQUIRE(m1(0, 0) == 2);
    REQUIRE(m1(0, 1) == 2);
    REQUIRE(m1(0, 2) == 2);
    REQUIRE(m1(0, 3) == 2);

    REQUIRE(m1(1, 0) == 1);
    REQUIRE(m1(1, 1) == 2);
    REQUIRE(m1(1, 2) == 3);
    REQUIRE(m1(1, 3) == 4);
}

std::valarray<std::valarray<int>> mock_data = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};


/*
  1 2 3
  4 5 6
  7 8 9
 */
TEST_CASE("Test Matrix Transpose)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(3, 3, mock_data);
    auto result = mat.transpose();

    REQUIRE(result.rows() == 3);
    REQUIRE(result.cols() == 3);

    REQUIRE(result(0, 0) == 1);
    REQUIRE(result(0, 1) == 4);
    REQUIRE(result(0, 2) == 7);

    REQUIRE(result(1, 0) == 2);
    REQUIRE(result(1, 1) == 5);
    REQUIRE(result(1, 2) == 8);

    REQUIRE(result(2, 0) == 3);
    REQUIRE(result(2, 1) == 6);
    REQUIRE(result(2, 2) == 9);
}

TEST_CASE("Test Matrix Min)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(3, 3, mock_data);

    REQUIRE(1 == mat.min());
}

TEST_CASE("Test Matrix Max)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(3, 3, mock_data);

    REQUIRE(9 == mat.max());
}

TEST_CASE("Test Matrix Sum)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(3, 3, mock_data);
    REQUIRE(45 == mat.sum());
}

TEST_CASE("Test Matrix Mean)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(3, 3, 2);
    REQUIRE(2 == mat.mean());
}

TEST_CASE("Test Matrix Normalize)", "[TortoiseMatrix]") {
    TortoiseMatrix<double> mat(2, 2, 0.0);
    mat.set(0, 0, 2.0);
    mat.set(0, 1, 1.5);
    mat.set(1, 0, 1.0);
    mat.set(1, 1, 0);
    mat.normalize();

    REQUIRE(mat(0, 0) == 1.0);
    REQUIRE(mat(0, 1) == 0.75);
    REQUIRE(mat(1, 0) == 0.5);
    REQUIRE(mat(1, 1) == 0.0);
}

TEST_CASE("Test Matrix broadcast add)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat1(2, 2, 2);
    TortoiseMatrix<int> mat2(1, 2, 5);
    auto result = mat1.broadcast(mat2);

    REQUIRE(result(0, 0) == 7);
    REQUIRE(result(0, 1) == 7);
    REQUIRE(result(1, 0) == 7);
    REQUIRE(result(1, 1) == 7);
}

TEST_CASE("Test Matrix broadcast subtract)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat1(2, 2, 2);
    TortoiseMatrix<int> mat2(1, 2, 5);
    auto result = mat1.bSubtract(mat2);

    REQUIRE(result(0, 0) == -3);
    REQUIRE(result(0, 1) == -3);
    REQUIRE(result(1, 0) == -3);
    REQUIRE(result(1, 1) == -3);
}

TEST_CASE("Test Matrix broadcast multiply)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat1(2, 2, 2);
    TortoiseMatrix<int> mat2(1, 2, 5);
    auto result = mat1.bMultiply(mat2);

    REQUIRE(result(0, 0) == 10);
    REQUIRE(result(0, 1) == 10);
    REQUIRE(result(1, 0) == 10);
    REQUIRE(result(1, 1) == 10);
}

TEST_CASE("Test Matrix abs)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(2, 2, 2);
    mat.set(0, 0, -1);
    mat.set(0, 1, 0);
    auto result = mat.abs();

    REQUIRE(result(0, 0) == 1);
    REQUIRE(result(0, 1) == 0);
    REQUIRE(result(1, 0) == 2);
    REQUIRE(result(1, 1) == 2);
}

TEST_CASE("Test Matrix pow)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(2, 2, 2);
    auto result = mat.pow(2);

    REQUIRE(result(0, 0) == 4);
    REQUIRE(result(0, 1) == 4);
    REQUIRE(result(1, 0) == 4);
    REQUIRE(result(1, 1) == 4);
}

TEST_CASE("Test Matrix sqrt)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(2, 2, 16);
    auto result = mat.sqrt();

    REQUIRE(result(0, 0) == 4);
    REQUIRE(result(0, 1) == 4);
    REQUIRE(result(1, 0) == 4);
    REQUIRE(result(1, 1) == 4);
}

TEST_CASE("Test Matrix extract row)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(2, 2, 2);
    auto row1 = mat.extract(0, 1);
    auto row2 = mat.extract(1, 1);
    auto all = mat.extract(0, 2);

    REQUIRE(row1.rows() == 1);
    REQUIRE(row1.cols() == 2);
    REQUIRE(row1(0, 0) == 2);
    REQUIRE(row1(0, 1) == 2);

    REQUIRE(row2.rows() == 1);
    REQUIRE(row2.cols() == 2);
    REQUIRE(row2(0, 0) == 2);
    REQUIRE(row2(0, 1) == 2);

    REQUIRE(all.rows() == 2);
    REQUIRE(all.cols() == 2);

    REQUIRE(all(0, 0) == 2);
    REQUIRE(all(0, 1) == 2);
    REQUIRE(all(1, 0) == 2);
    REQUIRE(all(1, 1) == 2);
}

/*
  Test extract column
*/
TEST_CASE("Test Matrix extract column)", "[TortoiseMatrix]") {
    TortoiseMatrix<int> mat(2, 2);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(1, 0, 3);
    mat.set(1, 1, 4);

    auto col1 = mat.extract(0);
    auto col2 = mat.extract(1);

    REQUIRE(col1.rows() == 2);
    REQUIRE(col1.cols() == 1);
    REQUIRE(col1(0, 0) == 1);
    REQUIRE(col1(1, 0) == 3);

    REQUIRE(col2.rows() == 2);
    REQUIRE(col2.cols() == 1);
    REQUIRE(col2(0, 0) == 2);
    REQUIRE(col2(1, 0) == 4);
}
