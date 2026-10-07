/*
 * file:     field_fog_p22.c
 * unit:     yes
 * function: func_021A0F7C, func_021A0F90
 * address:  0x021A0F7C
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
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 */
#include "../../matched/include/Obj07215.h"
#include "../../matched/include/Obj17990.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A0EE4(u32, u32, u32, u32);
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
u32 func_021A0F90(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07215 *)((u8 *)(a)))->f18 = c;
((struct Obj07215 *)((u8 *)(a)))->f1C = d;
((struct Obj07215 *)((u8 *)(a)))->f4 = func_021A0EE4(a, b, c, d);
((struct Obj07215 *)((u8 *)(a)))->f8 = 1;
return 1;
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A0F90(u8 *p)
{
    return ((struct Obj17990 *)p)->f0;
}
