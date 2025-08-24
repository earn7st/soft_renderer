#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

class Camera
{
public:
    Vec3f pos_ = Vec3f(0, 0, 5);
    Vec3f center_ = Vec3f(0, 0, 0);
    Vec3f up_ = Vec3f(0, 1, 0); //FPS Camera up_ = WORLD_UP
    float aspect_ = 1.5;    // width/height

    float near_plane_ = 0.1;
    float far_plane_ = 10;

    Camera() = default;
    Camera(const Vec3f& pos, const Vec3f& center, const Vec3f& up, float aspect)
    : pos_(pos), center_(center), up_(up),  aspect_(aspect) { }

};

#endif