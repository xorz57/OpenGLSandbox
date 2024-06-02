#include "Cylinder.hpp"

Cylinder::Cylinder() {
    Build(32);

    mVAO = VAO::Create();
    mVBO = VBO<Vertex>::Create(mVertices);
    mTopCircleEBO = EBO<GLuint>::Create(mTopCircleElements);
    mBottomCircleEBO = EBO<GLuint>::Create(mBottomCircleElements);
    mSideEBO = EBO<GLuint>::Create(mSideElements);
    mTexture = Texture::Create("assets/textures/cylinder.png");

    mVAO->Bind();
    mVBO->Bind();
    VAO::SetFloat3(0, sizeof(Vertex), (void *) offsetof(Vertex, position));
    VAO::SetFloat2(1, sizeof(Vertex), (void *) offsetof(Vertex, texture_coordinates));
    VBO<GLuint>::Unbind();
    VAO::Unbind();
}

Cylinder::Cylinder(std::uint32_t sectors) {
    Build(sectors);

    mVAO = VAO::Create();
    mVBO = VBO<Vertex>::Create(mVertices);
    mTopCircleEBO = EBO<GLuint>::Create(mTopCircleElements);
    mBottomCircleEBO = EBO<GLuint>::Create(mBottomCircleElements);
    mSideEBO = EBO<GLuint>::Create(mSideElements);
    mTexture = Texture::Create("assets/textures/cylinder.png");

    mVAO->Bind();
    mVBO->Bind();
    VAO::SetFloat3(0, sizeof(Vertex), (void *) offsetof(Vertex, position));
    VAO::SetFloat2(1, sizeof(Vertex), (void *) offsetof(Vertex, texture_coordinates));
    VBO<GLuint>::Unbind();
    VAO::Unbind();
}

void Cylinder::Build(std::uint32_t sectors) {
    mVertices.clear();
    mTopCircleElements.clear();
    mBottomCircleElements.clear();
    mSideElements.clear();

    mVertices.push_back({{0.0f, 0.5f, 0.0f}, {0.5f, 0.5f}});
    for (std::uint32_t i = 0; i <= sectors; ++i) {
        float angle = 2.0f * glm::pi<float>() * static_cast<float>(i) / static_cast<float>(sectors);
        float x = 0.5f * glm::cos(angle);
        float z = 0.5f * glm::sin(angle);
        float u = 0.5f + 0.5f * glm::cos(angle);
        float v = 0.5f + 0.5f * glm::sin(angle);
        mVertices.push_back({{x, 0.5f, z}, {u, v}});
    }
    for (std::uint32_t i = 1; i <= sectors; ++i) {
        mTopCircleElements.push_back(0);
        mTopCircleElements.push_back(i);
        mTopCircleElements.push_back(i + 1);
    }

    size_t offset = mVertices.size();

    mVertices.push_back({{0.0f, -0.5f, 0.0f}, {0.5f, 0.5f}});
    for (std::uint32_t i = 0; i <= sectors; ++i) {
        float angle = 2.0f * glm::pi<float>() * static_cast<float>(i) / static_cast<float>(sectors);
        float x = 0.5f * glm::cos(angle);
        float z = 0.5f * glm::sin(angle);
        float u = 0.5f + 0.5f * glm::cos(angle);
        float v = 0.5f + 0.5f * glm::sin(angle);
        mVertices.push_back({{x, -0.5f, z}, {u, v}});
    }
    for (std::uint32_t i = 1; i <= sectors; ++i) {
        mBottomCircleElements.push_back(static_cast<GLuint>(offset));
        mBottomCircleElements.push_back(static_cast<GLuint>(offset + i + 1));
        mBottomCircleElements.push_back(static_cast<GLuint>(offset + i));
    }

    for (std::uint32_t i = 1; i <= sectors; ++i) {
        std::uint32_t top1 = i;
        std::uint32_t top2 = i + 1;
        std::uint32_t bottom1 = static_cast<std::uint32_t>(offset) + i;
        std::uint32_t bottom2 = static_cast<std::uint32_t>(offset) + i + 1;

        mSideElements.push_back(top1);
        mSideElements.push_back(bottom1);
        mSideElements.push_back(top2);

        mSideElements.push_back(top2);
        mSideElements.push_back(bottom1);
        mSideElements.push_back(bottom2);
    }
}

void Cylinder::Draw() const {
    mVAO->Bind();
    mTexture->Bind();

    mTopCircleEBO->Bind();
    glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(mTopCircleElements.size()), GL_UNSIGNED_INT, nullptr);

    mBottomCircleEBO->Bind();
    glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(mBottomCircleElements.size()), GL_UNSIGNED_INT, nullptr);

    mSideEBO->Bind();
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mSideElements.size()), GL_UNSIGNED_INT, nullptr);

    Texture::Unbind();
    VAO::Unbind();
}

void Cylinder::Delete() const {
    mVAO->Delete();
    mVBO->Delete();
    mTopCircleEBO->Delete();
    mBottomCircleEBO->Delete();
    mSideEBO->Delete();
}

void Cylinder::Scale(const glm::vec3 &v) {
    mModel = glm::scale(mModel, v);
}

void Cylinder::Translate(const glm::vec3 &v) {
    mModel = glm::translate(mModel, v);
}

void Cylinder::Rotate(float angle, const glm::vec3 &v) {
    mModel = glm::rotate(mModel, angle, v);
}

void Cylinder::Reset() {
    mModel = glm::mat4(1.0f);
}

glm::mat4 Cylinder::GetModel() const {
    return mModel;
}
