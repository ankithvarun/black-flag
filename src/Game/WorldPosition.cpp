#include "stdafx.h"
#include "WorldPosition.h"

void Position::set_position(const glm::vec3& new_pos
    , const glm::vec3& new_angle) {
    position = new_pos;
    angle = new_angle;
    update();
}

void Position::move_forward(float dt, glm::vec3 forward) {
    position += forward * MotionVel * dt;
}

void Position::move_back(float dt, glm::vec3 forward) {
    position -= forward * MotionVel * dt;
}

void Position::move_left(float dt) {
    position -= right * MotionVel * dt;
}

void Position::move_right(float dt) {
    position += right * MotionVel * dt;
}

void Position::move_up(float dt) {
    position.y += MotionVel * dt;
}

void Position::move_down(float dt) {
    position.y -= MotionVel * dt;
}

void Position::rotate_clockwise(float dt) {
    angle.x -= RotationVel * dt;
    update();
}

void Position::rotate_anticlockwise(float dt) {
    angle.x += RotationVel * dt;
    update();
}

void Position::resize_screen(int w, int h) {
    width = w;
    height = h;
}

void Position::set_mouse_point(int x, int y) {
    angle.x -= (x - width / 2) * RotationVel * 0.01f;
    angle.y -= (y - height / 2) * RotationVel * 0.01f;

    // Boundary Conditions
    if (angle.x<-M_PI) {
        angle.x += M_PI * 2;
    }
    
    if (angle.x>M_PI) {
        angle.x -= M_PI * 2;
    }

    if (angle.y<-M_PI/2) {
        angle.y = -M_PI / 2;
    }

    if (angle.y>M_PI/2) {
        angle.y = M_PI / 2;
    }

    update();
}

void Position::update() {
    forward.x = -sin(angle.x);
    forward.y = 0.0;
    forward.z = cos(angle.x);

    right.x = -cos(angle.x);
    right.y = 0.0;
    right.z = sin(angle.x);

    lookat.x = sin(angle.x) * cos(angle.y);
    lookat.y = sin(angle.y);
    lookat.z = cos(angle.x) * cos(angle.y);

    up = glm::cross(right, lookat);
}
