#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
	// hit point coordinate
	point3 p;
	// normal at the hit point
	vec3 normal;
	// t of the ray at the hit point
	double t;
};

class hittable {
public:
	// calculate the hit record. 
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif