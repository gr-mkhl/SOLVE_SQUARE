#include "PAINTSQ.H"

//void DrawAxis();
//void DrawFunc(int x, EqCoeffs* eq);
RGB_t Frame[YMAX][XMAX] = {};
double Scale = 2;

void PutFramePixel(int x, int y, RGB_t Color);
void CleanFrame();
void DrawFrame();
void DrawSq(coeffs Sq);
double FuncSq(coeffs Sq, double x);
coeffs RandCoeffs();
RGB_t RandRGB();


void Paint()
{


    txCreateWindow(XMAX, YMAX);
    DrawFrame();

    coeffs My = {0.01, 0.05, 3};

    while (true)
    {
        if (txGetAsyncKeyState(VK_UP))
        {
          Scale *= 2;

          CleanFrame();
          DrawFrame();
          DrawSq(My);
          DrawFrame();
        }
        if (txGetAsyncKeyState(VK_DOWN))
        {
          Scale /= 2;
          CleanFrame();
          DrawFrame();
          DrawSq(My);
          DrawFrame();
        }
        if (txGetAsyncKeyState(VK_ESCAPE))
            return;
    }
}

coeffs RandCoeffs()
{
    coeffs Now = {};

    Now.a = MyRandDouble(-0.5, 0.5);
    Now.b = MyRandInt(-10, 10);
    Now.c = MyRandInt(-10, 10);

    return Now;
}

RGB_t RandRGB()
{
    RGB_t Now = {};

    Now.Red = (unsigned char)MyRandInt(0, 255);
    Now.Green = (unsigned char)MyRandInt(0, 255);
    Now.Blue = (unsigned char)MyRandInt(0, 255);

    return Now;
}
void CleanFrame()
{
    for (int y = -YMAX / 2; y < YMAX / 2; y++)
        for (int x = -XMAX / 2; x < XMAX / 2; x++)
        {
            PutFramePixel(x, y, {0, 0, 0});
        }
}

void PutFramePixel(int x, int y, RGB_t Color)
{
    Frame[YMAX / 2 - y - 1][XMAX / 2 + x - 1] = Color;
}

void DrawFrame()
{
    for (int x = 0; x < XMAX; x++)
        for (int y = 0; y < YMAX; y++)
            txSetPixel(x, y, RGB(Frame[y][x].Red, Frame[y][x].Green, Frame[y][x].Blue));
}


double FuncSq(coeffs Sq, double x)
{
    return Sq.a * x * x + Sq.b * x + Sq.c;
}

void DrawSq(coeffs Sq)
{
  RGB_t Now = RandRGB();

  for (int y = - YMAX / 2; y < YMAX / 2; y++)
    for (int x = - XMAX / 2; x < XMAX / 2; x++)
    {
        if
        (
        ((FuncSq(Sq, x / Scale) <= (y + 1) / Scale) && (FuncSq(Sq, (x + 1) / Scale) >= (y + 1) / Scale)) ||
        ((FuncSq(Sq, x / Scale) >= (y + 1) / Scale) && (FuncSq(Sq, (x + 1) / Scale) <= (y + 1) / Scale)) ||
        ((FuncSq(Sq, x / Scale) <= (y + 1) / Scale) && (FuncSq(Sq, x / Scale) >= y / Scale))             ||
        ((FuncSq(Sq, (x + 1) / Scale) >= y / Scale) && (FuncSq(Sq, (x + 1) / Scale) <= (y + 1) / Scale))
        )
        {
            PutFramePixel(x, y, Now);
        }
    }
}
