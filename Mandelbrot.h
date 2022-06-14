#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

namespace czh
{

    class Mandelbrot
    {

    public:
        static const int MAX_ITERATION=500; 

    public:
        Mandelbrot();
        virtual ~Mandelbrot();
        static int getIterations(double x,double y);

    };

} // namespace czh


#endif