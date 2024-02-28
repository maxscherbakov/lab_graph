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



void Graph::del_vertices(std::vector <Point> & vec, Point & ver, int k, int &mark) {
    std::vector <int> next = {};
    std::vector <int> last = {ver.number};
    int count = 0;
    while (count < k) {
        for (int i : last) {
            for (int j : vec[i-1].relations) {
                if (vec[j-1].mark != mark) {
                    vec[j-1].mark = mark;
                    vec[j-1].number = 0;
                    next.push_back(j);
                }
            }
        }
        last = next;
        next = {};
        ++count;
    }
}

void Graph::support_func(std::vector<Point> & V, std::vector<Point> & V_, int & mark, int & k,
                  std::vector <int> & num_vec) {
    for (int i : num_vec) {
        if (V[i].number != 0) {
            V_.push_back(V[i]);
            V[i].mark = mark;
            del_vertices(V, V[i], std::pow(2, k), mark);
            ++mark;
            mark %= 100;
        }
    }

}

void Graph::sort_vertices() {
    std::vector <Point> V = points;
    std::vector <std::vector <Point>> sort_vec;
    std::vector <Point> V_;
    std::vector <int> num_vec;
    sort_vec.push_back(V);
    int k = 1;
    int mark = 1;
    while (k != -1) {
        V_ = {};
        num_vec = {};
        for (Point i : sort_vec[sort_vec.size()-1]) num_vec.push_back(i.number - 1);

        support_func(V, V_, mark, k, num_vec);
        sort_vec.push_back(V_);
        ++k;
        if (V_.size() <= 3) k = -1;
    }
    k = sort_vec.size() - 1;
    if (V_.size() < 3) {
        num_vec = {};
        for (Point i : sort_vec[sort_vec.size() - 2]) {
            num_vec.push_back(i.number - 1);
        }

        while ( std::next_permutation(num_vec.begin(),num_vec.end()) ) {
            V_ = {};
            for (int i : num_vec) {
                V[i].number = i + 1;
            }
            support_func(V, V_, mark, k, num_vec);
            if (V_.size() == 3) {
                sort_vec[sort_vec.size()-1] = V_;
                break;
            }

        }
    }

    for (int i = 0; i < sort_vec.size(); ++i) {
        std:: cout << i << '\n';
        for (int j = 0; j < sort_vec[i].size(); ++j) {
            std::cout << sort_vec[i][j].number << ' ';
        }
        std::cout << '\n';
    }
}