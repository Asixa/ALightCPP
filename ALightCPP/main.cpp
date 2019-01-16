
#include <iostream>
#include "GLWindow.h"
#include "Sphere.h"
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

vec3 shade(const ray& r)
{
	if (hit_sphere(vec3(0, 0, -1), 0.5, r))return vec3(1, 0, 0);
	vec3 unit_dir = unit_vector(r.direction());
	float t = 0.5*(unit_dir.y() + 1);
	return  (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
void render()
{
	// for (auto j = ImageHeight - 1; j >= 0; j--)
	// 	for (auto i = 0; i < ImageWidth; i++)
	// 		SetPixel(i, j, &vec3(float(i) / float(ImageWidth), float(j) / float(ImageHeight), 0.2f));

	const vec3 lower_left_corner(-2.0, -2.0, -1.0),horizontal(4, 0, 0), vertical(0, 4, 0), origin(0, 0, 0);

	for (auto j=ImageHeight-1;j>=0;j--)
		for (auto i=0;i<ImageWidth;i++)
		{
			float u = float(i) / float(ImageWidth), v = float(j) / float(ImageHeight);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			auto c = shade(r);
			SetPixel(i, j, &c);
		}
}
