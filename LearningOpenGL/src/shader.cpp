#include"shader.h"

//This file is used to manage our shader program
//We can create a shader program and init here! 
//Author: Xingyu Feng
//Date: 12.1.2021

Shader::Shader(const char* vertexshader_path, const char* fragmentshader_path) {
  //init filestream
  std::ifstream vshader_fstream;
  std::ifstream fshader_fstream;
  std::string vertex_code;
  std::string fragment_code;
  vshader_fstream.exceptions(std::ifstream::badbit || std::ifstream::failbit);
  fshader_fstream.exceptions(std::ifstream::badbit || std::ifstream::failbit);
  try {
    vshader_fstream.open(vertexshader_path);
    fshader_fstream.open(fragmentshader_path);
    std::stringstream v_shader_stringstream, f_shader_stringstream;
    v_shader_stringstream << vshader_fstream.rdbuf();
    f_shader_stringstream << fshader_fstream.rdbuf();
    vshader_fstream.close();
    fshader_fstream.close();
    vertex_code = v_shader_stringstream.str();
    fragment_code = f_shader_stringstream.str();
  }
  catch (std::ifstream::failure) {
    std::cout << "We got some problems in reading files!";
  }
  // Transfer our string to c style stiring
  const char* v_shader_code = vertex_code.c_str();
  const char* f_shader_code = fragment_code.c_str();
  unsigned int vertex, fragment;
  int success;
  char infolog[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(vertex, 1, &v_shader_code, NULL);
  glShaderSource(fragment, 1, &f_shader_code, NULL);
  glCompileShader(vertex);
  glCompileShader(fragment);

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infolog);
    std::cout << "Vertex shader compile error: " << infolog << std::endl;
  }

  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infolog);
    std::cout << "Fragment shader compile error: " << infolog << std::endl;
  }

  shader_program_ = glCreateProgram();
  glAttachShader(shader_program_, vertex);
  glAttachShader(shader_program_, fragment);
  glLinkProgram(shader_program_);
  //Check our program error and print it

  glGetProgramiv(shader_program_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shader_program_, 512, NULL, infolog);
    std::cout << "Link got some problems: " << infolog << std::endl;
  }
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::Use() {
  glUseProgram(shader_program_);
}
