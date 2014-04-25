#include <iomanip>
#include <sstream>
#include "Matrix_5.h"

using namespace std;

namespace BigCPlusPlus_Matrix{

string Matrix::IndexException::formatMessage(int n){
    ostringstream outstr;
    outstr << "Matrix Index " << n << " out of range!";
    return outstr.str();
}

double& Matrix::Operator()(int i, int j){
    if(i < 0 || i >= rows)
    {
        throw Matrix::IndexException(i);
    }

    if(j < 0 || j >= columns)
    {
        throw Matrix::IndexException(j);
    }
    return elements[i * get_columns() + j];
}

}
