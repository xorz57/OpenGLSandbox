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

class Capsule {
public:
    Capsule();
    explicit Capsule(std::uint32_t sectors, std::uint32_t stacks);

    void Draw() const;
    void Delete() const;

private:
    void Build(std::uint32_t sectors, std::uint32_t stacks);

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
    };

    std::vector<Vertex> mVertices;
    std::vector<GLuint> mElements;

    std::shared_ptr<VAO> mVAO;
    std::shared_ptr<VBO<Vertex>> mVBO;
    std::shared_ptr<EBO<GLuint>> mEBO;
};
