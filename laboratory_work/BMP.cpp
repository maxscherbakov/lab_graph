#include "BMP.h"
#include <fstream>
#include <iostream>

void BMP::write_file(const char *fname) {
    std:: ofstream of{fname, std:: ios_base::binary};
    if (of.is_open()) {
        of.write((const char*)&file_header, sizeof(file_header));
        of.write((const char*)&bmp_info_header, sizeof(bmp_info_header));
        of.write((const char*)data.data(), data.size());
    }
    of.close();
}


void BMP::write() {
    std::cout<<
    "file_type" << ' ' << file_header.file_type << '\n' <<       
    "file_size" << ' ' << file_header.file_size << '\n' <<            
    "reserved1" << ' ' << file_header.reserved1 << '\n' <<            
    "reserved2" << ' ' << file_header.reserved2 << '\n' <<              
    "offset_data" << ' ' << file_header.offset_data << '\n' <<
    "size" << ' ' << bmp_info_header.size << '\n' <<        
    "width" << ' ' << bmp_info_header.width << '\n' <<                
    "height" << ' ' << bmp_info_header.height << '\n' <<            
    "planes" << ' ' << bmp_info_header.planes << '\n' <<                  
    "bit_count" << ' ' << bmp_info_header.bit_count << '\n' <<
    "compression" << ' ' << bmp_info_header.compression << '\n' << 
    "size_image" << ' ' << bmp_info_header.size_image << '\n' <<
    "x_pixels_per_meter" << ' ' << bmp_info_header.x_pixels_per_meter << '\n' <<
    "y_pixels_per_meter" << ' ' << bmp_info_header.y_pixels_per_meter << '\n' <<
    "colors_used" << ' ' << bmp_info_header.colors_used << '\n' <<             
    "colors_important" << ' ' << bmp_info_header.colors_important << '\n';
}
