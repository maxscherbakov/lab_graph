#include <iostream>
#include <fstream>
#include "graph.h"

int main() {
    Graph graph;

    std:: ifstream inp("test.txt");
    if (inp.is_open()) {
        int V, E;
        int a1, a2;
        inp >> V >> E;
        for (int i = 0; i < E; ++i) {
            inp >> a1 >> a2;
            graph.add_relation(a1, a2);
        }
    }
    inp.close();
    return 0;
}