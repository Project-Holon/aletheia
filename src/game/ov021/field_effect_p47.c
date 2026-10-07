/*
 * file:     field_effect_p47.c
 * unit:     yes
 * function: func_021ABE14, func_021ABE18, func_021ABE24, func_021ABE28
 * address:  0x021ABE14
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
 *   func_02188CD8  0x02188CD8  thumb  ov021
 */
#include "../../matched/include/Obj18079.h"
#include "../../matched/include/Obj18080.h"
#include "../../matched/include/Obj18081.h"
#include "../../matched/include/Obj18082.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_02188CD8(u8 *p);
u32 func_021ABE14(u8 *p);
u32 func_021ABE18(u8 *p);
u32 func_021ABE24(u8 *p);
u8 func_021ABE28(u8 *p);


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021ABE14(u8 *p)
{
    return ((struct Obj18079 *)p)->f8;
}


/*
 * Tail-call thunk: the object's word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021ABE18(u8 *p)
{
    return func_02188CD8((u8 *)(((struct Obj18080 *)p)->f8));
}


/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021ABE24(u8 *p)
{
    return ((struct Obj18081 *)p)->fC;
}


/*
 * Loads the byte at +0x16 of the object.
 */
u8 func_021ABE28(u8 *p)
{
    return ((struct Obj18082 *)p)->f16;
}
