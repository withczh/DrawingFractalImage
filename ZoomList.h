#ifndef _ZOOMLIST_H_
#define _ZOOMLIST_H_

#include "Zoom.h"
#include<vector>

namespace czh
{

    class ZoomList
    {
    public:
        ZoomList(int,int);
        void add(const Zoom& zoom);
        std::pair<double,double> doZoom(int x,int y);

    private:
        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0};

        int m_width{0};
        int m_height{0};
        std::vector<Zoom> zooms;


    };


} // namespace czh


#endif