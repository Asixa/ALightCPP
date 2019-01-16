
#include <iostream>
#include "GLWindow.h"
using namespace std;


void InitData()
{
	PixelLength = ImageHeight*ImageWidth*4;
	PixelData = new GLbyte[PixelLength];
	col = new vec3[ImageHeight*ImageWidth];
	//InitWindow zero
	for (auto i = 0; i < PixelLength; i++)
		PixelData[i] = static_cast<GLbyte>(int(0));
}


int main(int argc, char* argv[])
{
	InitData();
	InitWindow(argc, argv, GLUT_DOUBLE | GLUT_RGBA, 100, 100, ImageWidth, ImageHeight, "ALight");
	return 0;
}

void render()
{
	for (auto j = ImageHeight - 1; j >= 0; j--)
		for (auto i = 0; i < ImageWidth; i++)
			SetPixel(i, j, &vec3(float(i) / float(ImageWidth), float(j) / float(ImageHeight), 0.2f));
}
