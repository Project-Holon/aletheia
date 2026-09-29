typedef struct tagAREA { unsigned short x, y, w, h; } AREA;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
extern int func_021D696C(RECT *r);
int func_021D6B04(AREA *a)
{
    RECT r;
    unsigned short x, y, w, hh;
    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
x = a->x;hh = a->h;w = a->w;y = a->y;r.r = x + w;r.t = y;r.l = x;r.b = y + hh;return func_021D696C(&r);}
