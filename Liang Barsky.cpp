#include <iostream>
#include <graphics.h>
using namespace std;

void liangBarskyLineClip(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax)
{
  double t1 = 0, t2 = 1;

  double dx = x2 - x1;
  double dy = y2 - y1;

  double p[4] = {-dx, dx, -dy, dy};
  double q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

  for (int i = 0; i < 4; i++)
  {
    if (p[i] == 0)
    {
      if (q[i] < 0)
      {
        cout << "Line is parallel to clipping window and outside.\n";
        return;
      }
    }
    else
    {
      double t = q[i] / p[i];
      if (p[i] < 0 && t > t1)
        t1 = t;
      else if (p[i] > 0 && t < t2)
        t2 = t;
    }
  }

  setcolor(GREEN);

  if (t1 < t2)
  {
    double x_new1 = x1 + t1 * dx;
    double y_new1 = y1 + t1 * dy;
    double x_new2 = x1 + t2 * dx;
    double y_new2 = y1 + t2 * dy;

    line(x_new1, y_new1, x_new2, y_new2);
  }
  else
  {
    cout << "Line is completely outside the clipping window.\n";
    setcolor(RED);
  }
}

void clipPolygon(double vertices[], int n, double xmin, double ymin, double xmax, double ymax)
{
  for (int i = 0; i < 2 * n; i += 2)
  {
    int next = (i + 2) % (2 * n); // Closing the polygon

    liangBarskyLineClip(vertices[i], vertices[i + 1], vertices[next], vertices[next + 1], xmin, ymin, xmax, ymax);
  }
}

int main()
{
  double xmin = 50, ymin = 50, xmax = 300, ymax = 200;

  // Polygon vertices (Assuming a convex polygon)
  double vertices[12] = {150, 150, 200, 100, 250, 150, 250, 200, 200, 250, 150, 200};

  // Initialize graphics mode
  initwindow(400, 300, "Liang-Barsky Polygon Clipping Algorithm");

  // Draw the clipping window
  rectangle(xmin, ymin, xmax, ymax);

  // Convert double array to int array for drawpoly
  int verticesInt[12];
  for (int i = 0; i < 12; i++)
    verticesInt[i] = static_cast<int>(vertices[i]);

  // Draw the original polygon
  drawpoly(6, verticesInt);

  // Clip the polygon against the window
  clipPolygon(vertices, 6, xmin, ymin, xmax, ymax);

  delay(50000);
  // closegraph();

  return 0;
}