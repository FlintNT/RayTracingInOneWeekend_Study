#ifndef RAY_H
#define RAY_H

#include "vec3.h"

// 3-dimension ray
class ray {
public:
	ray() {}
	ray(const point3& origin, const vec3& direction)
		: orig(origin), dir(direction)
	{}

	point3 origin() const { return orig; }
	// direction of ray
	vec3 direction() const { return dir; }

	// 11
	point3 at(double t) const;

private:
	point3 orig;
	vec3 dir;
};

point3 ray::at(double t) const {
	return orig + t * dir;
}

#endif // !RAY_H
