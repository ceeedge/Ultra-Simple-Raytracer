#include "include/color.hpp"
#include "include/ray.hpp"
#include "include/Vec3.hpp"

#include <iostream>

double hitSphere(const Point3& center, double radius, const Ray& r)
{
    Vec3 oc{r.origin() - center};
    auto a{r.direction().length_squared()};
    auto half_b{dot(oc,r.direction())};
    auto c{oc.length_squared() - radius*radius};
    auto discriminant{half_b*half_b - a*c};
    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return (-half_b - sqrt(discriminant)) / a;
    }
}

Color ray_color(const Ray& r)
{
    auto t{hitSphere(Point3{0, 0, -1}, 0.5, r)};
    if (t > 0.0)
    {
        Vec3 N = unit_vector(r.at(t) - Vec3{0,0,-1});
        return 0.5 * Color{N.x()+1, N.y()+1, N.z()+1};
    }

    Vec3 unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - t) * Color{1.0, 1.0, 1.0} + 
        t * Color{0.5, 0.7, 1.0}; 
}

int main() 
{
    // Image
    constexpr auto aspectRatio{16.0/9.0};
    constexpr auto imageWidth{400};
    constexpr auto imageHeight{static_cast<int>(imageWidth/aspectRatio)};

    // Camera
    constexpr auto viewportHeight{2.0};
    constexpr auto viewportWidth{aspectRatio * viewportHeight};
    constexpr auto focalLength{1.0};

    auto origin{Point3{0, 0, 0}};
    auto horizontal{Vec3{viewportWidth, 0, 0}};
    auto vertical{Vec3{0, viewportHeight, 0}};
    auto lowerLeftCorner{origin - horizontal/2 - vertical /2 
        - Vec3{0, 0, focalLength}};

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight-1; j >= 0; --j) 
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) 
        {
            auto u{ static_cast<double>(i) / (imageWidth-1) };
            auto v{ static_cast<double>(j) / (imageHeight-1) };
            Ray r{ origin, lowerLeftCorner + u*horizontal + v*vertical - origin };
            Color pixelColor{ ray_color(r) };
            write_color(std::cout, pixelColor);
        }
    }

    std::cerr << "\nDone.\n";

}