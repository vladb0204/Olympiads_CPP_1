#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:
    double x, y;

    Vector(double x, double y) : x(x), y(y) {};

public:
    Vector operator+(Vector v) {
        return Vector(x + v.x, y + v.y);
    }

    Vector operator-(Vector v) {
        return Vector(x - v.x, y - v.y);
    }

    Vector operator*(double c) {
        return Vector(x * c, y * c);
    }

public:
    double length() {
        return sqrt(x * x + y * y);
    }

    double phi() {
        return atan2(y, x);
    }

};

class VectorFormulas {
public:
    double angle(Vector a, Vector b) {
        return abs(atan2(b.x, b.y) - atan2(a.x, a.y));
    }

    double scalar(Vector a, Vector b) {
        return a.x * b.x + a.y * b.y;
    }

};


class Point {
public:
    double x, y;
    Point(double x, double y): x(x), y(y){};

};

class Polygon {
public:
    double triangleArea(Point a, Point b, Point c) {
//      Можно почитать через детерминант
        return abs(a.x * b.y + b.x * c.y + c.x * a.y
                    - b.x * a.y - c.x * b.y - a.x * c.y) / 2;
    }

    double perimeterTriangle(Point a, Point b, Point c) {
        double line1 = line(a, b);
        double line2 = line(b, c);
        double line3 = line(a, c);

        return line1 + line2 + line3;
    }

public:
    double rectangleArea(Point a, Point b, Point c, Point d) {
//      Можно почитать через детерминант
        return abs(a.x * b.y + b.x * c.y + c.x * d.y + d.x * a.y
                    - b.x * a.y - c.x * b.y - d.x * c.y - a.x * d.y) / 2;
    }

public:
    double PolygonArea(int points) {
        double x, y; cin >> x >> y;
        double x1 = x, y1 = y;
        double x2 = 0, y2 = 0;
        double area = 0;

        for (int point = 0; point < points - 1; point++) {
            double x2, y2; cin >> x2 >> y2;
            area = area + (x1 * y2 - x2 * y1);
            x1 = x2; y1 = y2;
        }

        area = area + (x1 * y - x * y1);
        return abs(area) / 2;
    }

private:
    double line(Point a, Point b) {
        return sqrt(length(a.x, b.x) + length(a.y, b.y));
    }

    double length(double a, double b) {
        return (a - b) * (a - b);
    }
};


int main() {
    Polygon polygon;
    VectorFormulas formulas;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Vector a = Vector(x1, y1);
    Vector b = Vector(x2, y2);

    printf("%.12f", abs(a.phi() - b.phi()));
}