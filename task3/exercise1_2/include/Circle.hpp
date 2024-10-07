#ifndef CIRCLE_HPP
#define CIRCLE_HPP

const double pi = 3.141592;

class Circle {
    public:
        Circle(double radius_);
        double get_area() const;
        double get_circumference() const;
    private:
        double radius;
};

#endif