/*
 * unit:     yes
 * function: func_021BA318
 * function: func_021BA394
 * address:  0x021BA318
 * packet:   pkt_ov091_021BA318
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB464  0x021BB464  thumb ov091
 *   func_021BB97C  0x021BB97C  thumb ov091
 *   func_021BB99C  0x021BB99C  thumb ov091
 *   func_021BB9EC  0x021BB9EC  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021B9E20  0x021B9E20  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021BA3A4  0x021BA3A4  thumb ov091
 */
#include "../include/Obj13244.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern u16  func_021BB464(int unused, u16 *q);
extern void func_021BB97C(u8 *p, u32 obj);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9EC(u8 *p, u32 obj, u32 a, u16 b, u8 c);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E20(u8 *p);
extern void func_021B9804(u8 *p, int a1);
extern void func_021BA3A4(u8 *p, u32 state);

void func_021BA318(u8 *p)
{
    u16 r;
    u16 t;

    r = func_021BB464((int)p, (u16 *)((u32 *)(p + 0x160))[((u32 *)W(0x280))[0x3c / 4]]);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    func_021BB97C(p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    t = ((struct Obj13244 *)p)->f11C;
    if (t) {
        func_021BB9EC(p, W(0x150), 1, r - t, 3);
        func_021B9788(p, 0x2c, 1, (int)func_021B9E20);
    }
    func_021BB98C(p, W(0x150));
}

void func_021BA394(u8 *p)
{
    func_021B9804(p, (int)func_021BA3A4);
}
