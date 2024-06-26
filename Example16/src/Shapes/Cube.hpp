#pragma once

#include "../EBO.hpp"
#include "../Texture.hpp"
#include "../VAO.hpp"
#include "../VBO.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <memory>
#include <vector>

class Cube {
public:
    Cube();

    void Draw() const;
    void Delete() const;

    [[nodiscard]] glm::mat4 GetModel() const;

    void Scale(const glm::vec3 &v);
    void Translate(const glm::vec3 &v);
    void Rotate(float angle, const glm::vec3 &v);
    void Reset();

private:
    struct Vertex {
        glm::vec3 position;
        glm::vec2 texture_coordinates;
    };

    const std::vector<Vertex> mVertices{
            {{-0.5f, -0.5f, -0.5f}, {+0.0f, +0.0f}},// 0
            {{+0.5f, -0.5f, -0.5f}, {+1.0f, +0.0f}},// 1
            {{+0.5f, +0.5f, -0.5f}, {+1.0f, +1.0f}},// 2
            {{-0.5f, +0.5f, -0.5f}, {+0.0f, +1.0f}},// 3

            {{-0.5f, -0.5f, +0.5f}, {+0.0f, +0.0f}},// 4
            {{+0.5f, -0.5f, +0.5f}, {+1.0f, +0.0f}},// 5
            {{+0.5f, +0.5f, +0.5f}, {+1.0f, +1.0f}},// 6
            {{-0.5f, +0.5f, +0.5f}, {+0.0f, +1.0f}},// 7

            {{-0.5f, +0.5f, +0.5f}, {+1.0f, +0.0f}},// 8
            {{-0.5f, +0.5f, -0.5f}, {+1.0f, +1.0f}},// 9
            {{-0.5f, -0.5f, -0.5f}, {+0.0f, +1.0f}},// 10
            {{-0.5f, -0.5f, +0.5f}, {+0.0f, +0.0f}},// 11

            {{+0.5f, +0.5f, +0.5f}, {+1.0f, +0.0f}},// 12
            {{+0.5f, +0.5f, -0.5f}, {+1.0f, +1.0f}},// 13
            {{+0.5f, -0.5f, -0.5f}, {+0.0f, +1.0f}},// 14
            {{+0.5f, -0.5f, +0.5f}, {+0.0f, +0.0f}},// 15

            {{-0.5f, -0.5f, -0.5f}, {+0.0f, +1.0f}},// 16
            {{+0.5f, -0.5f, -0.5f}, {+1.0f, +1.0f}},// 17
            {{+0.5f, -0.5f, +0.5f}, {+1.0f, +0.0f}},// 18
            {{-0.5f, -0.5f, +0.5f}, {+0.0f, +0.0f}},// 19

            {{-0.5f, +0.5f, -0.5f}, {+0.0f, +1.0f}},// 20
            {{+0.5f, +0.5f, -0.5f}, {+1.0f, +1.0f}},// 21
            {{+0.5f, +0.5f, +0.5f}, {+1.0f, +0.0f}},// 22
            {{-0.5f, +0.5f, +0.5f}, {+0.0f, +0.0f}},// 23
    };

    const std::vector<GLuint> mElements{
            0, 1, 2, 2, 3, 0,      // 0
            4, 5, 6, 6, 7, 4,      // 1
            8, 9, 10, 10, 11, 8,   // 2
            12, 13, 14, 14, 15, 12,// 3
            16, 17, 18, 18, 19, 16,// 4
            20, 21, 22, 22, 23, 20,// 5
    };

    glm::mat4 mModel{1.0f};

    std::shared_ptr<VAO> mVAO;
    std::shared_ptr<VBO<Vertex>> mVBO;
    std::shared_ptr<EBO<GLuint>> mEBO;
    std::shared_ptr<Texture> mTexture;
};
