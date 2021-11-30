#pragma once
#include"glad/glad.h"
#include<sstream>
#include<iostream>
#include<fstream>


class Shader {
 public:
  Shader(const char* vertexshader_path, const char* fragmentshader_path);
  void Use();
 private:
   GLuint shader_program_;
};