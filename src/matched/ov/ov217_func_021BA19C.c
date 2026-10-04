/*
 * function: func_021BA19C
 * address:  0x021BA19C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C09C8  0x021C09C8  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *
 * Same classifier as func_021BE46C with the pair (2, 1).
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25812.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C09C8(void *p);
extern u32 func_021C09CC(void *p);
u32 func_021BA19C(u8 *a0)
{
    u32 v = ((struct Obj25812 *)a0)->f0;
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 2;
    }
    return 1;
}
