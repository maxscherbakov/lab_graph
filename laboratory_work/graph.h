#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Point {
    Point(int num_) {
        number = num_;
    }
    int number;
    int x = 0;
    int y = 0;
    std:: vector <int> relation;
    int count_rel;
};


class Graph {
    std::vector <Point> points;
    public:
        void add_relation(int a1, int a2) {}
};


#endif // GRAPH_H