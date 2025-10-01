#include "matrix.hpp"

#include <cmath>
#include "constant.h"

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

// parameter near and far are coordinates
// since we look at -z, 0 > near > far
Matrix ortho(float width, float height, float near, float far)
{
    // frustum is always centered : r = -l = width/2, t = -b = height/2s
    Matrix ortho_translate_mat
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, -(near + far)/2,
        0, 0, 0, 1
    };
    Matrix ortho_scale_mat
    {
        2/ width, 0, 0, 0,
        0, 2 / height, 0, 0,
        0, 0, 2 / (near - far), 0,
        0, 0, 0, 1
    };
    return ortho_scale_mat * ortho_translate_mat;
}

// parameter near and far are coordinates
// negative since we look at -z
Matrix perspective(float fovy, float aspect, float near, float far)
{
    Matrix perspective_to_ortho_mat
    {
        near, 0, 0, 0,
        0, near, 0, 0,
        0, 0, near + far, -near * far,
        0, 0, 1, 0
    };

    float radian_fovy = fovy * PI / 180.0;
    float height = -near * tan(radian_fovy / 2) * 2;

    Matrix ortho_mat = ortho(height * aspect, height, near, far);

    return ortho_mat * perspective_to_ortho_mat;
}
