#include "FractalCreator.h"

namespace czh
{
FractalCreator::FractalCreator(int width,int height):m_width(width),m_height(height),
m_histogram(new int[Mandelbrot::MAX_ITERATION]{0}),m_fractal(new int[width*height]{0}),
m_bitmap(width,height),m_zoomList(width,height)
{
    m_zoomList.add(Zoom(width/2,height/2,0.005));
}

FractalCreator::~FractalCreator(){}

void FractalCreator::run(std::string fileName)
{
    calculateIteration();
    calculateTotalIteration();
    drawFractal();
    writeBitmap(fileName);
}

void FractalCreator::calculateIteration()
{
    for(int y=0;y<m_height;y++)
    {
        for(int x=0;x<m_width;x++)
        {
            std::pair<double,double> coords=m_zoomList.doZoom(x,y);

            int iteration = Mandelbrot::getIterations(coords.first,coords.second);
            m_fractal[y*m_width+x]=iteration;

            if(iteration!=Mandelbrot::MAX_ITERATION)
            {
                m_histogram[iteration]++;
            }         
            
        }
    }
}

void FractalCreator::calculateTotalIteration()
{
    for(int i=0;i<Mandelbrot::MAX_ITERATION;i++)
    {
        m_total+=m_histogram[i];
    }
}

void FractalCreator::addZoom(const Zoom& zoom)
{
    m_zoomList.add(zoom);
}

void FractalCreator::drawFractal()
{
    for(int y=0;y<m_height;y++)
    {
        for(int x=0;x<m_width;x++)
        {
            uint8_t red=0;
            uint8_t green=0;
            uint8_t blue=0;
            int iteration=m_fractal[y*m_width+x];
            if(iteration!=Mandelbrot::MAX_ITERATION)
            {
                double hue=0.0;
                for(int i=0;i<=iteration;i++)
                {
                    hue+=((double)m_histogram[i])/m_total;
                } 
                red=pow(255,hue);   
            }

            m_bitmap.setPixel(x,y,red,green,blue);
        }
    }
}

void FractalCreator::writeBitmap(std::string fileName)
{
    m_bitmap.write(fileName);
}


} // namespace czh
