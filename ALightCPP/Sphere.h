#pragma once
#include "vec3.h"
#include "ray.h"
#include "Hitable.h"

class sphere :public hitable
{
public:
	sphere() {}
	sphere(vec3 cent, float r) :center(cent), radius(r) {};
	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec)const;
	vec3 center;
	float radius;
};

inline bool sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec) const
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b =dot(oc, r.direction());
	auto c = dot(oc, oc) - radius * radius;
	const auto discriminant = b * b - a*c;

	if (discriminant > 0)
	{
		float temp = (-b - sqrt(b*b - a * c)) / a;
		if (temp<tmax&&temp>tmin)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(b*b - a * c)) / a;
		if (temp<tmax&&temp>tmin)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}
