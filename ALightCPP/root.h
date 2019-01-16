#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "vec3.h"
const GLint  ImageWidth = 512;
const GLint  ImageHeight = 512;
GLint    PixelLength;
GLbyte* PixelData;
const GLint SamplingRate = 1000;
const GLint rgbwidth = ImageWidth * 4;
vec3* col;