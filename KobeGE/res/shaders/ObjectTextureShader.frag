#version 330 core

in vec2 texCoord;

layout (location = 0) out vec4 color;

uniform sampler2D textureData;

void main() {
	color = texture(textureData, texCoord);
}