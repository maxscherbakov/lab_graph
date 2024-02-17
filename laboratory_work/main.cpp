#include <iostream>
#include <fstream>
#include "graph.h"
#include "BMP.h"

int main() {
    Graph graph;

    std:: ifstream inp("test.txt");
    if (inp.is_open()) {
        int V, E;
        int a1, a2;
        inp >> V >> E;
        graph.create_vertices(V);
        for (int i = 0; i < E; ++i) {
            inp >> a1 >> a2;
            graph.relation(a1, a2);
        }

    }
    inp.close();
    
    graph.sort_vertices();
    //graph.print();

    BMP painter;
    painter.write_file("out2.bmp");
    painter.write();
    return 0;
}