#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

struct Point {
    int number;
    int count_rel {0};
    std:: vector <int> relations;
    int x {0};
    int y {0};
    int mark {-1};
    Point(int num_) {
        number = num_;
    }
    void add_relation(int);
    void print();
    int get_count_rel() { return count_rel; }
};


struct Graph {
    std::vector <Point> points;
    void relation(int, int);
    void create_vertices(int);
    void print();
    void sort_vertices();
    void support_func(std::vector<Point> &, std::vector<Point> &, int &, int &, std::vector <int> &); 
    void del_vertices(std::vector <Point> &, Point &, int, int &);
};


#endif // GRAPH_H