#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y, z;
};

void translate(Point& p, double dx, double dy, double dz) {
    p.x += dx;
    p.y += dy;
    p.z += dz;
}

int main() {
    Point p = { 1, 2, 3 };
    double dx = 2, dy = -1, dz = 3;
    translate(p, dx, dy, dz);
    cout << "Translated Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
    return 0;
}