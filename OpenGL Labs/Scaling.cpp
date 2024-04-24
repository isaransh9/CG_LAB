#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x;
    double y;
};

Point calculateCenter(const vector<Point>& square) {
    Point center;
    center.x = (square[0].x + square[1].x + square[2].x + square[3].x) / 4.0;
    center.y = (square[0].y + square[1].y + square[2].y + square[3].y) / 4.0;
    return center;
}

vector<vector<double>> constructScalingMatrix(double Sx, double Sy) {
    vector<vector<double>> matrix = {
        {Sx, 0, 0},
        {0, Sy, 0},
        {0, 0, 1}
    };
    return matrix;
}

Point applyTransformation(const vector<vector<double>>& matrix, const Point& point) {
    Point result;
    result.x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2];
    result.y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2];
    return result;
}

int main() {
    vector<Point> square = { {1, 1}, {3, 1}, {3, 3}, {1, 3} };
    Point center = calculateCenter(square);
    double Sx = 0.5, Sy = 0.5;
    vector<vector<double>> scalingMatrix = constructScalingMatrix(Sx, Sy);
    vector<Point> scaledSquare;
    for (const auto& point : square) {
        Point translatedPoint = { point.x - center.x, point.y - center.y };
        Point scaledPoint = applyTransformation(scalingMatrix, translatedPoint);
        scaledPoint.x += center.x;
        scaledPoint.y += center.y;
        scaledSquare.push_back(scaledPoint);
    }
    cout << "Coordinates of the scaled square:" << endl;
    for (int i = 0; i < scaledSquare.size(); ++i) {
        cout << "Point " << i + 1 << ": (" << scaledSquare[i].x << ", " << scaledSquare[i].y << ")" << endl;
    }
    return 0;
}