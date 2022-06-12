#ifndef _BITMAPFILEHEADER_H_
#define _BITMAPFILEHEADER_H_

#include<cstdint>

/*位图文件头*/
struct BitmapFileHeader
{
    char header[2]={'B','M'};
    int32_t fileSize;
    int32_t reserve={0};
    int32_t dataOffest;
};

#endif