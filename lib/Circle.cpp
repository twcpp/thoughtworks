#include "Circle.h"

#define PI 3.1415926

Circle::Circle(int r) {
    this->r = r;
}


double Circle::area() {
    return 2 * PI * this->r;
}
