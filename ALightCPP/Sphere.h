#pragma once
#include "vec3.h"
#include "ray.h"

bool hit_sphere(const vec3& center,float radius,const ray& r)
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0*dot(oc, r.direction());
	auto c = dot(oc, oc) - radius * radius;
	const auto discriminant = b * b - 4 * a*c;
	return (discriminant > 0);
}
