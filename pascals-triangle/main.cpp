#include "pascals-triangle.h"

int main()
{
    auto triangle = generate_triangle(15);    
    check_triangle_properties(triangle); 
    show_triangle(std::cout, triangle);
}
