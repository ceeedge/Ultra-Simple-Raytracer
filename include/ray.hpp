#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"

class Ray final
{
public:
    Ray() {}
    Ray(const Point3& origin,const Vec3& direction)
        : orig{origin}, dir{direction} {}
    
    Point3 origin(void) const { return orig; }
    Vec3 direction(void) const { return dir; }

    Point3 at(double t) const 
    {
        return orig + t*dir;
    }

private:
    Point3 orig;
    Vec3 dir;

};





#endif  // RAY_HPP