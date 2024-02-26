#include "Painter.h"
#include <iostream>


void Painter::settings_image() {
    graph->sort_vertices();
    bmp->bmp_info_header.width = graph->points.size() * 16;
    bmp->bmp_info_header.height = graph->points[0].get_count_rel() * 16;

    bmp->data.resize(bmp->bmp_info_header.height * bmp->bmp_info_header.width * 3);
    std::fill(bmp->data.begin(), bmp->data.end(), 255);
    bmp->bmp_info_header.size_image = bmp->data.size();


    bmp->file_header.file_size = bmp->bmp_info_header.size_image  + bmp->file_header.offset_data;
}

void Painter::draw_pixel(int x, int y) {
    for (int i = 0; i < 3; ++i) bmp->data[(x + y * bmp->bmp_info_header.width)*3 + i] = 0;
}

void Painter::draw_vertex(int x, int y) {
    draw_pixel(x+1, y+1);
    draw_pixel(x+2, y);
    draw_pixel(x+3, y);
    draw_pixel(x+4, y+1);
    draw_pixel(x+5, y+2);
    draw_pixel(x+5, y+3);
    draw_pixel(x+4, y+4);
    draw_pixel(x+3, y+5);
    draw_pixel(x+2, y+5);
    draw_pixel(x+1, y+4);
    draw_pixel(x, y+3);
    draw_pixel(x, y+2);
}

void Painter::draw_graph() {
    settings_image();
    draw_vertex(10, 10);
    bmp->write_file("out2.bmp");
}