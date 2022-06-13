#ifndef _BITMAPINFOHEADER_H_
#define _BITMAPINFOHEADER_H_

#include<cstdint>
namespace czh
{
    //位图信息头
    struct BitmapInfoHeader
    {
        int32_t headSize=40;
        int32_t width;
        int32_t height;
        int16_t planes=1;
        int16_t bitPerPixel=24;
        int32_t compression=0; //0：不压缩，1：8位压缩 2：4位压缩
        int32_t dataSize=0;
        int32_t horizontalResolution=2400;
        int32_t verticalResolution=2400;
        int32_t colors=0;    
        int32_t importantColors=0;        
    };

}
#endif