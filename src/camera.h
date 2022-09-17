#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


class Camera
{
private:

    float Yaw;
    float Pitch;
    float CurrentFOV;
    float MaxFOV;
    float MovementSpeed;
    float MouseSensetivity;
    glm::vec3 PositionVector;
    glm::vec3 WorldUpVector;
    glm::vec3 FrontVector;
    glm::vec3 RightVector;
    glm::vec3 UpVector;

    void UpdateCameraVectors();

public:

    enum CAMERA_MOVEMENT {
        FORWARD,
        BACKWARD,
        RIGHT,
        LEFT
    };

    Camera(
        glm::vec3 position,
        glm::vec3 worldUpVector = glm::vec3(0.0f, 1.0f, 0.0f),
        float maxFOV = 45.0f,
        float MovementSpeed = 2.0f,
        float mouseSensetivity = 0.1f
    );
    
    float GetCurrentFOV();
    glm::mat4 GetViewMatrix();
    void RotateCamera(float YawOffset, float PitchOffset);
    void RotateCameraByMouse(float xOffset, float yOffset, float deltaTime = 1.0f);
    void MoveCamera(CAMERA_MOVEMENT direction, float deltaTime);
};