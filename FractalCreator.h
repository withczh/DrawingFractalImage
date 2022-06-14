#ifndef _FRACTALCREATOR_H_
#define _FRACTALCREATOR_H_

#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"
#include<string>
#include<memory>
#include<math.h>
#include<vector>
#include<assert.h>


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

    std::vector<int> m_ranges;
    std::vector<RGB> m_colors;
    std::vector<int> m_rangeTotals;

    bool m_bGetFirstRange{false};
    
private:
    void calculateIteration();
    void calculateTotalIteration();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(std::string fileName);
    int getRange(int interations) const;

public:
    FractalCreator(int,int);
    virtual ~FractalCreator();
    void addRange(double rangeEnd,const RGB& rgb);
    void addZoom(const Zoom& zoom);
    void run(std::string fileName);

};



} // namespace czh




#endif