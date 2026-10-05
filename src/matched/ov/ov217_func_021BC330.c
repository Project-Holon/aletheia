/*
 * function: func_021BC330
 * address:  0x021BC330
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set both +0x34 and +0x38 to the argument.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14732.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC330(void *p, u32 v)
{
    ((struct Obj14732 *)p)->f38 = v;
    ((struct Obj14732 *)p)->f34 = v;
}
