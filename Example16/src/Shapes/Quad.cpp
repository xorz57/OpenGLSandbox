#include "Quad.hpp"

Quad::Quad() {
    mVAO = VAO::Create();
    mVBO = VBO<Vertex>::Create(mVertices);
    mEBO = EBO<GLuint>::Create(mElements);
    mTexture = Texture::Create("assets/textures/quad.png");

    mVAO->Bind();
    mVBO->Bind();
    VAO::SetFloat3(0, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, position)));
    VAO::SetFloat2(1, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, texture_coordinates)));
    VBO<GLuint>::Unbind();
    VAO::Unbind();
}

void Quad::Draw() const {
    mVAO->Bind();
    mTexture->Bind();

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mElements.size()), GL_UNSIGNED_INT, static_cast<void *>(nullptr));

    Texture::Unbind();
    VAO::Unbind();
}

void Quad::Delete() const {
    mVAO->Delete();
    mVBO->Delete();
    mEBO->Delete();
}
