#include "Object.h"

Object::Object() :
	_vaoID(0),
	_vboID(0),
	_eboID(0)
{
	
}

Object::~Object() {
	if (_vaoID != 0)
		glDeleteVertexArrays(1, &_vaoID);
	if (_vboID != 0)
		glDeleteBuffers(1, &_vboID);
	if (_eboID != 0)
		glDeleteBuffers(1, &_eboID);
	
}

void Object::init(ObjectStruct objInfo) {
	
	if (_vaoID == 0)
		glGenVertexArrays(1, &_vaoID);
	if (_vboID == 0)
		glGenBuffers(1, &_vboID);
	if (_eboID == 0)
		glGenBuffers(1, &_eboID);

	VertexStruct vertexData[4];

	float x = objInfo.x;
	float y = objInfo.y;
	float width = objInfo.width;
	float height = objInfo.height;

	vertexData[0].position.x = x + width;
	vertexData[0].position.y = y + height;

	vertexData[1].position.x = x + width;
	vertexData[1].position.y = y;

	vertexData[2].position.x = x;
	vertexData[2].position.y = y;

	vertexData[3].position.x = x;
	vertexData[3].position.y = y + height;
	
	for (int i = 0; i < 4; i++) {
		vertexData[i].color.r = 255;
		vertexData[i].color.g = 255;
		vertexData[i].color.b = 255;
		vertexData[i].color.a = 255;
	}

	GLuint indices[]{
		0, 1, 3,
		1, 2, 3
	};

	vertexCount = sizeof(indices) / sizeof(*indices);

	upload(vertexData, sizeof(vertexData), indices, sizeof(indices));
	
}

void Object::upload(VertexStruct vertexData[], int sizeOfVertexData, GLuint indices[], int sizeOfIndices) {
	glBindVertexArray(_vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);

	glBufferData(GL_ARRAY_BUFFER, sizeOfVertexData, vertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertexStruct), (void*)offsetof(VertexStruct, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertexStruct), (void*)offsetof(VertexStruct, color));
	glEnableVertexAttribArray(1);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices, indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Object::draw() {
	glBindVertexArray(_vaoID);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}
