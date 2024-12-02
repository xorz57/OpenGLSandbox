#pragma once

#include "../EBO.hpp"
#include "../VAO.hpp"
#include "../VBO.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <memory>
#include <vector>

class Quad {
public:
    Quad();

    void Draw() const;
    void Delete() const;

private:
    struct Vertex {
        glm::vec3 position;
    };

    const std::vector<Vertex> mVertices{
            {{-0.5f, -0.5f, +0.0f}},// 0
            {{+0.5f, -0.5f, +0.0f}},// 1
            {{-0.5f, +0.5f, +0.0f}},// 2
            {{+0.5f, +0.5f, +0.0f}},// 3
    };

    const std::vector<GLuint> mElements{
            0,// 0
            1,// 1
            2,// 2
            2,// 3
            1,// 4
            3,// 5
    };

    std::shared_ptr<VAO> mVAO;
    std::shared_ptr<VBO<Vertex>> mVBO;
    std::shared_ptr<EBO<GLuint>> mEBO;
};
