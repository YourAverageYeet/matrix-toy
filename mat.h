#ifndef     MAT_H_INCLUDED
#define     MAT_H_INCLUDED

#include <initializer_list>
#include <stdexcept>
#include <iostream>

class Matrix33 {
        double rows[3][3];
    public:
        Matrix33(void);
        Matrix33(double val);
        Matrix33(std::initializer_list<std::initializer_list<double>> mat);
        void setMatValue(size_t row, size_t col, double val);
        double getMatValue(size_t row, size_t col) const;
        bool operator!=(const Matrix33& m) const;
        Matrix33& operator=(const Matrix33& m);
        Matrix33 operator*(const Matrix33& m) const;
};

extern const Matrix33 ident33;

std::ostream& operator<<(std::ostream& os, const Matrix33& m);

#endif  //  MAT_H_INCLUDED
