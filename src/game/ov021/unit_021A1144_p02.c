/*
 * file:     unit_021A1144_p02.c
 * unit:     yes
 * function: func_021A12A4, func_021A12BC
 * address:  0x021A12A4
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
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A8E10  0x021A8E10  thumb  ov021
 *   func_021A8E20  0x021A8E20  thumb  ov021
 */
#include "../../matched/include/Obj17993.h"

struct W;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A0F90(u8 *p);
extern u32 func_021A8E10(u32);
extern void func_021A8E20(struct W *w, u32 v);
u32 func_021A12A4(void *a);
void func_021A12BC(u32 *p, u32 a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A12A4(void *a)
{
if (func_021A0F90((u8 *)a) != 1) {
    return 0;
}
return func_021A8E10(((struct Obj17993 *)((u8 *)(a)))->f20);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A12BC(u32 *p, u32 a)
{
    if (func_021A0F90((u8 *)p) == 1)
        func_021A8E20((struct W *)p[8], a);
}
