#include "Sphere.hpp"

Sphere::Sphere() {
    Build(32, 16);

    mVAO = VAO::Create();
    mVBO = VBO<Vertex>::Create(mVertices);
    mEBO = EBO<GLuint>::Create(mElements);

    mVAO->Bind();
    mVBO->Bind();
    VAO::SetFloat3(0, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, position)));
    VBO<GLuint>::Unbind();
    VAO::Unbind();
}

Sphere::Sphere(const std::uint32_t sectors, const std::uint32_t stacks) {
    Build(sectors, stacks);

    mVAO = VAO::Create();
    mVBO = VBO<Vertex>::Create(mVertices);
    mEBO = EBO<GLuint>::Create(mElements);

    mVAO->Bind();
    mVBO->Bind();
    VAO::SetFloat3(0, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, position)));
    VBO<GLuint>::Unbind();
    VAO::Unbind();
}

void Sphere::Build(const std::uint32_t sectors, const std::uint32_t stacks) {
    for (std::uint32_t stack = 0; stack <= stacks; ++stack) {
        const float stack_step = glm::pi<float>() / static_cast<float>(stacks);
        const float stack_angle = static_cast<float>(stack) * stack_step;

        const float y = glm::cos(stack_angle);

        for (std::uint32_t sector = 0; sector <= sectors; ++sector) {
            const float sector_step = 2.0f * glm::pi<float>() / static_cast<float>(sectors);
            const float sector_angle = static_cast<float>(sector) * sector_step;

            const float x = glm::sin(stack_angle) * glm::cos(sector_angle);
            const float z = glm::sin(stack_angle) * glm::sin(sector_angle);

            mVertices.push_back({{0.5f * x, 0.5f * y, 0.5f * z}});
        }
    }

    for (std::uint32_t stack = 0; stack < stacks; ++stack) {
        std::uint32_t k1 = stack * (sectors + 1);
        std::uint32_t k2 = k1 + sectors + 1;

        for (std::uint32_t sector = 0; sector < sectors; ++sector) {
            if (stack != 0) {
                mElements.push_back(k1);
                mElements.push_back(k2);
                mElements.push_back(k1 + 1);
            }

            if (stack != (stacks - 1)) {
                mElements.push_back(k1 + 1);
                mElements.push_back(k2);
                mElements.push_back(k2 + 1);
            }

            ++k1;
            ++k2;
        }
    }
}

void Sphere::Draw() const {
    mVAO->Bind();

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mElements.size()), GL_UNSIGNED_INT, static_cast<void *>(nullptr));

    VAO::Unbind();
}

void Sphere::Delete() const {
    mVAO->Delete();
    mVBO->Delete();
    mEBO->Delete();
}
