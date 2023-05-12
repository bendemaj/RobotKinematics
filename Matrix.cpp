#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Mat
{
public:
  // Parameter Constructor
  Mat(int _row, int _col, const T& _init)
  {
    m_mat.resize(_row);
    for (int i = 0; i < m_mat.size(); i++)
    {
      m_mat[i].resize(_col, _init);
    }
    m_row = _row;
    m_col = _col;
  }

  // Copy Constructor
  Mat(const Mat<T>& temp)
  {
    m_mat = temp.m_mat;
    m_row = temp.m_row;
    m_col = temp.m_col;
  }

  // Virtual Destruktor
  ~Mat() {}

  // Operators
  Mat<T>& operator=(const Mat<T>& temp)
  {
    if (&temp == this)
      return *this;

    m_mat.resize(temp.m_row);
    for (int i = 0; i < m_mat.size(); i++)
    {
      m_mat[i].resize(temp.m_col);
    }

    for (int i = 0; i < temp.m_row; i++)
    {
      for (int j = 0; j < temp.m_row; j++)
      {
        m_mat[i][j] = temp.m_mat[i][j];
      }
    }

    m_row = temp.m_row;
    m_col = temp.m_col;

    return *this;
  }
  Mat<T>& operator+(const Mat<T>& temp)
  {
    for (int i = 0; i < m_row; i++)
    {
      for (int j = 0; j < m_col; j++)
      {
        this->m_mat[i][j] += temp.m_mat[i][j];
      }
    }
    return *this;
  }
  Mat<T>& operator+=(const Mat<T>& temp)
  {
    for (int i = 0; i < m_row; i++)
    {
      for (int j = 0; j < m_col; j++)
      {
        this->m_mat[i][j] += temp.m_mat[i][j];
      }
    }
    return *this;
  }
  Mat<T>& operator-(const Mat<T>& temp)
  {
    for (int i = 0; i < m_row; i++)
    {
      for (int j = 0; j < m_col; j++)
      {
        this->m_mat[i][j] -= temp.m_mat[i][j];
      }
    }
    return *this;
  }
  Mat<T>& operator-=(const Mat<T>& temp)
  {
    for (int i = 0; i < m_row; i++)
    {
      for (int j = 0; j < m_col; j++)
      {
        this->m_mat[i][j] -= temp.m_mat[i][j];
      }
    }
    return *this;
  }
  friend ostream& operator<<(ostream& stream, const Mat<T> temp)
  {
    for (int i = 0; i < temp.m_row; i++)
    {
      for (int j = 0; j < temp.m_col; j++)
      {
        stream << temp.m_mat[i][j] << " ";
      }
      stream << endl;
    }
    return stream;
  }
  T& operator()(const int& row, const int& col)
  {
    return this->m_mat[row][col];
  }
  const T& operator()(const int& row, const int& col) const
  {
    return this->m_mat[row][col];
  }

private:
  int m_row;
  int m_col;
  vector<vector<T>> m_mat;
};

int main()
{
  Mat<double> a(2, 2, 0.0), b(2, 2, 0.0), c(2, 2, 0.0);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 5;
  b(0, 1) = 6;
  b(1, 0) = 7;
  b(1, 1) = 8;

  cout << a << endl << b;


}

/*
19	22
43	50
*/
