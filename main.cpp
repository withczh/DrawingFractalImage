#include<iostream>

#include<math.h>

#include "FractalCreator.h"
using namespace czh;

int main()
{
    const int height=600;
    FractalCreator fractalCreator(800,600);
    fractalCreator.addZoom(Zoom(285,height-202,0.001));
    fractalCreator.run("Fractal.bmp");

    std::cout<<"finished"<<std::endl;

    

    return 0;
}