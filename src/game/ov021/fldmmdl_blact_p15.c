/*
 * file:     fldmmdl_blact_p15.c
 * unit:     yes
 * function: func_0219E334, func_0219E348
 * address:  0x0219E334
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 */
#include "../../matched/include/Obj17973.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D69C(void *p);
extern u32 func_021B7DC0(u32, u32);
int func_0219E334(u32 a, u32 b);
void *func_0219E348(void *a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E334(u32 a, u32 b)
{
return func_021B7DC0(((struct Obj17973 *)((u8 *)(func_0216D69C((void *)a))))->f0, b);
}


void *func_0219E348(void *a)
{
    return *(void **)func_0216D69C(a);
}
