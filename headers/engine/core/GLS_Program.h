#pragma once

#ifndef _SHADER_
#define _SHADER_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include "../utils/Error.h"

using namespace std;

class GLS_Program {
	GLuint _programID;
	GLuint _fragmentShaderID;
	GLuint _vertexShaderID;

	void compileShader(const string& shaderPath, GLuint id);

public:
	int _numAtribute;
	
	GLS_Program();
	~GLS_Program();

	void addAtribute(const string atributeName);
	
	void use();
	void unuse();
	
	void compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void linkShader();

	GLuint getUniformLocation(const string& name);

};

#include "GLS_Program.inl"
#endif
