/*
 * file:     fld3d_ci_p03.c
 * unit:     yes
 * function: func_021C1AA8, func_021C1AB4, func_021C1AD0
 * address:  0x021C1AA8
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
 *   func_02051230  0x02051230  arm
 *   func_021C1A84  0x021C1A84  thumb  ov021
 *   func_02050ED4  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj18282.h"
#include "../../matched/include/Obj09206.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02051230(u32, u32, u32, u32);
extern int func_02051614(int **p);
extern u32 func_020307B0(void *p);
extern u32 func_02050ED4(u32);
extern u32 func_021C1A84(u32, u32, u32, u32);
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d);
int func_021C1AB4(u32 *p);
int func_021C1AD0(void *a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d)
{
return func_02051230(((struct Obj18282 *)((u8 *)(a)))->fC, b, c, d);
}


int func_021C1AB4(u32 *p)
{
    if (p[3] == 0)
        return 1;
    if (func_02051614((int **)p[3]) == 0)
        return 1;
    return 0;
}


int func_021C1AD0(void *a, u32 b, u32 c, u32 d)
{
func_02050ED4(func_021C1A84((u32)a, b, c, d));
func_020307B0((void *)(((struct Obj09206 *)((u8 *)(a)))->f8));
return func_020307B0(a);
}
