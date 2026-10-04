/*
 * function: func_021A0458
 * address:  0x021A0458
 * packet:   pkt_ov021_021A0458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A07F8  0x021A07F8  thumb  ov021
 *   func_021A0974  0x021A0974  thumb  ov021
 *   func_021A0B14  0x021A0B14  thumb  ov021
 *   func_021A0B34  0x021A0B34  thumb  ov021
 *   func_021A0B4C  0x021A0B4C  thumb  ov021
 *   func_021A0C74  0x021A0C74  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01497.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s32 func_021A07F8(u16 a, void *b);
extern void func_021A0974(u32 a1, u32 a2, u32 a3);
extern void func_021A0B14(void *a);
extern int func_021A0B34(u32 a);
extern void func_021A0B4C(const u8 *a, u8 *b);
extern s32 func_021A0C74(void *a, void *b, void *c, void *d);

void func_021A0458(u8 *a, s32 b)
{
    s32 prev;
    s32 cur;
    s32 t;
    s32 wrapped;
    s32 i;
    u32 m;

    if (((struct Obj01497 *)a)->fC == 0)
        return;
    switch (((struct Obj01497 *)a)->f0) {
    case 0:
        cur = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34);
        wrapped = 0;
        i = ((struct Obj01497 *)a)->f350 - 1;
        if (i < 0) {
            prev = 0;
            t = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + (*(s32 *)&((struct Obj01497 *)a)->fC - 1) * 0x34);
            if (t <= b) {
                prev = t;
                wrapped = 1;
                cur += 86400;
            }
        } else {
            prev = func_021A07F8(((struct Obj01497 *)a)->f2, a + 0x10 + i * 0x34);
        }
        if ((prev > b || cur <= b) && wrapped == 0) {
            m = (*(u32 *)&((struct Obj01497 *)a)->f350 + 1) % ((struct Obj01497 *)a)->fC;
            *(u32 *)&((struct Obj01497 *)a)->f350 = m;
            func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + m * 0x34));
        }
        break;
    case 1:
        if (func_021A0C74(a + 0x484, a + 0x390, a + 0x356, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34))
            ((struct Obj01497 *)a)->f0 = 0;
        break;
    }
    if (func_021A0B34((u32)(a + 0x390))) {
        func_021A0B14(a + 0x390);
        func_021A0B4C(a + 0x390, a + 0x356);
        ((struct Obj01497 *)a)->f38C = 1;
    }
    ((struct Obj01497 *)a)->f48C = b;
}
