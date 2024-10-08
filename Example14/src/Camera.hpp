#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    [[nodiscard]] glm::mat4 GetView() const;
    [[nodiscard]] glm::mat4 GetProjection(float aspect) const;

private:
    glm::vec3 mEye{0.0f, 0.0f, 8.0f};
    glm::vec3 mCenter{0.0f, 0.0f, 0.0f};
    glm::vec3 mUp{0.0f, 1.0f, 0.0f};
    float mFOV = glm::radians(45.0f);
    float mNear = 0.1f;
    float mFar = 100.0f;
};
