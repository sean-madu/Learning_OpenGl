#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>


enum CameraDirection {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};


class Camera {
	
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
    float speed = 2.5f;

	Camera(glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f), 	glm::vec3 camFront = glm::vec3(0.0f, 0.0f, -1.0f),	glm::vec3 camUp = glm::vec3(0.0f, 1.0f, 0.0f)){
		position = camPos;
		front = camFront;
		up = camUp;

	}

    void processKeyboard(CameraDirection direction, float deltaTime)
    {
        float velocity = speed * deltaTime;
        glm::vec3 right = glm::normalize(glm::cross(front, up));
        if (direction == FORWARD)
            position += front * velocity;
        if (direction == BACKWARD)
            position -= front * velocity;
        if (direction == LEFT)
            position -=  right * velocity;
        if (direction == RIGHT)
            position += right * velocity;
    }
};
#endif
