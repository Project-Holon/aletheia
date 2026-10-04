/*
 * function: func_0689ABA0
 * address:  0x0689ABA0
 * packet:   pkt_ov095_0689ABA0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The byte and word out-parameters are one struct local: struct-member
 * loads are re-read after stores/calls (the reload of w for the (u8)
 * argument), and the compound `t.w &= ~0x8000` re-reads the member, which
 * is the second `ldr r1,[sp,#4]`.
 *
 * symbols:
 *   func_0689AC4C  0x0689AC4C  thumb  ov095
 *   func_0689AC5C  0x0689AC5C  thumb  ov095
 *   func_0689AC6C  0x0689AC6C  thumb  ov095
 *   func_0689AC7C  0x0689AC7C  thumb  ov095
 *   func_0689AC8C  0x0689AC8C  thumb  ov095
 *   func_0689AC9C  0x0689AC9C  thumb  ov095
 *   func_0689ACAC  0x0689ACAC  thumb  ov095
 *   func_0689ACBC  0x0689ACBC  thumb  ov095
 */
#include "../include/Obj04407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689AC4C(u32 h, u8 *b, u32 *w);
extern int func_0689AC5C(u32 b);
extern u32 func_0689AC6C(u32 a, u32 b);
extern void func_0689AC7C(u8 *p, u32 b);
extern void func_0689AC8C(u8 *p, u32 v, int n);
extern void func_0689AC9C(u32 p, u32 v, int n);
extern void func_0689ACAC(u32 p);
extern void func_0689ACBC(u32 p);

typedef struct { u8 b; u32 w; } T;

int func_0689ABA0(int unused, u8 *s)
{
    T t;
    u32 flag;
    u32 w;
    u32 v;

    if (func_0689AC4C(((struct Obj04407 *)s)->fB0, &t.b, &t.w)) {
        flag = (t.w & 0x8000) != 0;
        t.w &= ~0x8000;
        w = t.w;
        if (w != 4) {
            if (t.b == 0)
                t.b = 1;
            if (w != 7)
                v = func_0689AC6C(*(u32 *)(*(u32 *)&((struct Obj04407 *)s)->f7C + func_0689AC5C(t.b) * 8), (u8)t.w);
            else
                v = 0xa5;
            func_0689AC7C(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x18, t.b);
            func_0689AC8C(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x1c, v, 6);
            func_0689AC9C(((struct Obj04407 *)s)->f70, v, 6);
            if (flag)
                func_0689ACAC(((struct Obj04407 *)s)->f70);
        } else if (w == 4) {
            func_0689ACBC(((struct Obj04407 *)s)->f70);
        }
        return 1;
    }
    return 0;
}
