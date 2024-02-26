#include "graph.h"
#include <iostream>
#include <algorithm>
#include <cmath>

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
    std::cout << points.size() << '\n' <<
    points[0].get_count_rel() << '\n';
    for (Point i : points) {
        i.print();
    }
}



void Graph::del_vertices(std::vector <Point> & vec, Point & ver, int i, int k, int num) {
    if (i <= k) {
        i += 1;
        for (int j : ver.relations) {
            vec[j-1].number = 0;
            del_vertices(vec, vec[j-1], i, k, num);
        }
    }
}


void Graph::sort_vertices() {
    std::vector <Point> V = points;
    std::vector <std::vector <Point>> sort_vec;
    std::vector <Point> V_;
    sort_vec.push_back(V);
    int k = 1;
    while (k != -1) {
        V_ = {};
        for (int i = 0; i < V.size(); ++i) {
            if (V[i].number != 0) {
                V_.push_back(V[i]);
                del_vertices(V, V[i], 1, std::pow(2, k), i);
            }
        }
        sort_vec.push_back(V_);
        ++k;
        if (V_.empty()) k = -1;
    }
    for (int i = 0; i < sort_vec.size(); ++i) {
        std:: cout << i << '\n';
        for (int j = 0; j < sort_vec[i].size(); ++j) {
            std::cout << sort_vec[i][j].number << ' ';
        }
        std::cout << '\n';

    }
}


void Graph::assemble_graph() {
    sort_vertices();
    int now_x = 2;
    int now_y = 2;
    for (int cur = 0; cur < points.size(); ++cur) {
        points[cur].x = now_x;
        points[cur].y = now_y;
        now_x += 10;
        for (int i : points[cur].relations) {
            if (points[i-1].x == 0) {
                points[i-1].x = now_x;
                points[i-1].y = now_y;
            }
            now_y += 10;
        }
    }

}