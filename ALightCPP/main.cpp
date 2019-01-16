
#include <iostream>
#include "GLWindow.h"
#include "Sphere.h"
#include "hitable_list.h"
using namespace std;

hitable *world;	hitable *list[2];
void InitData()
{
	PixelLength = ImageHeight*ImageWidth*4;
	PixelData = new GLbyte[PixelLength];
	col = new vec3[ImageHeight*ImageWidth];
	//InitWindow zero
	for (auto i = 0; i < PixelLength; i++)
		PixelData[i] = static_cast<GLbyte>(int(0));
}
void InitScene()
{

	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	world = new hitable_list(list, 2);

}

int main(int argc, char* argv[])
{
	InitData();
	InitScene();
	InitWindow(argc, argv, GLUT_DOUBLE | GLUT_RGBA, 100, 100, ImageWidth, ImageHeight, "ALight");
	return 0;
}

vec3 shade(const ray& r,hitable *world)
{
	hit_record rec;
	if(world->hit(r,0,99999,rec))
	{
		return  0.5*vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else
	{
		vec3 unit_dir = unit_vector(r.direction());
		auto t = 0.5*(unit_dir.y() + 1);
		return  (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}
void render()
{
	const vec3 lower_left_corner(-2.0, -2.0, -1.0),horizontal(4, 0, 0), vertical(0, 4, 0), origin(0, 0, 0);

	for (auto j=ImageHeight-1;j>=0;j--)
		for (auto i=0;i<ImageWidth;i++)
		{
			float u = float(i) / float(ImageWidth), v = float(j) / float(ImageHeight);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			auto c = shade(r,world);
			SetPixel(i, j, &c);
		}
}
