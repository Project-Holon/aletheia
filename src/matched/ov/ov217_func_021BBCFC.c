/*
 * function: func_021BBCFC
 * address:  0x021BBCFC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Advance the u32 at +0x2c by the argument plus two, reduced modulo two.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BBCFC(void *p, s32 v)
{
    *(s32 *)&((struct Obj02928 *)p)->f2C = (*(s32 *)&((struct Obj02928 *)p)->f2C + v + 2) % 2;
}
