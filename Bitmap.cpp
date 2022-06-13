#include<fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
using namespace czh;

namespace czh
{
Bitmap::Bitmap(int width,int height):m_width(width),m_height(height),m_pPixel(new uint8_t[width*height*3]){}

Bitmap::~Bitmap(){}

bool Bitmap::write(std::string filename)
{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    
    fileHeader.fileSize=sizeof(BitmapFileHeader)+sizeof(BitmapInfoHeader)+m_width*m_height*3;
    fileHeader.dataOffest=sizeof(BitmapFileHeader)+sizeof(BitmapInfoHeader);

    infoHeader.width=m_width;
    infoHeader.height=m_height;

    std::fstream file;
    file.open(filename,std::ios::out|std::ios::binary);
    if(!file) return false;

    file.write((char*)&fileHeader,sizeof(fileHeader));
    file.write((char*)&infoHeader,sizeof(infoHeader));
    file.write((char*)m_pPixel.get(),m_width*m_height*3);

    file.close();
    return true;
}

void Bitmap::setPixel(int x,int y,uint8_t red,uint8_t green,uint8_t blue)
{
    uint8_t *pPixel = m_pPixel.get();
    pPixel+=(y*3)*m_width+(x*3);    //移动像素指针

    //小端存储
    pPixel[0]=blue;
    pPixel[1]=green;
    pPixel[2]=red;
}

} // namespace czh

