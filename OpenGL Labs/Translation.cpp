#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x;
    double y;
};

void scale(Point& point, double Sx, double Sy) {
    point.x *= Sx;
    point.y *= Sy;
}

void rotate(Point& point, double angle, double pivot_x, double pivot_y) {
    double radian = angle * M_PI / 180.0;
    double cosAngle = cos(radian);
    double sinAngle = sin(radian);

    double translated_x = point.x - pivot_x;
    double translated_y = point.y - pivot_y;

    point.x = translated_x * cosAngle - translated_y * sinAngle + pivot_x;
    point.y = translated_x * sinAngle + translated_y * cosAngle + pivot_y;
}

void translate(Point& point, double Tx, double Ty) {
    point.x += Tx;
    point.y += Ty;
}

int main() {
    vector<Point> triangle = { {3, 5}, {4, 8}, {9, 8} };
    double Sx = 5, Sy = 7;
    double pivot_x = 10, pivot_y = 7;
    double rotation_angle = -60;
    double Tx = 5, Ty = 6;
    for (auto& point : triangle) {
        scale(point, Sx, Sy);
        rotate(point, rotation_angle, pivot_x, pivot_y);
        translate(point, Tx, Ty);
    }

    cout << "Coordinates of the Translated triangle:" << endl;
    int point_index = 1;
    for (const auto& point : triangle) {
        cout << "Point " << point_index++ << ": (" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}