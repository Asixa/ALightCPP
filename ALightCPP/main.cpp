
#include <iostream>
#include "GLWindow.h"
#include "Sphere.h"
#include "hitable_list.h"
#include "stdlib.h"
#include "Camera.h"
#include <thread>
using namespace std;

hitable *world;	hitable *list[2]; camera cam;
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
			vec3 c(0, 0, 0);
			for (int s=0;s<SPP;s++)
			{
				float u = float(i + drand48()) / float(ImageWidth);
				float v = float(j + drand48()) / float(ImageHeight);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2);
				c += shade(r, world);
			}
			c /= SPP;
			SetPixel(i, j, &c);
		}
}


int main(int argc, char* argv[])
{
	InitData();
	InitScene();
	thread t(render);

	InitWindow(argc, argv, GLUT_DOUBLE | GLUT_RGBA, 100, 100, ImageWidth, ImageHeight, "ALight");
	t.join();
	return 0;
}

