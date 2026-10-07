/*
 * file:     field_fog_p19.c
 * unit:     yes
 * function: func_021A0CE4, func_021A0CF4
 * address:  0x021A0CE4
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
 *   func_02030734  0x02030734  arm
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   d_021DDE48  0x021DDE48  data  ov021
 *   d_021D872C  0x021D872C  data  a4
 */
#include "../../matched/include/Obj05021.h"

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021A0EE4(void *p, u32 b);
int func_021A0CE4(u16 *p);
u32 *func_021A0CF4(u32 a, u32 b, u32 c);
extern u8 d_021DDE48[];
extern const u8 d_021D872C[];


/*
 * Unlabelled leaf (ldrh; nonzero test), filed for the ov026 lane.
 */
int func_021A0CE4(u16 *p)
{
    if (*p != 0) {
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 * d_021D872C is a const table (0x1C-byte rows, a callback at +0): the
 * `const` lets its load move ahead of the p[1] store, as in the original.
 */
u32 *func_021A0CF4(u32 a, u32 b, u32 c)
{
    u32 *p;
    u32 r;

    p = (u32 *)func_02030734((u16)a, 0x2c, 1, (const char *)d_021DDE48, 0x13c);
    p[2] = 0;
    ((struct Obj05021 *)p)->fC = a;
    p[8] = 0;
    p[5] = b;
    r = func_021A0EE4(p, c);
    p[0] = r;
    p[1] = r;
    ((void (*)(u32 *, u32))*(const u32 *)(d_021D872C + r * 0x1c))(p, 0xb);
    return p;
}
