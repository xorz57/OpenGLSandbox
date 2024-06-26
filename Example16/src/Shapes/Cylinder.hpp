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

class Cylinder {
public:
    Cylinder();
    explicit Cylinder(std::uint32_t sectors);

    void Draw() const;
    void Delete() const;

    [[nodiscard]] glm::mat4 GetModel() const;

    void Scale(const glm::vec3 &v);
    void Translate(const glm::vec3 &v);
    void Rotate(float angle, const glm::vec3 &v);
    void Reset();

private:
    void Build(std::uint32_t sectors);

    struct Vertex {
        glm::vec3 position;
        glm::vec2 texture_coordinates;
    };

    std::vector<Vertex> mVertices;
    std::vector<GLuint> mElements1;
    std::vector<GLuint> mElements2;
    std::vector<GLuint> mElements3;

    glm::mat4 mModel{1.0f};

    std::shared_ptr<VAO> mVAO;
    std::shared_ptr<VBO<Vertex>> mVBO;
    std::shared_ptr<EBO<GLuint>> mEBO1;
    std::shared_ptr<EBO<GLuint>> mEBO2;
    std::shared_ptr<EBO<GLuint>> mEBO3;
    std::shared_ptr<Texture> mTexture;
};
