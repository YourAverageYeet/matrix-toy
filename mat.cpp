#include "mat.h"
#include <initializer_list>

const Matrix33 ident33 = {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}
};

Matrix33::Matrix33(void):
    rows {{0.0, 0.0, 0.0},
          {0.0, 0.0, 0.0},
          {0.0, 0.0, 0.0}}
    {}

Matrix33::Matrix33(double val):
    rows {{val, val, val},
          {val, val, val},
          {val, val, val}}
    {}

Matrix33::Matrix33(std::initializer_list<std::initializer_list<double>> mat){
    std::initializer_list<std::initializer_list<double>>::const_iterator
        part = mat.begin();
    for(size_t i = 0; i < 3; i++){
        std::initializer_list<double>::const_iterator val = part->begin();
        rows[i][0] = *val++;
        rows[i][1] = *val++;
        rows[i][2] = *val;
        part++;
    }
}

void Matrix33::setMatValue(size_t row, size_t col, double val){
    if((row > 2) || (col > 2)){
        throw std::out_of_range("Invalid matrix access request.");
    }
    rows[row][col] = val;
}

double Matrix33::getMatValue(size_t row, size_t col) const {
    if((row > 2) || (col > 2)){
        throw std::out_of_range("Invalid matrix access request.");
    }
    return rows[row][col];
}

bool Matrix33::operator!=(const Matrix33& m) const {
    for(size_t r = 0; r < 3; r++){
        for(size_t c = 0; c < 3; c++){
            if(rows[r][c] != m.rows[r][c]){
                return true;
            }
        }
    }
    return false;
}

Matrix33& Matrix33::operator=(const Matrix33& m){
    rows[0][0] = m.rows[0][0];
    rows[0][1] = m.rows[0][1];
    rows[0][2] = m.rows[0][2];
    rows[1][0] = m.rows[1][0];
    rows[1][1] = m.rows[1][1];
    rows[1][2] = m.rows[1][2];
    rows[2][0] = m.rows[2][0];
    rows[2][1] = m.rows[2][1];
    rows[2][2] = m.rows[2][2];
    return *this;
}

Matrix33 Matrix33::operator*(const Matrix33& m) const {
    Matrix33 r;
    r.rows[0][0] = rows[0][0]*m.rows[0][0] + rows[0][1]*m.rows[1][0] +
        rows[0][2]*m.rows[2][0];
    r.rows[0][1] = rows[0][0]*m.rows[0][1] + rows[0][1]*m.rows[1][1] +
        rows[0][2]*m.rows[2][1];
    r.rows[0][2] = rows[0][0]*m.rows[0][2] + rows[0][1]*m.rows[1][2] +
        rows[0][2]*m.rows[2][2];
    r.rows[1][0] = rows[1][0]*m.rows[0][0] + rows[1][1]*m.rows[1][0] +
        rows[1][2]*m.rows[2][0];
    r.rows[1][1] = rows[1][0]*m.rows[0][1] + rows[1][1]*m.rows[1][1] +
        rows[1][2]*m.rows[2][1];
    r.rows[1][2] = rows[1][0]*m.rows[0][2] + rows[1][1]*m.rows[1][2] +
        rows[1][2]*m.rows[2][2];
    r.rows[2][0] = rows[2][0]*m.rows[0][0] + rows[2][1]*m.rows[1][0] +
        rows[2][2]*m.rows[2][0];
    r.rows[2][1] = rows[2][0]*m.rows[0][1] + rows[2][1]*m.rows[1][1] +
        rows[2][2]*m.rows[2][1];
    r.rows[2][2] = rows[2][0]*m.rows[0][2] + rows[2][1]*m.rows[1][2] +
        rows[2][2]*m.rows[2][2];
    return r;
}

std::ostream& operator<<(std::ostream& os, const Matrix33& m){
    os << '[' << m.getMatValue(0, 0) << ", " << m.getMatValue(0, 1) << ", " <<
        m.getMatValue(0, 2) << "]\n";
    os << '[' << m.getMatValue(1, 0) << ", " << m.getMatValue(1, 1) << ", " <<
        m.getMatValue(1, 2) << "]\n";
    os << '[' << m.getMatValue(2, 0) << ", " << m.getMatValue(2, 1) << ", " <<
        m.getMatValue(2, 2) << "]\n";
    return os;
}
