#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 transform;\n"
"void main()\n"
"{\n"
"	gl_Position = transform * vec4(aPos, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec3 color;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(color, 1.0f);\n"
"}\n\0";

// Function to process user input
void processInput(GLFWwindow* window, glm::vec3& translation, float& rotation, glm::vec3& scale, int objectID) {
    float translationSpeed = 0.001f;
    float rotationSpeed = 0.01f;
    float scaleSpeed = 0.0001f;

    if (objectID == 1) { // Plate controls
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            translation.y += translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            translation.y -= translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            translation.x -= translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            translation.x += translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            rotation += rotationSpeed;
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            rotation -= rotationSpeed;
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
            scale += glm::vec3(scaleSpeed);
        if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
            scale -= glm::vec3(scaleSpeed);
    }
    else if (objectID == 2) { // Cake controls
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
            translation.y += translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
            translation.y -= translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
            translation.x -= translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
            translation.x += translationSpeed;
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
            rotation += rotationSpeed;
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
            rotation -= rotationSpeed;
        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
            scale += glm::vec3(scaleSpeed);
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
            scale -= glm::vec3(scaleSpeed);
    }
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "First Window", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create an window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, 800, 800);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLfloat cake[] = {
        0.150, 0.672, 0.0,
        0.148, 0.241, 0.0,
        0.198, 0.644, 0.0,
        0.190, 0.203, 0.0,
        0.245, 0.620, 0.0,
        0.232, 0.172, 0.0,
        0.296, 0.594, 0.0,
        0.282, 0.145, 0.0,
        0.354, 0.577, 0.0,
        0.332, 0.125, 0.0,
        0.415, 0.566, 0.0,
        0.390, 0.112, 0.0,
        0.479, 0.566, 0.0,
        0.464, 0.109, 0.0,
        0.550, 0.562, 0.0,
        0.552, 0.107, 0.0,
        0.624, 0.578, 0.0,
        0.643, 0.122, 0.0,
        0.691, 0.593, 0.0,
        0.718, 0.142, 0.0,
        0.762, 0.623, 0.0,
        0.784, 0.178, 0.0,
        0.821, 0.658, 0.0,
        0.835, 0.214, 0.0,
        0.856, 0.677, 0.0,
        0.854, 0.243, 0.0,
        0.856, 0.676, 0.0,
        0.820, 0.739, 0.0,
        0.822, 0.660, 0.0,
        0.756, 0.768, 0.0,
        0.761, 0.620, 0.0,
        0.696, 0.789, 0.0,
        0.692, 0.593, 0.0,
        0.628, 0.803, 0.0,
        0.625, 0.579, 0.0,
        0.544, 0.808, 0.0,
        0.553, 0.563, 0.0,
        0.466, 0.811, 0.0,
        0.478, 0.566, 0.0,
        0.414, 0.800, 0.0,
        0.415, 0.566, 0.0,
        0.353, 0.791, 0.0,
        0.355, 0.576, 0.0,
        0.291, 0.775, 0.0,
        0.298, 0.593, 0.0,
        0.247, 0.754, 0.0,
        0.245, 0.618, 0.0,
        0.198, 0.734, 0.0,
        0.197, 0.643, 0.0,
        0.149, 0.674, 0.0,
        0.149, 0.674, 0.0
    };

    GLfloat plate[] = {
        0.002, 0.276, 0.0,
        0.028, 0.352, 0.0,
        0.026, 0.189, 0.0,
        0.073, 0.400, 0.0,
        0.071, 0.138, 0.0,
        0.132, 0.440, 0.0,
        0.132, 0.099, 0.0,
        0.210, 0.471, 0.0,
        0.195, 0.066, 0.0,
        0.285, 0.491, 0.0,
        0.272, 0.045, 0.0,
        0.368, 0.504, 0.0,
        0.355, 0.031, 0.0,
        0.455, 0.509, 0.0,
        0.452, 0.021, 0.0,
        0.542, 0.516, 0.0,
        0.539, 0.027, 0.0,
        0.614, 0.523, 0.0,
        0.631, 0.036, 0.0,
        0.672, 0.513, 0.0,
        0.708, 0.048, 0.0,
        0.735, 0.507, 0.0,
        0.779, 0.067, 0.0,
        0.806, 0.484, 0.0,
        0.842, 0.090, 0.0,
        0.867, 0.447, 0.0,
        0.900, 0.126, 0.0,
        0.911, 0.418, 0.0,
        0.956, 0.164, 0.0,
        0.960, 0.377, 0.0,
        0.993, 0.207, 0.0,
        0.987, 0.338, 0.0,
        1.002, 0.277, 0.0
    };



    GLuint VAO[2], VBO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cake), cake, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plate), plate, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glm::vec3 cakeTranslation(0.0f), plateTranslation(0.0f);
    float cakeRotation = 0.0f, plateRotation = 0.0f;
    glm::vec3 cakeScale(1.0f), plateScale(1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window, plateTranslation, plateRotation, plateScale, 1);
        processInput(window, cakeTranslation, cakeRotation, cakeScale, 2);

        glUseProgram(shaderProgram);

        glm::mat4 plateTransform = glm::translate(glm::mat4(1.0f), plateTranslation);
        plateTransform = glm::rotate(plateTransform, glm::radians(plateRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        plateTransform = glm::scale(plateTransform, plateScale);

        GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(plateTransform));
        glUniform3f(glGetUniformLocation(shaderProgram, "color"), 1.0f, 1.0f, 1.0f);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 33);

        glm::mat4 cakeTransform = glm::translate(glm::mat4(1.0f), cakeTranslation);
        cakeTransform = glm::rotate(cakeTransform, glm::radians(cakeRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        cakeTransform = glm::scale(cakeTransform, cakeScale);

        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(cakeTransform));
        glUniform3f(glGetUniformLocation(shaderProgram, "color"), 0.0f, 0.0f, 0.0f);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 26);
        glUniform3f(glGetUniformLocation(shaderProgram, "color"), 0.9f, 0.5f, 0.5f);
        glDrawArrays(GL_TRIANGLE_STRIP, 26, 25);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
