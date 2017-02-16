#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void oct12(int x0, int y0, int x1, int y1, screen s, color c) {
    int A, B, d;
    A = 2*(y1 - y0);
    B = -2*(x1 - x0);
    if ( (x1 - x0) > (y1 - y0) ) {
        d = A - x1 + x0;
        while (x0 < x1) {
            plot(s, c, x0, y0);
            if (d > 0) {
                y0++;
                d+=B;
            }
            x0++;
            d+=A;
        }
    }
    else {
        d = y1 - y0 + B;
        while (y0 < y1) { 
            plot(s, c, x0, y0);
            if (d < 0) {
                x0++;
                d+=A;
            }
            y0++;
            d+=B;
        }
    }
    plot(s, c, x0, y0);
}

void oct78(int x0, int y0, int x1, int y1, screen s, color c) {
    int A, B, d;
    A = 2*(y1 - y0);
    B = -2*(x1 - x0);
    if ( (x1 - x0) > (y0 - y1) ) {
        d = y1 - y0 - B;
        while (y0 > y1) {
            plot(s, c, x0, y0);
            if (d > 0) {
                x0++;
                d+=A;
            }
            y0--;
            d-=B;
        }
    }
    else {
        d = A + x1 - x0;
        while (x0 > x1) {
            plot(s, c, x0, y0);
            if (d < 0) {
                y0--;
                d-=B;
            }
            x0++;
            d+=A;
        }
    }
    plot(s, c, x0, y0);
}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    if (x1 < x0) {
        if (y0 < y1) oct12(x1, y1, x0, y0, s, c);
        else oct78(x1, y1, x0, y0, s, c);
    }
    else if (y0 < y1) oct12(x0, y0, x1, y1, s, c);
    else oct78(x0, y0, x1, y1, s, c);
}