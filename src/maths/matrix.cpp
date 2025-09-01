#include "matrix.hpp"

Matrix Matrix::Identity(
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1);

Matrix transpose(const Matrix& mat)
{
    Matrix result_mat;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            result_mat.m_[i][j] = mat.m_[j][i]; 
        }
    }
    return result_mat;
}

Matrix scale(const Matrix& mat, const double scale_x, const double scale_y, const double scale_z)
{
    Matrix result_mat(mat);
    result_mat.m_[0][0] *= scale_x;
    result_mat.m_[1][1] *= scale_y;
    result_mat.m_[2][2] *= scale_z;
    return result_mat;
}

Matrix translate(const Matrix& mat, const Vector3<double>& v)
{
    Matrix result_mat(mat);
    result_mat.m_[0][3] += v.x_;
    result_mat.m_[1][3] += v.y_;
    result_mat.m_[2][3] += v.z_;
    return result_mat;
}

Matrix translate(const Matrix& mat, const Vector3<float>& v)
{
    Matrix result_mat(mat);
    result_mat.m_[0][3] += static_cast<double>(v.x_);
    result_mat.m_[1][3] += static_cast<double>(v.y_);
    result_mat.m_[2][3] += static_cast<double>(v.z_);
    return result_mat;
}

// TODO
Matrix perspective(float fovy, float aspect, float near, float far)
{
    Matrix result_mat;

    return result_mat;
}

