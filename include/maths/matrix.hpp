#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <cassert>
#include <stdexcept>

#include "vector.hpp"

// Matrix 4x4
// Since we are building matrix for rendering
class Matrix
{
public:
    static Matrix Identity;
    
    union
    {
        double m_[4][4];
        double m_array_[16];
    };

    Matrix() : m_{  {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} } {}
    Matrix(double m00, double m01, double m02, double m03,
        double m10, double m11, double m12, double m13,
        double m20, double m21, double m22, double m23,
        double m30, double m31, double m32, double m33)
    {
        m_[0][0] = m00, m_[0][1] = m01, m_[0][2] = m02, m_[0][3] = m03;
        m_[1][0] = m10, m_[1][1] = m11, m_[1][2] = m12, m_[1][3] = m13;
        m_[2][0] = m20, m_[2][1] = m21, m_[2][2] = m22, m_[2][3] = m23;
        m_[3][0] = m30, m_[3][1] = m31, m_[3][2] = m32, m_[3][3] = m33;
    }
    Matrix(const std::initializer_list<double>& init)
    {
        assert(init.size() == 16 && "Matrix initializer must have exactly 16 values");
        std::copy(init.begin(), init.end(), &m_[0][0]);
    }

    Matrix(const Matrix& m) { memcpy(m_array_, m.m_array_, 16 * sizeof(double)); }

    Matrix& operator = (const Matrix& m)
    {
        if(this == &m) return *this;
        memcpy(m_array_, m.m_array_, 16 * sizeof(double));
        return *this;
    }
};

inline
std::ostream& operator << (std::ostream& os, const Matrix& mat)
{
    os << "{" << std::endl;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            os << mat.m_[i][j];
            if(!(i == 3 && j == 3)) os << ", ";
        }
        if(i != 3) os << std::endl;
    }
    os << std::endl << "}" << std::endl;
    return os;
}

Matrix transpose(const Matrix&);
Matrix scale(const Matrix&, const double, const double, const double);
Matrix translate(const Matrix&, const Vector3<double>&);
Matrix translate(const Matrix&, const Vector3<float>&);
Matrix ortho(float width, float height, float near, float far);
Matrix perspective(float fovy, float aspect, float near, float far);

template <typename T>
inline Vector4<T> operator * (const Matrix& mat, const Vector4<T>& vec)
{
    Vector4<T> result_vec;
    result_vec.x_ = (mat.m_[0][0] * vec.x_ + mat.m_[0][1] * vec.y_ + mat.m_[0][2] * vec.z_ + mat.m_[0][3] * vec.w_);
    result_vec.y_ = (mat.m_[1][0] * vec.x_ + mat.m_[1][1] * vec.y_ + mat.m_[1][2] * vec.z_ + mat.m_[1][3] * vec.w_);
    result_vec.z_ = (mat.m_[2][0] * vec.x_ + mat.m_[2][1] * vec.y_ + mat.m_[2][2] * vec.z_ + mat.m_[2][3] * vec.w_);
    result_vec.w_ = (mat.m_[3][0] * vec.x_ + mat.m_[3][1] * vec.y_ + mat.m_[3][2] * vec.z_ + mat.m_[3][3] * vec.w_);
    return result_vec;
}

inline Matrix operator * (const Matrix& mat1, const Matrix& mat2)
{
    Matrix result_mat;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            for(int k = 0; k < 4; ++k)
            {
                result_mat.m_[i][j] += mat1.m_[i][k] * mat2.m_[k][j];
            }
        }
    }
    return result_mat;
}

template <typename T>
inline Matrix lookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up)
{
    Vector3<T> z_view = normalize(eye - center);

    Vector3<T> x_view = normalize(cross(up, z_view));
    Vector3<T> y_view = cross(z_view, x_view);

    Matrix result_mat(
        x_view.x_, x_view.y_, x_view.z_, -eye.x_,
        y_view.x_, y_view.y_, y_view.z_, -eye.y_,
        z_view.x_, z_view.y_, z_view.z_, -eye.z_,
        0, 0, 0, 1
    );

    // Matrix result_mat(
    //     x_view.x_, y_view.x_, z_view.x_, -eye.x_,
    //     x_view.y_, y_view.y_, z_view.y_, -eye.y_,
    //     x_view.z_, y_view.z_, z_view.z_, -eye.z_,
    //     0, 0, 0, 1
    // );

    return result_mat;
}

typedef Matrix Mat4;


#endif