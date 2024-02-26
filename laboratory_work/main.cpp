#include <iostream>
#include <fstream>
#include "Painter.h"

int main() {
    Painter painter;

    std:: ifstream inp("test.txt");
    if (inp.is_open()) {
        int V, E;
        int a1, a2;
        inp >> V >> E;
        painter.graph->create_vertices(V);
        for (int i = 0; i < E; ++i) {
            inp >> a1 >> a2;
            painter.graph->relation(a1, a2);
        }

    }
    inp.close();
    painter.graph->sort_vertices();

    //painter.graph->print();

    //painter.draw_graph();
    //painter.bmp->write();
    return 0;
}