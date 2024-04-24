#include <iostream>
#include <graphics.h>
using namespace std;

void drawSymmetricPoints(int cx, int cy, int x, int y)
{
  // Draw symmetric points
  putpixel(cx + x, cy + y, WHITE); // point in region 1
  putpixel(cx - x, cy + y, WHITE); // point in region 2
  putpixel(cx + x, cy - y, WHITE); // point in region 3
  putpixel(cx - x, cy - y, WHITE); // point in region 4
  delay(10);
}

void drawEllipse(int cx, int cy, int rx, int ry)
{
  initwindow(1000, 900, "Mid-point Ellipse Drawing");
  int x = 0;
  int y = ry;
  int rxSquare = rx * rx;
  int rySquare = ry * ry;
  int rx2 = 2 * rxSquare;
  int ry2 = 2 * rySquare;
  int p;

  // Region 1
  int dx = 0;
  int dy = rx2 * y;

  // Draw symmetric points in region 1
  drawSymmetricPoints(cx, cy, x, y);

  p = rySquare - (rxSquare * ry) + (0.25 * rxSquare);

  while (dx < dy)
  {
    x++;
    dx += ry2;
    if (p < 0)
      p += rySquare + dx; // p' = p + dx + rysquare
    else
    {
      y--;
      dy -= rx2;
      p += rySquare + dx - dy;
    }
    drawSymmetricPoints(cx, cy, x, y);
  }

  // Region 2
  p = rySquare * (x + 0.5) * (x + 0.5) + rxSquare * (y - 1) * (y - 1) - rxSquare * rySquare;

  while (y > 0)
  {
    y--;
    dy -= rx2;
    if (p > 0)
      p += rxSquare - dy;
    else
    {
      x++;
      dx += ry2;
      p += rxSquare - dy + dx;
    }
    drawSymmetricPoints(cx, cy, x, y);
  } // Wait for 15 seconds before closing the window
  closegraph();
}

int main()
{
  // Example usage
  int gd = DETECT, gm;
  // Initialize graphics function
  char path[] = "";
  initgraph(&gd, &gm, path);

  drawEllipse(370, 370, 300, 250); // Draw an ellipse with center at (50, 50), rx = 30, ry = 20
  return 0;
}