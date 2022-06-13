#include "Mandelbrot.h"
#include<complex>

namespace czh
{

Mandelbrot::Mandelbrot(){}

Mandelbrot::~Mandelbrot(){}

int Mandelbrot::getIterations(double x,double y)
{
    std::complex<double> z=0;
    std::complex<double> c(x,y);

    int Iteration=0;
    while(Iteration<MAX_ITERATION)
    {
        z=z*z+c;
        if(abs(z)>2)
        {
            break;
        }
        Iteration++;
    }
    return Iteration;
}


} // namespace czh
