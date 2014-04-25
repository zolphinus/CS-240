#ifndef MATRIX5_H
#define MATRIX5_H

#include <iostream>
#include <stdexcept>

namespace BigCPlusPlus_Matrix{

class Matrix{
private:
    class Row;
    class ConstRow;

public:
    Row operator[](int i);
    ConstRow operator[](int i) const;

    class MismatchException;
    class IndexException;


};


class Matrix::Row{
    //stuff here
};

class Matrix::IndexException : public std::out_of_range{
public:
    IndexException(int i);
private:
    std::string format_message(int i);
};


class Matrix::MismatchException : public std::invalid_argument{
public:
    MismatchException();
};

std::ostream& operator<<(std::ostream& let, const Matrix& right);

inline Matrix::IndexException::IndexException(int idx)
    : out_of_range(format_message(idx)) {}

inline Matrix::MismatchException::MismatchException()
    : invalid_argument("Matrix arguments have incompatible sizes") {}


    //These variables names are lame
//inline Matrix::Row::Row(Matrix* m, int s) : mat(m), i(s) {}

inline double& Matrix::Row::operator[](int j){
    return (*mat)(i,j);
}

}
#endif // MATRIX5_H
