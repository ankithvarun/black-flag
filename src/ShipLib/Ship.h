#ifndef SHIP_H
#define SHIP_H

#include "model.h"
#include "stdafx.h"

class Ship {
    private:
        const float RotationVel = 1.0;

    public:
        int HP = 100;
        int Score = 0;
        float MotionVel = 0;
        glm::vec3 position;
        glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 lookat = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 angle = glm::vec3(M_PI, M_PI/8, 0.0f);
        glm::mat4 modelMatrix;
        glm::mat4 rotateMatrix;

        glm::vec3 shootCameraPos;
        glm::vec3 TPPCameraPos;

        Ship(){}

        void Init(glm::vec3 position, glm::mat4 modelMatrix)
        {
            this->position = position;
            this->modelMatrix = glm::translate(glm::mat4(1), position);
            this->rotateMatrix = glm::mat4(1);
            this->shootCameraPos = glm::vec3(0.0f, 0.0f, 30.0f);
            this->TPPCameraPos = glm::vec3(0.0f, -30.0f, -60.0f);
        }
        // void Init(glm::vec3 position, glm::mat4 modelMatrix);
        void Render(Shader_M shader, Model model, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
        {
            shader.use();
            shader.setMat4("rotate", rotateMatrix);
            shader.setMat4("model", modelMatrix);
            shader.setMat4("view", viewMatrix);
            shader.setMat4("projection", projectionMatrix);
            model.Draw(shader);
        }

        void move() {
            position += forward * MotionVel;
            modelMatrix = glm::translate(modelMatrix, forward * MotionVel);
        }

        // void move_back(float dt) {
        //     position += forward * MotionVel * dt;
        //     modelMatrix = glm::translate(modelMatrix, forward * MotionVel * dt);
        // }

        void rotate_clockwise(float dt) {
            angle.x += RotationVel * dt;
            rotateMatrix = glm::rotate(rotateMatrix, -RotationVel * dt, glm::vec3(0.0f, 1.0f, 0.0f));
            
            forward.x = -sin(angle.x);
            forward.y = 0.0f;         
            forward.z = cos(angle.x);

            shootCameraPos.x = 30.0f * sin(angle.x);
            shootCameraPos.z = -30.0f * cos(angle.x);

            TPPCameraPos.x = -60.0f * sin(angle.x);
            TPPCameraPos.z = 60.0f * cos(angle.x);

            right = glm::cross(forward, up);
        }

        void rotate_anticlockwise(float dt) {
            angle.x -= RotationVel * dt;
            rotateMatrix = glm::rotate(rotateMatrix, RotationVel * dt, glm::vec3(0.0f, 1.0f, 0.0f));
            
            forward.x = -sin(angle.x);
            forward.y = 0.0f;         
            forward.z = cos(angle.x);

            shootCameraPos.x = 30.0f * sin(angle.x);
            shootCameraPos.z = -30.0f * cos(angle.x);

            TPPCameraPos.x = -60.0f * sin(angle.x);
            TPPCameraPos.z = 60.0f * cos(angle.x);

            right = glm::cross(forward, up);
        }
};

#endif                                                                  