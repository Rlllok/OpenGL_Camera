#include "camera.h"
#include <cmath>


Camera::Camera(glm::vec3 position, glm::vec3 worldUpVector, float maxFOV, float movementSpeed, float mouseSensetivity)
{
    PositionVector = position;
    WorldUpVector = worldUpVector;
    MaxFOV = maxFOV;
    CurrentFOV = maxFOV;
    MovementSpeed = movementSpeed;
    MouseSensetivity = mouseSensetivity;
    Yaw = 90.0f;
    Pitch = 0.0f;
    UpdateCameraVectors();
}


float Camera::GetCurrentFOV()
{
    return CurrentFOV;
}


glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(PositionVector, PositionVector + FrontVector, UpVector);
}


void Camera::RotateCamera(float YawOffset, float PitchOffset)
{
    Yaw += YawOffset;
    Pitch += PitchOffset;

    if (Pitch > 89.0f) {
        Pitch = 89.0f;
    }
    if (Pitch < -89.0f) {
        Pitch = -89.0f;
    }

    UpdateCameraVectors();
}


void Camera::RotateCameraByMouse(float xOffset, float yOffset, float deltaTime)
{
    Yaw += xOffset * MouseSensetivity * deltaTime;
    Pitch += yOffset * MouseSensetivity * deltaTime;

    if (Pitch > 89.0f) {
        Pitch = 89.0f;
    }
    if (Pitch < -89.0f) {
        Pitch = -89.0f;
    }

    UpdateCameraVectors();
}


void Camera::MoveCamera(CAMERA_MOVEMENT direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD) {
        PositionVector += FrontVector * velocity;
    }
    if (direction == BACKWARD) {
        PositionVector -= FrontVector * velocity;
    }
    if (direction == RIGHT) {
        PositionVector += RightVector * velocity;
    }
    if (direction == LEFT) {
        PositionVector -= RightVector * velocity;
    }
}


void Camera::UpdateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    FrontVector = glm::normalize(front);
    
    RightVector = glm::cross(FrontVector, WorldUpVector);
    RightVector = glm::normalize(RightVector);

    UpVector = glm::cross(RightVector, FrontVector);
    UpVector = glm::normalize(UpVector);
}
