#pragma once

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
private:

    unsigned int ID;

public:

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    unsigned int getShaderID() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void checkCompileErrors(unsigned int shader, std::string type);
};