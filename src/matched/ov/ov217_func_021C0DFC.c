/*
 * function: func_021C0DFC
 * address:  0x021C0DFC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u8 at +0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26000.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C0DFC(void *p, u8 v)
{
    ((struct Obj26000 *)p)->f0 = v;
}
