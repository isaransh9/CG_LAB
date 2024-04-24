#include <graphics.h>
#include <iostream>
using namespace std;

// Define region codes
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Define viewport dimensions
#define X_MIN 100
#define X_MAX 400
#define Y_MIN 100
#define Y_MAX 300

// Function to compute region code for a point (x, y)
int compute_code(int x, int y)
{
  int code = INSIDE;
  if (x < X_MIN)
    code |= LEFT;
  else if (x > X_MAX)
    code |= RIGHT;
  if (y < Y_MIN)
    code |= BOTTOM;
  else if (y > Y_MAX)
    code |= TOP;
  return code;
}

// Function to clip a line segment (x1, y1)-(x2, y2) against a viewport
void cohen_sutherland(int x1, int y1, int x2, int y2)
{
  int code1 = compute_code(x1, y1);
  int code2 = compute_code(x2, y2);
  bool accept = false;

  while (true)
  {
    // Line is completely inside Case
    if (code1 == 0 && code2 == 0)
    {
      accept = true;
      break;
    }
    // Line is completely outside Case
    else if (code1 & code2)
    {
      break;
    }
    // Partial Case
    else
    {
      int x, y;
      int code_out = code1 ? code1 : code2;

      if (code_out & TOP)
      {
        x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
        y = Y_MAX;
      }
      else if (code_out & BOTTOM)
      {
        x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
        y = Y_MIN;
      }
      else if (code_out & RIGHT)
      {
        y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
        x = X_MAX;
      }
      else if (code_out & LEFT)
      {
        y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
        x = X_MIN;
      }

      if (code_out == code1)
      {
        x1 = x;
        y1 = y;
        code1 = compute_code(x1, y1);
      }
      else
      {
        x2 = x;
        y2 = y;
        code2 = compute_code(x2, y2);
      }
    }
  }

  if (accept)
  {
    setcolor(RED);
    line(x1, y1, x2, y2);
  }
  else
  {
    cout << "Line segment is outside the viewport and rejected." << endl;
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  // Draw viewport
  rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

  // Original line segment
  int x1 = 50, y1 = 50, x2 = 500, y2 = 250;
  setcolor(WHITE);
  line(x1, y1, x2, y2);

  // Clip the line segment
  cohen_sutherland(x1, y1, x2, y2);

  delay(5000);
  closegraph();
  return 0;
}