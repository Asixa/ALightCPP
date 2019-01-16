#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "vec3.h"
const GLint  ImageWidth = 512;
const GLint  ImageHeight = 512;
const int SPP = 8;
GLint    PixelLength;
GLbyte* PixelData;
const GLint SamplingRate = 1000;
const GLint rgbwidth = ImageWidth * 4;
vec3* col;


long seed = 1;
double drand48()
{
	seed = (0x5DEECE66DL * seed + 0xB16) & 0xFFFFFFFFFFFFL;
	return (seed >> 16) / (0x100000000L);
}