#ifndef _BITMAPFILEHEADER_H_
#define _BITMAPFILEHEADER_H_

#include<cstdint>

/*位图文件头*/
#pragma pack(2)  //2字对齐
struct BitmapFileHeader
{
    char header[2]={'B','M'}; //位图文件类型
    int32_t fileSize;   //位图文件大小
    int32_t reserve={0};    //文图文件保留字
    int32_t dataOffest; //位图数据的偏移量
};

#endif