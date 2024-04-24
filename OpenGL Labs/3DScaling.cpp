#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y, z;
};

void scale(Point& p, double sx, double sy, double sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

int main() {
    Point p = { 1, 2, 3 };
    double sx = 2, sy = 0.5, sz = 3;
    scale(p, sx, sy, sz);
    cout << "Scaled Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    return 0;
}