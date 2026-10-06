/*
 * function: func_021A41B0
 * address:  0x021A41B0
 * packet:   pkt_ov021_021A41B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A4254  0x021A4254  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A55A8  0x021A55A8  thumb  ov021
 *   func_021A4444  0x021A4444  thumb  ov021
 *   func_021A4224  0x021A4224  thumb  ov021
 *   func_021A4CA8  0x021A4CA8  thumb  ov021
 *   func_021A43D8  0x021A43D8  thumb  ov021
 */
#include "../include/Obj00656.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u32 wC;
    u32 w10;
} Req;

extern u16 func_021A3AB8(u32 a, u32 v);
extern int func_021A4254(u32 *p, u32 a);
extern void func_021A3CC0(u32);
extern int func_021A55A8(u32 *p, u32 a, int b);
extern int func_021A4444(u8 *p, u32 s);
extern void func_021A4224(u8 *, int, Req *);
extern void func_021A4CA8(u32 a, u32 b, u32 c);
extern void func_021A43D8(u8 *p, int k, int dir);

void func_021A41B0(u8 *p, u32 a, u32 b, u32 c)
{
    Req s;
    u32 d;
    int e;

    d = func_021A3AB8(*(u32 *)&((struct Obj00656 *)p)->fC, b);
    if (func_021A4254((u32 *)p, d) == 1) {
        func_021A3CC0(*(u32 *)&((struct Obj00656 *)p)->fC);
        if (func_021A55A8((u32 *)p, d, 0) == 0) {
            s.w0 = a;
            s.w4 = b;
            s.h8 = d;
            s.wC = c;
            s.w10 = 0;
            e = func_021A4444(p, (u32)(&s));
            func_021A4224(p, e, &s);
            func_021A4CA8((u32)p, e, (u32)(&s));
            func_021A43D8(p, e, d);
        }
    }
}
