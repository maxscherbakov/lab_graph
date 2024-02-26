#ifndef PAINTER_H
#define PAINTER_H
#include "BMP.h"
#include "graph.h"

struct Painter {
    BMP * bmp = new BMP;
    Graph * graph = new Graph;

    void settings_image();
    void draw_vertex(int, int);
    void draw_pixel(int, int);
    void draw_graph();
};


#endif // PAINTER_H