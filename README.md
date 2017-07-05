TortoiseMatrix is a simple, slow and header only matrix implementation in C++ language. 

# Examples

``` cpp
// element wise matrix multiplication example
// create 3x4 matrix with 2.0 
TortoiseMatrix<double> m1(3, 4, 2.0);
// create 3x4 matrix with 3.0 
TortoiseMatrix<double> m2(3, 4, 3.0);
// result 3x4 matrix with 6.0 
TortoiseMatrix<double> m3 = m1 * m2;
```

``` cpp
// Matrix multiplication example
// create 1x2 matrix with 2.0 
TortoiseMatrix<double> m1(1, 2, 2.0);
// create 2x1 matrix with 3.0 
TortoiseMatrix<double> m2(2, 1, 3.0);
// result 1x1 matrix with 12 
TortoiseMatrix<double> m3 = m1.dot(m2);
```

``` cpp
std::valarray<std::valarray<int>> mock_data = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

// Matrix transpose example
// create 3x3 matrix with mock data 
TortoiseMatrix<int> mat(3, 3, mock_data);
auto result = mat.transpose();
/*
Result is now:
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9},
*/
```

``` cpp
std::valarray<std::valarray<int>> mock_data = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

// min example
// create 3x3 matrix with mock data 
TortoiseMatrix<int> mat(3, 3, mock_data);
// min is 1
auto min = mat.min();
```

``` cpp
std::valarray<std::valarray<int>> mock_data = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

// max example
// create 3x3 matrix with mock data 
TortoiseMatrix<int> mat(3, 3, mock_data);
// min is 9
auto max = mat.max();
```

``` cpp
// pow example
// create 3x3 matrix with 2 
TortoiseMatrix<int> mat(3, 3, 2);
auto square = mat.pow(2);
```

``` cpp
// Extract 
// create 3x3 matrix with 2 
TortoiseMatrix<int> mat(3, 3, 2);
// 3x1 matrix (row1)
auto row1 = mat.extract(0, 3);
// 3x1 matrix (row2)
auto row2 = mat.extract(1, 3);
```

# Things to implement
Matrix multiplication is O^3. Optimization required.
