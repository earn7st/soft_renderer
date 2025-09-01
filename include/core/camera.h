#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

class Camera
{
public:

    Camera() = default;
    Camera(const Vec3f& pos, const Vec3f& center, const Vec3f& up, float aspect)
    : pos_(pos), center_(center), up_(up),  aspect_(aspect) { }

    // Getters
    Vec3f get_pos() const { return pos_; }
    Vec3f get_center() const { return center_; }
    Vec3f get_up() const { return up_; }
    float get_aspect() const { return aspect_; }
    float get_fovy() const { return fovy_; }
    float get_near_plane() const { return near_plane_; }
    float get_far_plane() const { return far_plane_; }

private:
    Vec3f pos_ = Vec3f(0, 0, 5);
    Vec3f center_ = Vec3f(0, 0, 0);
    Vec3f up_ = Vec3f(0, 1, 0); //FPS Camera : up_ = WORLD_UP
    float aspect_ = 1.5;    // width/height

    float fovy_ = 60.0f;
    float near_plane_ = 0.1;
    float far_plane_ = 10;
};

#endif