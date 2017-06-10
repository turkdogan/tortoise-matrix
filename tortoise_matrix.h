#ifndef TT_MATRIX_H
#define TT_MATRIX_H

#include <valarray>
#include <algorithm>
#include <string>
#include <assert.h>

template <typename T>
class TortoiseMatrix
{
public:
	TortoiseMatrix<T>();
	TortoiseMatrix<T>(int rows, int cols);
	TortoiseMatrix<T>(int rows, int cols, const T&);
	TortoiseMatrix<T>(int rows, int cols, const std::valarray<std::valarray<T>>& mat);
	TortoiseMatrix<T>(const TortoiseMatrix<T>& mat);

	/*
	 * Access specific element by row and column
	 */
	T operator()(int row, int col) const;

	long size() const;

	TortoiseMatrix<T>& operator=(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T>& operator=(const T& value);

	TortoiseMatrix<T> operator+(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T> operator-(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T> operator*(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T> operator/(const TortoiseMatrix<T>& mat);

	TortoiseMatrix<T> operator+(const T& value);
	TortoiseMatrix<T> operator-(const T& value);
	TortoiseMatrix<T> operator*(const T& value);
	TortoiseMatrix<T> operator/(const T& value);

	/*
	  Adds the row of the mat to all rows of this matrix
	*/
	TortoiseMatrix<T> broadcast(TortoiseMatrix<T>& mat);
	/*
	  Subtracts the row of the mat from all rows of this matrix
	*/
	TortoiseMatrix<T> bSubtract(TortoiseMatrix<T>& mat);
	/*
	  Multiplies the row of the mat with all rows of this matrix
	*/
	TortoiseMatrix<T> bMultiply(TortoiseMatrix<T>& mat);

	// reverse order divide (eg. value / matrix)
	TortoiseMatrix<T> div(double);

	TortoiseMatrix<T>& operator+=(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T>& operator-=(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T>& operator*=(const TortoiseMatrix<T>& mat);
	TortoiseMatrix<T>& operator/=(const TortoiseMatrix<T>& mat);

	void resize(int rows, int cols);

	/*
	 * Set value to the individual position in the matrix
	 */
	void set(int row, int col, const T&);

/*
	 * Set value to the all positions in the matrix
	 */
	void set(const T&);

	/*
	 * Transpose of the matrix
	 */
	TortoiseMatrix<T> transpose() const;

	/*
	 * Dot product
	 */
	TortoiseMatrix<T> dot(const TortoiseMatrix<T>& mat) const;
	TortoiseMatrix<T> dot2(const TortoiseMatrix<T>& mat);

	// experimental only! 4 times slower than dot 
	TortoiseMatrix<T> dotTemp(const TortoiseMatrix<T>& mat);

	TortoiseMatrix<T> abs() const;
	TortoiseMatrix<T> exp() const;
	TortoiseMatrix<T> log() const;
	TortoiseMatrix<T> log10() const;

	TortoiseMatrix<T> pow(double) const;
	TortoiseMatrix<T> sqrt() const;

	TortoiseMatrix<T> sin() const;
	TortoiseMatrix<T> cos() const;
	TortoiseMatrix<T> tan() const;
	TortoiseMatrix<T> asin() const;
	TortoiseMatrix<T> acos() const;
	TortoiseMatrix<T> atan() const;
	TortoiseMatrix<T> atan2() const;

	TortoiseMatrix<T> sinh() const;
	TortoiseMatrix<T> cosh() const;
	TortoiseMatrix<T> tanh() const;

	/*
	  Extracts sub matrix from row_begin to row_end (including)
	  returns [row_count, m_cols] matrix
	*/
	TortoiseMatrix<T> extract(int row_begin, int row_count) const;

	/*
	  Extracts single column
	  returns [m_rows, 1] matrix
	*/
	TortoiseMatrix<T> extract(int col) const;

	/*
	 * Normalizes the matrix elements by:
	 * value - min / max - min
	 */
	void normalize();

	/*
	 * Swaps the rows of the matrix
	 */
	void swap(int row1, int row2);

	/*
	 * minimum value in the matrix
	 */
	T min() const;

	/*
	 * maximum value in the matrix
	 */
	T max() const;

	/*
	 * All the elements are summed
	 */
	T sum() const;

	/*
	 * Mean of the whole matrix
	 */
	double mean() const;

	inline int rows() const { return m_rows; }
	inline int cols() const { return m_cols; }

private:
	std::valarray<T> m_data;

	int m_rows;
	int m_cols;
};

template<typename T>
TortoiseMatrix<T>::TortoiseMatrix()
{
}

template<typename T>
TortoiseMatrix<T>::TortoiseMatrix(int rows, int cols)
: m_rows(rows), m_cols(cols)
{
	m_data.resize(rows * cols);
}

template<typename T>
TortoiseMatrix<T>::TortoiseMatrix(int rows, int cols, const T& value)
: m_rows(rows), m_cols(cols)
{
	m_data.resize(rows * cols, value);
}

template<typename T>
TortoiseMatrix<T>::TortoiseMatrix(int rows, int cols, const std::valarray<std::valarray<T>> & mat)
: m_rows(rows), m_cols(cols)
{
	m_data.resize(rows * cols);
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			set(r, c, mat[r][c]);
		}
	}
}

template<typename T>
TortoiseMatrix<T>::TortoiseMatrix(const TortoiseMatrix<T>& mat)
{
	m_data = mat.m_data;
	m_rows = mat.m_rows;
	m_cols = mat.m_cols;
}

template<typename T>
T TortoiseMatrix<T>::operator()(int row, int col) const
{
	return m_data[row * m_cols + col];
}

template<typename T>
long TortoiseMatrix<T>::size() const
{
	return m_cols * m_rows;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator=(const TortoiseMatrix<T>& mat)
{
	m_rows = mat.m_rows;
	m_cols = mat.m_cols;

	m_data = mat.m_data;
	return *this;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator=(const T& value)
{
	m_data = value;
	return *this;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator+(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data + mat.m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::broadcast(TortoiseMatrix<T>& mat)
{
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = m_data;

	auto broadcast_valarray = mat.m_data[std::slice(0, m_cols, 1)];

	for (int i = 0; i < m_rows; i++) {
		result.m_data[std::slice(i * m_cols, m_cols, 1)] += broadcast_valarray;
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::bSubtract(TortoiseMatrix<T>& mat)
{
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = m_data;

	auto broadcast_valarray = mat.m_data[std::slice(0, m_cols, 1)];

	for (int i = 0; i < m_rows; i++) {
		result.m_data[std::slice(i * m_cols, m_cols, 1)] -= broadcast_valarray;
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::bMultiply(TortoiseMatrix<T>& mat)
{
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = m_data;

	auto broadcast_valarray = mat.m_data[std::slice(0, m_cols, 1)];

	for (int i = 0; i < m_rows; i++) {
		result.m_data[std::slice(i * m_cols, m_cols, 1)] *= broadcast_valarray;
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator-(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data - mat.m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator*(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data * mat.m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator/(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data / mat.m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator+(const T& value)
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data + value);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator-(const T& value)
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data - value);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator*(const T& value)
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data * value);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::operator/(const T& value)
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (m_data / value);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::div(double value)
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = (value / m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator+=(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	m_data += mat.m_data;
	return *this;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator-=(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	m_data -= mat.m_data;
	return *this;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator*=(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	m_data *= mat.m_data;
	return *this;
}

template<typename T>
TortoiseMatrix<T>& TortoiseMatrix<T>::operator/=(const TortoiseMatrix<T>& mat)
{
	assert(m_rows == mat.m_rows);
	assert(m_cols == mat.m_cols);

	m_data /= mat.m_data;
	return *this;
}

template<typename T>
void TortoiseMatrix<T>::resize(int rows, int cols)
{
	m_rows = rows;
	m_cols = cols;

	m_data.resize(rows * cols);
}

template<typename T>
void TortoiseMatrix<T>::set(int row, int col, const T& value)
{
	m_data[row * m_cols + col] = value;
}

template<typename T>
void TortoiseMatrix<T>::set(const T& value)
{
	m_data.fill(value);
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::transpose() const
{
	TortoiseMatrix<T> result(m_cols, m_rows);
	for (auto r = 0; r < m_rows; r++)
	{
		for (auto c = 0; c < m_cols; c++)
		{
			//result.m_data[c * m_cols + r] = m_data[r * m_cols + c];
			T value = operator()(r, c);
			result.set(c, r, value);
		}
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::extract(int row_begin, int row_count) const
{
	int index_begin = row_begin * m_cols;
	int number_of_elements = row_count * m_cols;

	TortoiseMatrix<T> result(row_count, m_cols);
	result.m_data = m_data[std::slice(index_begin, number_of_elements, 1)];
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::extract(int col) const
{
	TortoiseMatrix<T> result(m_rows, 1);
	result.m_data = m_data[std::slice(col, m_rows, m_cols)];
	return result;
}

template<typename T>
void TortoiseMatrix<T>::normalize()
{
	const T _min = min();
	const T _max = max();
	const T min_max_diff = _max - _min;
	for (auto r = 0; r < m_rows; r++)
	{
		for (auto c = 0; c < m_cols; c++)
		{
			T value = operator()(r, c);
			set(r, c, (value - _min)/min_max_diff);
		}
	}
}

template<typename T>
void TortoiseMatrix<T>::swap(int row1, int row2)
{
	assert(m_rows > row1);
	assert(m_rows > row2);

	int ind_start = row1 * m_cols;
	int ind_end = ind_start + m_cols;
	int swp_ind_start = row2 * m_cols;
	std::swap_ranges(std::begin(m_data) + ind_start, std::begin(m_data) + ind_end, std::begin(m_data) + swp_ind_start);
}

template<typename T>
T TortoiseMatrix<T>::min() const
{
	return m_data.min();
}

template<typename T>
T TortoiseMatrix<T>::max() const
{
	return m_data.max();
}

template<typename T>
T TortoiseMatrix<T>::sum() const
{
	return m_data.sum();
}

template<typename T>
double TortoiseMatrix<T>::mean() const
{
	return (double)sum() / m_data.size();
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::dotTemp(const TortoiseMatrix<T> &mat)
{
	TortoiseMatrix<T> result = TortoiseMatrix(m_rows, mat.m_cols);
	for(auto r = 0; r < m_rows; r++) {
		for(auto c = 0; c < mat.m_cols; c++) {
			std::valarray<T> row = m_data[std::slice(r * m_cols, m_cols, 1)];
			std::valarray<T> col = mat.m_data[std::slice(c, mat.m_rows, mat.m_cols)];
			std::valarray<T> mul = row * col;
			const T& sum = mul.sum();
			result.set(r, c, sum);
		}
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::dot(const TortoiseMatrix<T> &mat) const
{
	TortoiseMatrix<T> dest = TortoiseMatrix(m_rows, mat.m_cols);

	TortoiseMatrix<T> tr = mat.transpose();
	
	for (int r = 0; r < dest.m_rows; r++) {
		for (int c = 0; c < dest.m_cols; c++) {
			T sum = 0;
			for (int k = 0; k < m_cols; k++)
				sum += m_data[r * m_cols + k] * tr.m_data[c * tr.m_cols + k];
				//sum += m_data[r * m_cols + k] * tr(c, k);
			dest.m_data[r * dest.m_cols + c] = sum;
		}
	}
	return dest;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::dot2(const TortoiseMatrix<T> &mat)
{

	TortoiseMatrix<T> result = TortoiseMatrix(m_rows, mat.m_cols);
	
	for(auto r = 0; r < m_rows; r++) {
		for(auto k = 0; k < m_cols; k++) {
			double total = 0;
			for(auto c = 0; c < mat.m_cols; c++) {
				result.m_data[r * mat.m_cols + c] += (m_data[r * m_cols + k] * mat.m_data[k * mat.m_cols + c]);
			}
		}
	}
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::abs() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::abs(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::exp() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::exp(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::log() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::log(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::log10() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::log10(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::pow(double value) const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::pow(m_data, (T)value);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::sqrt() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::sqrt(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::sin() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::sin(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::cos() const

{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::cos(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::tan() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::tan(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::asin() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::asin(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::acos() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::acos(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::atan() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::atan(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::atan2() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::atan2(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::sinh() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::sinh(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::cosh() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::cosh(m_data);
	return result;
}

template<typename T>
TortoiseMatrix<T> TortoiseMatrix<T>::tanh() const
{
	TortoiseMatrix<T> result(m_rows, m_cols);
	result.m_data = std::tanh(m_data);
	return result;
}

#endif
