#pragma once
#include <GL/glew.h>
#include <cstddef>
#include <iostream>
#include "Structs/ObjectStruct.h"
#include "Structs/VertexStruct.h"

class Object {
public:
	Object();
	~Object();
	virtual void init(ObjectStruct objInfo);
	void draw();
private:
	void upload(VertexStruct vertexData[], int sizeOfVertexData, GLuint indices[], int sizeOfIndices);
	GLuint _vboID;
	GLuint _vaoID;
	GLuint _eboID;
	int vertexCount;
};

