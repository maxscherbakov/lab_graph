#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Point {
    int number;
    std:: vector <int> relations;
    int count_rel;
    public:
        Point(int num_) {
            number = num_;
        }
        void add_relation(int);
        void print();
        int get_count_rel() { return count_rel; }
};


class Graph {
    std::vector <Point> points;
    public:
        void relation(int, int);
        void create_vertices(int);
        void print();
        void sort_vertices();
};


#endif // GRAPH_H