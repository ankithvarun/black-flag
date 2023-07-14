#ifndef PIRATE_SHIP_H
#define PIRATE_SHIP_H

#include "stdafx.h"

class PirateShip {
    private:
        float MotionVel = 100.0;
        float DrownVel = 10.0;
        float RotationVel = 1.0;

    public:
        int HP = 100;
        glm::vec3 position;
        glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 lookat = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 angle = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::mat4 modelMatrix;
        glm::mat4 rotateMatrix;

        bool isSpawn = false;
        bool isDrown = false;
        double shootTime = glfwGetTime();

        PirateShip() {}

        ~PirateShip() {
            // delete model;
        }

        void Init(glm::vec3 position, glm::mat4 modelMatrix)
        {
            this->position = position;
            this->modelMatrix = glm::translate(glm::mat4(1), position);
            this->rotateMatrix = glm::mat4(1);
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

        void move_forward(float dt) {
            position += forward * MotionVel * dt;
            modelMatrix = glm::translate(modelMatrix, forward * MotionVel * dt);
        }

        void move_back(float dt) {
            position -= forward * MotionVel * dt;
            modelMatrix = glm::translate(modelMatrix, -forward * MotionVel * dt);
        }

        void rotate_clockwise(float dt) {
            angle.x += RotationVel * dt;
            rotateMatrix = glm::rotate(rotateMatrix, -RotationVel * dt, glm::vec3(0.0f, 1.0f, 0.0f));           
            
            forward.x = sin(angle.x);
            forward.y = 0.0f;         
            forward.z = -cos(angle.x);

            right = glm::cross(forward, up);
        }

        void rotate_anticlockwise(float dt) {
            angle.x -= RotationVel * dt;
            rotateMatrix = glm::rotate(rotateMatrix, RotationVel * dt, glm::vec3(0.0f, 1.0f, 0.0f));
            
            forward.x = sin(angle.x);
            forward.y = 0.0f;         
            forward.z = -cos(angle.x);

            right = glm::cross(forward, up);
        }

        void drown(float dt) {
            position.y -= DrownVel * dt;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, -DrownVel * dt, 0.0f));
        }
};

#endif