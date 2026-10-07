/*
 * file:     zukan_detail_graphic_p31.c
 * unit:     yes
 * function: func_021C2430, func_021C2458
 * address:  0x021C2430
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *   func_0204B688  0x0204B688  arm
 */
#include "../../matched/include/Obj14657.h"

struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32_021C2430;

typedef enum { ONE = 1 } One;

typedef int            s32_021C2458;

extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021C2430(u8 *p);
void ov208_func_021C2458(u16 *heap, u8 *p, int key);


void func_021C2430(u8 *p)
{
    One one = ONE;
    ((struct Obj14657 *)p)->f1D8 = one;
    ((struct Obj14657 *)p)->f1DC = one << 15;
    func_0207D63C(0x04000050, 0, 0x3f, one, 16 - one);
}


void ov208_func_021C2458(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 0);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 0);
    }
}
