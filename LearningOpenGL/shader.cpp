#include"shader.h"

//This file is used to manage our shader program
//Author: Xingyu Feng

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
  }
  catch (std::ifstream::failure) {
    cout <<  
  }

}

void Shader::Use() {
  glUseProgram(shader_program_);
}
