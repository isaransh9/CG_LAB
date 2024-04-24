#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int p = 1 - radius;

    // Initialize graphics
    initwindow(800, 600, "Midpoint Circle Drawing");

    // Plot the initial point
    putpixel(xc + x, yc - y, WHITE);

    // Draw the circle using Midpoint Circle Drawing Algorithm
    while (x <= y) {
        x++;

        // Mid-point is inside or on the perimeter of the circle
        if (p <= 0)
            p = p + 2 * x + 1;
        else {
            y--;
            p = p + 2 * (x - y) + 1;
        }

        // All the perimeter points have already been printed
        if (x > y)
            break;

        // If the generated point is on the line x = y, then
        // the perimeter points have already been printed
        if (x != y) {
            putpixel(xc + x, yc - y, WHITE);
            putpixel(xc - x, yc - y, WHITE);
            putpixel(xc + x, yc + y, WHITE);
            putpixel(xc - x, yc + y, WHITE);
        }

        // If the generated point is not on the line x = y
        if (x != y) {
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
        }
    }

    delay(5000);  // Wait for 5 seconds before closing the window
    closegraph(); // Close the graphics window
}

int main() {
    int xc, yc, radius;

    // Input center and radius of the circle
    std::cout << "Enter the center (x, y) coordinates of the circle: ";
    std::cin >> xc >> yc;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Call the drawCircle function
    drawCircle(xc, yc, radius);

    return 0;
}
