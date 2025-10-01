#include "camera.h"

#include <iostream>
#include "vector.hpp"

void Camera::print() const
{
    std::cout << "pos: " << pos_ << std::endl;
    std::cout << "center: " << center_ << std::endl;
    std::cout << "up: " << up_ << std::endl;
    std::cout << "aspect: " << aspect_ << std::endl;
    std::cout << "fovy: " << fovy_ << std::endl;
    std::cout << "near_plane: " << near_plane_ << std::endl;
    std::cout << "far_plane: " << far_plane_<< std::endl;
}