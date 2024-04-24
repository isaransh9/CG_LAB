#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y, z;
};

void rotateZ(Point& p, double theta) {
    double newX = p.x * cos(theta) - p.y * sin(theta);
    double newY = p.x * sin(theta) + p.y * cos(theta);
    p.x = newX;
    p.y = newY;
}

int main() {
    Point p = { 1, 2, 3 };
    double theta = M_PI / 4;
    rotateZ(p, theta);
    cout << "Rotated Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
    return 0;
}