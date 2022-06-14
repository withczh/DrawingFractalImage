#include<iostream>

#include<math.h>
#include "RGB.h"
#include "FractalCreator.h"
using namespace czh;

int main()
{



    const int height=600;
    FractalCreator fractalCreator(800,600);

    fractalCreator.addRange(0.0,RGB(0,0,100));
    fractalCreator.addRange(0.3,RGB(255,0,0));
    fractalCreator.addRange(0.5,RGB(255,255,0));
    fractalCreator.addRange(1.0,RGB(255,255,255));



    fractalCreator.addZoom(Zoom(285,height-202,0.001));
    fractalCreator.run("Fractal.bmp");

    std::cout<<"finished"<<std::endl;

    

    return 0;
}