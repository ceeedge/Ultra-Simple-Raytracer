#include "include/color.hpp"
#include "include/Vec3.hpp"

#include <iostream>


int main() 
{
    // Image
    static constexpr uint32_t imageWidth{256};
    static constexpr uint32_t imageHeight{256};

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            color pixel_color(double(i)/(imageWidth-1), double(j)/(imageHeight-1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";

}