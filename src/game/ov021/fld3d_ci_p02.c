/*
 * file:     fld3d_ci_p02.c
 * unit:     yes
 * function: func_021C1A84, func_021C1A98
 * address:  0x021C1A84
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
 *   func_02050DB8  0x02050DB8  arm
 */
#include "../../matched/include/Obj09206.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_02050DB8(u8 *p);
extern int func_0205121C(u32 a, u32 b, u32 c);
void func_021C1A84(u8 *p);
void *func_021C1A98(u16 *p, int a, int b);


void func_021C1A84(u8 *p)
{
    u32 v = ((struct Obj09206 *)p)->fC;
    if (v != 0) {
        func_02050DB8((u8 *)v);
        ((struct Obj09206 *)p)->fC = 0;
    }
}


/*
 * Loads a resource with the owner's heap id (tail call).
 */
void *func_021C1A98(u16 *p, int a, int b)
{
    return (void *)func_0205121C(a, b, p[2]);
}
