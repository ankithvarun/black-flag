#ifndef TREASURE_H
#define TREASURE_H

#include "stdafx.h"

class Treasure {

    public:
        glm::vec3 position;
        glm::mat4 modelMatrix;
        glm::mat4 rotateMatrix;
        bool isSpawn = false;

        int value = 50;

        Treasure(){}

        ~Treasure() {
            // std::cout << "Cannonball Destructor" << std::endl;
        }

        void Init(glm::vec3 position, glm::mat4 modelMatrix)
        {
            this->position = position;
            this->modelMatrix = glm::scale(glm::translate(glm::mat4(1), position), glm::vec3(5.0f, 5.0f, 5.0f));
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
};

#endif