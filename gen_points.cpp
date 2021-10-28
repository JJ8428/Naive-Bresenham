#include<iostream>
#include <math.h>
using namespace std;

// These the equivalent of the naive Bersenham's Line Algorithm
void naive_bresenham(int x1, int y1, float theta, float dist) {
    int x2 = round((float) x1 + (dist * cos(theta)));
    int y2 = round((float) y1 + (dist * sin(theta)));
    cout << "(x1, y1) = (" << x1 << "," << y1 << ")\n";
    cout << "(x2, y2) = (" << x2 << "," << y2 << ")\n";
    float delta_x = abs(x1 - x2);
    float delta_y = abs(y1 - y2);
    int bigX = max(x1, x2);
    int smallX = min(x1, x2);
    int bigY = max(y1, y2);
    int smallY = min(y1, y2);
    // Scales for both dx or dy
    if (delta_x >= delta_y) {
        float m = (float) (y1 - y2)/ (float) (x1 - x2);
        if (isinf(m) || isinf(-1 * m)) {
            for (float tx = smallX; tx <= bigX; tx++) {
                cout << "(" << tx << "," << y2 << ")\n";
            }
        }
        else {
            float c = (float) y1 - (m * (float) x1);
            for (float tx = smallX; tx <= bigX; tx++) {
                float ty = round(m*tx + c);
                cout << "(" << tx << "," << ty << ")\n";
            }
        }
    }
    else { // (delta_x < delta_y)
        float m = (float) (x1 - x2)/ (float) (y1 - y2);
        if (isinf(m) || isinf(-1 * m)) {
            for (float ty = smallY; ty <= bigY; ty++) {
                cout << "(" << x2 << "," << ty << ")\n";
            }
        }
        else {
            float c = (float) x1 - (m * (float) y1);
            for (float ty = smallY; ty <= bigY; ty++) {
                float tx = round(m*ty + c);
                cout << "(" << tx << "," << ty << ")\n";
            }
        }
    }
}

int main()
{
    naive_bresenham(1, 1, M_PI/2, 10);
}
