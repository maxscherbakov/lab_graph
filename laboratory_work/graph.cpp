#include "graph.h"
#include <iostream>
#include <algorithm>

void Point::add_relation(int a) {
    count_rel += 1;
    relations.push_back(a);
}

void Point::print() {
    std::cout << "num: " << number << '\n';
    for (int i : relations) std::cout << i << ' ';
    std:: cout << '\n';
}


void Graph::relation(int a1, int a2) {
    points[a1-1].add_relation(a2);
    points[a2-1].add_relation(a1);
}

void Graph::create_vertices(int count) {
    for (int i = 1; i <= count; ++i) {
        points.push_back(Point(i));
    }
}

void Graph::print() {
    for (Point i : points) {
        i.print();
    }
}

bool sort_count_relations(Point& left, Point& right) {
    return left.get_count_rel() > right.get_count_rel();
}

void Graph::sort_vertices() {
    std::sort(begin(points), end(points),sort_count_relations);
}