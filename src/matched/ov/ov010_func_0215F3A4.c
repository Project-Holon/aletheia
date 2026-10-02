/*
 * function: func_0215F3A4
 * address:  0x0215F3A4
 * packet:   pkt_ov010_0215F3A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_0215F608  0x0215F608  thumb  ov010
 *   func_0215A480  0x0215A480  thumb  ov010
 *   func_0215A490  0x0215A490  thumb  ov010
 *   func_02162788  0x02162788  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern int func_02159B10();
extern void *func_0215A5E4(void *a0);
extern int func_02012844();
extern int func_0215911C();
extern int func_0215F608();
extern int func_0215A480();
extern int func_0215A490();
extern int func_02162788();

int func_0215F3A4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y0 = func_02159B10(a, b);
    int y1 = func_02159B10(a, b);
    int y2 = func_02159B10(a, b);
    int y3 = func_02159B10(a, b);
    u8 *base;
    u8 *e;
    u16 h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    e = base + 6;
    h = func_0215F608(base, y0, y3);
    func_02162788(r, y1, func_0215A480(*(u16 *)(e + h * 8)));
    func_02162788(r, y2, func_0215A490(*(u16 *)(e + h * 8)));
    return 0;
}
