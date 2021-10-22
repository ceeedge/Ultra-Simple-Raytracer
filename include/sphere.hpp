#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hittable.hpp"
#include "Vec3.hpp"

class Sphere : public Hittable
{
public:
    Sphere() {}
    Sphere(Point3 cen, double r) : center{cen}, radius{r} {}

    virtual bool hit(const Ray &r, double tMin, double tMax, HitRecord &rec) const override
    {
        Vec3 oc{r.origin() - center};
        auto a{r.direction().length_squared()};
        auto half_b{dot(oc, r.direction())};
        auto c{oc.length_squared() - radius * radius};

        auto discriminant{half_b*half_b - a * c};
        if(discriminant < 0)
            return false;
        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
        auto root = (-half_b - sqrtd) / a;
        if(root < tMin || tMax < root)
        {
            root = (-half_b + sqrtd) / a;
            if(root < tMin || tMax < root)
                return false;
        }
    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;

    return true;
    };

private:
    Point3 center;
    double radius;

};







#endif // SPHERE_HPP