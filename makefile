cc=g++
CFLAGS=-g
TARGET:main.exe
LIBS=-std=c++11
OBJS=main.o Bitmap.o Mandelbrot.o ZoomList.o FractalCreator.o RGB.o
main.exe:${OBJS}
	${cc} ${CFLAGS} ${OBJS} -o main.exe ${LIBS}
main.o:main.cpp
	${cc} ${CFLAGS} main.cpp -c
Bitmap.o:Bitmap.cpp
	${cc} ${CFLAGS}  Bitmap.cpp -c
Mandelbrot.o:Mandelbrot.cpp
	${cc} ${CFLAGS} Mandelbrot.cpp -c
ZoomList.o:ZoomList.cpp
	${cc} ${CFLAGS} ZoomList.cpp -c
FractalCreator.o:FractalCreator.cpp
	${cc} ${CFLAGS} FractalCreator.cpp -c
RGB.o:RGB.cpp
	${cc} ${CFLAGS} RGB.cpp -c
clean:
	rm -rf *.o
	rm -rf *.exe