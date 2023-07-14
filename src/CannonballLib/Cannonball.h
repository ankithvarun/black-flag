#ifndef CANNON_BALL_H
#define CANNON_BALL_H

#include "stdafx.h"

class Cannonball {
    private:
        float RotationVel = 1.0;

    public:
        glm::vec3 initPosition;
        glm::vec3 position;
        glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::mat4 modelMatrix;
        glm::mat4 rotateMatrix;

        bool isSpawn = false;
        int shipIndex;
        float shootSpeed;

        Cannonball(){}

        ~Cannonball() {
            // std::cout << "Cannonball Destructor" << std::endl;
        }

        void Init(glm::vec3 position, glm::vec3 forward, glm::mat4 modelMatrix, int shipIndex, float shootSpeed)
        {
            this->position = position;
            this->initPosition = position;
            this->forward = forward;
            this->modelMatrix = glm::translate(glm::mat4(1), position);
            this->rotateMatrix = glm::mat4(1);
            this->shipIndex = shipIndex;
            this->shootSpeed = shootSpeed;
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

        void move_forward()
        {
            position += forward * shootSpeed;
            modelMatrix = glm::translate(modelMatrix, forward * shootSpeed);
        }
};

#endif