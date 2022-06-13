#ifndef _BITMAP_H_
#define _BITMAP_H_

#include<string>
#include<cstdint>
#include<memory>

namespace czh
{
    class Bitmap
    {
    public:
        Bitmap(int width,int height);
        bool write(std::string filename);
        void setPixel(int x,int y,uint8_t red,uint8_t green,uint8_t blue);
        virtual ~Bitmap();

    private:
        int m_width{0};
        int m_height{0};
        std::unique_ptr<uint8_t[]> m_pPixel{nullptr};

    };
}

#endif