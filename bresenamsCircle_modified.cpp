#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int radius)
{
  int x = 0, y = radius;
  int d = 3 - 2 * radius;

  // Initialize graphics
  initwindow(800, 600, "Bresenham's Circle Drawing");

  // Plot the initial point
  putpixel(xc + x, yc - y, WHITE);

  // Draw the circle using Bresenham's Circle Drawing Algorithm
  while (x <= y)
  {
    x++;

    // Mid-point is inside or on the perimeter of the circle
    if (d <= 0)
      d = d + 4 * x + 6;
    else
    {
      y--;
      d = d + 4 * (x - y) + 10;
    }

    // Plot all eight symmetric points
    cout << "(" << xc + x << "," << yc - y << ")" << endl;
    putpixel(xc + x, yc - y, WHITE);
    cout << "(" << xc - x << "," << yc - y << ")" << endl;
    putpixel(xc - x, yc - y, WHITE);
    cout << "(" << xc + x << "," << yc + y << ")" << endl;
    putpixel(xc + x, yc + y, WHITE);
    cout << "(" << xc - x << "," << yc + y << ")" << endl;
    putpixel(xc - x, yc + y, WHITE);
    cout << "(" << xc + y << "," << yc - x << ")" << endl;
    putpixel(xc + y, yc - x, WHITE);
    cout << "(" << xc - y << "," << yc - x << ")" << endl;
    putpixel(xc - y, yc - x, WHITE);
    cout << "(" << xc + y << "," << yc + x << ")" << endl;
    putpixel(xc + y, yc + x, WHITE);
    cout << "(" << xc - y << "," << yc + x << ")" << endl;
    putpixel(xc - y, yc + x, WHITE);
  }

  delay(15000);  // Wait for 15 seconds before closing the window
  closegraph(); // Close the graphics window
}

int main()
{
  int gd = DETECT, gm;
  // Initialize graphics function
  char path[] = "";
  initgraph(&gd, &gm, path);

  // Shift the center to the center of the window
  int xc = getmaxx() / 2;
  int yc = getmaxy() / 2;
  int radius = 230;

  // Call the drawCircle function
  drawCircle(xc, yc, radius);

  return 0;
}
