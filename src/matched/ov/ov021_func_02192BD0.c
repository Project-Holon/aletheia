/*
 * function: func_02192BD0
 * address:  0x02192BD0
 * packet:   pkt_ov021_02192BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-layer twin of func_02192E0C, plus func_02194704 on the new handle.
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02192FA4  0x02192FA4  thumb  ov021
 *   func_02194670  0x02194670  thumb  ov021
 *   func_02194704  0x02194704  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3E98     0x021D3E98  data  a4
 *   d_021D3E78     0x021D3E78  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00952.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int w[8]; } B32;
typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

extern const B32 d_021D3E98;
extern const B32 d_021D3E78;
struct BgTemplate;
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
typedef unsigned int   u32;
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02192FA4(int, int);
extern void *func_02194670(u16 *a);
extern void func_02194704(void);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(u32 which, unsigned char enable);

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
