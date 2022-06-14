#ifndef _FRACTALCREATOR_H_
#define _FRACTALCREATOR_H_

#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include<string>
#include<memory>
#include<math.h>

namespace czh
{
class FractalCreator
{
private:
    int m_width;
    int m_height;
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};
    
private:
    void calculateIteration();
    void calculateTotalIteration();
    void drawFractal();
    void writeBitmap(std::string fileName);

public:
    FractalCreator(int,int);
    virtual ~FractalCreator();
    void addZoom(const Zoom& zoom);
    void run(std::string fileName);

};



} // namespace czh




#endif