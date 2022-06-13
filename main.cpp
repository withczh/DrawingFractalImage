#include<iostream>
#include "Bitmap.h"
using namespace czh;

int main()
{
    const int width = 800;
    const int height = 600;
    Bitmap bitmap(width,height);
    
    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            bitmap.setPixel(x,y,255,0,0);
        }
    }
    
    
    bitmap.setPixel(width/2,height/2,255,255,255);
    bitmap.write("test.bmp");

    std::cout<<"finished"<<std::endl;

    

    return 0;
}