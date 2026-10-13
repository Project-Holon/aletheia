/*
 * function: FIELD_ENCOUNT_Delete
 * address:  0x021A9F28
 * packet:   pkt_021A9F28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   EFFECT_ENCOUNT_Exit  0x021AA7CC  thumb  ov021
 *   EFFECT_ENCOUNT_Delete  0x021AA794  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12092.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern u32 EFFECT_ENCOUNT_Delete(u32);
extern int EFFECT_ENCOUNT_Exit(u32 a, u32 b, u32 c, u32 d);

int FIELD_ENCOUNT_Delete(void *a, u32 b, u32 c, u32 d)
{
EFFECT_ENCOUNT_Exit((u32)a, ((struct Obj12092 *)((u8 *)(a)))->f10, c, d);
EFFECT_ENCOUNT_Delete(((struct Obj12092 *)((u8 *)(a)))->f10);
return func_020307B0(a);
}

