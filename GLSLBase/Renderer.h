#pragma once

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Dependencies\glew.h"
#include "Dependencies\wglew.h"
#include "Dependencies\glm/glm.hpp"
#include "Dependencies\glm/gtc/matrix_transform.hpp"
#include "Dependencies\glm/gtx/euler_angles.hpp"

class Renderer
{
public:
	Renderer(int windowSizeX, int windowSizeY);
	~Renderer();

	GLuint CreatePngTexture(char * filePath);
	GLuint CreateBmpTexture(char * filePath);
	   
	void Test();
	void Lecture2();
	void Particle();
	void Lecture3();
	void Lecture4();

	int particle_count = 0;

private:
	void Initialize(int windowSizeX, int windowSizeY);
	bool ReadFile(char* filename, std::string *target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void CreateVertexBufferObjects();							// 기본 Vertex Buffer Object 생성
	void GenQuadsVBO(int count);								// 랜덤한 count 개수만큼의 
																// 작은 사각형 파티클 Vertex Buffer Object 생성
	void CreateProxyGeometry();									// 평면의 Geometry Vertex Buffer Object 생성
	unsigned char * Renderer::loadBMPRaw(const char * imagepath, unsigned int& outWidth, unsigned int& outHeight);

	bool m_Initialized = false;
	
	unsigned int m_WindowSizeX = 0;
	unsigned int m_WindowSizeY = 0;

	GLuint m_VBORect = 0;
	GLuint m_VBORectColor = 0;

	// Lecture2
	GLuint m_VBOTri = 0;

	// Particle
	GLuint randQuads = 0;

	// Lecture3
	int m_VBOGridMesh_Count = 0;
	GLuint m_VBOGridMesh = 0;

	//Shaders
	GLuint m_SolidRectShader = 0;
	GLuint m_SimpleVelShader = 0;
};

