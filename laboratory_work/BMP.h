#ifndef BMP_H
#define BMP_H
#include <vector>
#include <cstdint>


#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t file_type{0x4D42};       
    uint32_t file_size{ 0 };            
    uint16_t reserved1{0};            
    uint16_t reserved2{0};            
    uint32_t offset_data{54};          
};

 struct BMPInfoHeader {
    uint32_t size{ 40 };             
    int32_t width{ 400 };                  
    int32_t height{ 200 };             
    uint16_t planes{ 1 };                  
    uint16_t bit_count{ 24 };
    uint32_t compression{ 0 }; 
    uint32_t size_image{ 0 };
    int32_t x_pixels_per_meter{ 11811 };
    int32_t y_pixels_per_meter{ 11811 };
    uint32_t colors_used{ 0 };             
    uint32_t colors_important{ 0 };     
};
#pragma pack(pop)

struct BMP {
    BMPFileHeader file_header;
    BMPInfoHeader bmp_info_header;
    std::vector<uint8_t> data;

    void write();
    void write_file(const char *);
};

#endif // BMP_H