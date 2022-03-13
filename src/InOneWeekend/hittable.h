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
	// front_face = true when the ray is outside the object
	bool front_face;

	// calculate the solution of front_face
	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : (-outward_normal);
	}
};

class hittable {
public:
	// calculate the hit record. 
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif