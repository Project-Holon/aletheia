/*
 * file:     unit_02192860.c
 * unit:     yes
 * function: func_02192860, func_021928C0, func_021928F8, func_021929E8, func_02192A04, func_02192B20, func_02192B64, func_02192BC0, func_02192BD0
 * address:  0x02192860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_020439A0  0x020439A0  arm
 *   d_021D3E60     0x021D3E60  data  a2
 *   func_021927FC  0x021927FC  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021D3E58     0x021D3E58  data  a2
 *   func_02049624  0x02049624  arm  arm9
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045730  0x02045730  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02192FA4  0x02192FA4  thumb  ov021
 *   func_02194670  0x02194670  thumb  ov021
 *   func_02194704  0x02194704  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3E98     0x021D3E98  data  a4
 *   d_021D3E78     0x021D3E78  data  a4
 */
#include "../../matched/include/Obj03575.h"
#include "../../matched/include/Obj02692.h"
#include "../../matched/include/Obj00952.h"

struct Bmp;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct BgTemplate;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct T3 {
    u16 v[3];
};

typedef short          s16_021928C0;

typedef struct Cur {
    u8 f00;
    u8 f01;
    u8 f02;
} Cur;

typedef signed short   s16_021928F8;

typedef short          s16_021929E8;

typedef signed int     s32;

typedef struct { int w[8]; } B32;

typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_021927FC(Cur *c, u32 win, u32 col);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041300(u32 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, unsigned char c, unsigned char d, unsigned char slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *a);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02192FA4(int, int);
extern void *func_02194670(u16 *a);
extern void func_02194704(void);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_02192860(u8 *a, u32 b, u32 col);
void func_021928C0(Cur *c, u32 win, u32 col);
void func_021928F8(u8 *a, u32 b, u32 c);
void func_021929E8(u32 heap);
void func_02192A04(u32 win);
u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e);
void func_02192B64(u32 a);
void func_02192BC0(u8 *p);
void func_02192BD0(char *p, int flag);
extern struct T3 d_021D3E60;
extern struct T3 d_021D3E58;
extern const B32 d_021D3E98;
extern const B32 d_021D3E78;


void func_02192860(u8 *a, u32 b, u32 col)
{
    struct T3 t;
    u16 x;
    u16 y;

    t = d_021D3E60;
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    func_020439A0((struct Bmp *)(((struct Obj03575 *)a)->f4), (struct Bmp *)b, 0, 0, x, y, 8, 8, 0);
    a[0] = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021928C0(Cur *c, u32 win, u32 col)
{
    func_021927FC(c, win, col);
    c->f02++;
    if (c->f02 >= 4) {
        c->f02 = 0;
        c->f01++;
        c->f01 %= 3;
    }
    func_02192860((u8 *)c, win, col);
}


void func_021928F8(u8 *a, u32 b, u32 c)
{
    struct T3 t;
    s16_021928F8 x;
    s16_021928F8 y;
    s16_021928F8 m;

    t = d_021D3E58;
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    m = y & 7;
    if (m != 0)
        func_020439A0((struct Bmp *)c, (struct Bmp *)b, 0, 8 - m, x, y, 8, m, 0xFFFF);
    func_020439A0((struct Bmp *)c, (struct Bmp *)b, 0, 0, x, y + m, 8, 8 - m, 0xFFFF);
    a[2]++;
    if (a[2] >= 4) {
        a[2] = 0;
        a[1]++;
        a[1] = a[1] % 3;
    }
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    func_020439A0((struct Bmp *)(((struct Obj02692 *)a)->f4), (struct Bmp *)b, 0, 0, x, y, 8, 8, 0);
    a[0] = 1;
}


void func_021929E8(u32 heap)
{
    func_02049624(5, 10, 1, 0x1F, 0, 0, heap);
}


/*
 * Draws a one-tile frame around a window (tiles 0x1F..0x30, palette 13).
 *
 * Addresses are Black-image addresses.
 */
void func_02192A04(u32 win)
{
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u32 bg;

    x = func_02045758((struct Descriptor *)win);
    y = func_02045760((struct Descriptor *)win);
    w = func_02045738((struct Descriptor *)win);
    h = func_02045740((struct Descriptor *)win);
    bg = func_02045730((struct Descriptor *)win);
    func_02041300(bg, 0x1f, x - 1, y - 1, 1, 1, 13);
    func_02041300(bg, 0x20, x, y - 1, w, 1, 13);
    func_02041300(bg, 0x24, x + w, y - 1, 1, 1, 13);
    func_02041300(bg, 0x25, x - 1, y, 1, h, 13);
    func_02041300(bg, 0x2a, x + w, y, 1, h, 13);
    func_02041300(bg, 0x2b, x - 1, y + h, 1, 1, 13);
    func_02041300(bg, 0x2d, x, y + h, w, 1, 13);
    func_02041300(bg, 0x30, x + w, y + h, 1, 1, 13);
    func_020409B4(bg);
}


u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e)
{
    u32 w;

    w = func_020450F0(2, a, b, c, d, 0xE, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 0xFF);
    func_02045374((struct Cfg *)w);
    func_02045334((struct Descriptor *)w);
    func_02192A04(w);
    return w;
}


void func_02192B64(u32 a)
{
    u32 bg;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    bg = func_02045730((struct Descriptor *)a);
    x = func_02045758((struct Descriptor *)a);
    y = func_02045760((struct Descriptor *)a);
    w = func_02045738((struct Descriptor *)a);
    h = func_02045740((struct Descriptor *)a);
    func_02041300(bg, 0, (u8)(x - 1), (u8)(y - 1), (u8)(w + 2), (u8)(h + 2), 0);
    func_020409B4(bg);
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_02192BC0(u8 *p)
{
    func_02192B64((u32)p);
    func_020452E8((struct Descriptor *)p);
}


/*
 * Two-layer twin of func_02192E0C, plus func_02194704 on the new handle.
 *
 * Addresses are Black-image addresses.
 */
void func_02192BD0(char *p, int flag)
{
    B32 tmp1;
    B32 tmp2;
    Req r;

    ((struct Obj00952 *)p)->f2 = 1;
    tmp1 = d_021D3E98;
    func_0203FCA0(((struct Obj00952 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp1), 0);
    ((struct Obj00952 *)p)->f4 = 2;
    tmp2 = d_021D3E78;
    func_0203FCA0(((struct Obj00952 *)p)->f4 & 0xff, (const struct BgTemplate *)(&tmp2), 0);
    func_02040C14(((struct Obj00952 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj00952 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(((struct Obj00952 *)p)->f4 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj00952 *)p)->f2 & 0xff);
    func_020409B4(((struct Obj00952 *)p)->f4 & 0xff);
    if (flag)
        func_02192FA4(((struct Obj00952 *)p)->f2, ((struct Obj00952 *)p)->f0);
    if (((struct Obj00952 *)p)->f168 != 0) {
        r.a = ((struct Obj00952 *)p)->f0;
        r.b = ((struct Obj00952 *)p)->f168;
        r.c = ((struct Obj00952 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj00952 *)p)->f15C = (int)func_02194670((u16 *)(&r));
        func_02194704();
    }
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_02040588(((struct Obj00952 *)p)->f2 & 0xff, 1);
    func_02040588(((struct Obj00952 *)p)->f4 & 0xff, 1);
    ((struct Obj00952 *)p)->f6 = 0xe;
}
