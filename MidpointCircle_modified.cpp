#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int radius)
{
  int x = 0, y = radius;
  int p = 1 - radius;

  // Initialize graphics
  initwindow(800, 600, "Midpoint Circle Drawing");

  // Plot the initial point
  cout << "(" << xc + x << "," << yc - y << ")" << endl;
  putpixel(xc + x, yc - y, WHITE);

  // Draw the circle using Midpoint Circle Drawing Algorithm
  while (x <= y)
  {
    x++;

    // Mid-point is inside or on the perimeter of the circle
    if (p <= 0)
      p = p + 2 * x + 3;
    else
    {
      y--;
      p = p + 2 * (x - y) + 5;
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
  int radius = 200;

  // Call the drawCircle function
  drawCircle(xc, yc, radius);

  return 0;
}
