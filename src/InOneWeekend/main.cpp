#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

// return true when ray hit intersect with the sphere
double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminat = half_b * half_b -  a * c;
    if (discriminat < 0) {
        return -1.0;
    }
    else {
        // return smaller t
        return (-half_b - sqrt(discriminat)) / a;
    }
}

// display the color of ray that saw by camera
color ray_color(const ray& r) {
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        // For a sphere, the outward normal is the direction of the hit point minus the center. (Easy to calculate!)
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto facal_length = 1.0; // distance between the projection plane and the projection point

    auto origin = point3(0, 0, 0); // position of camera center or "eye"
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, facal_length);


    // Render

    std::cout << "P3\n" << image_width << ' '
            << image_height <<"\n255\n";
    
    for (int j = image_height-1; j >=0; --j)    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i)
        {
            // caculate the color:

            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }


    std::cerr << "\nDone.\n";
}