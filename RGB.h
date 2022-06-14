#ifndef _RGB_H_
#define _RGB_H_

namespace czh
{
struct RGB
{
    double r;
    double g;
    double b;

    RGB(double,double,double);


};

RGB operator-(const RGB& first,const RGB& second);
} // namespace czh


#endif