/*
 * function: func_021A396C
 * address:  0x021A396C
 * packet:   pkt_021A396C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x10.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18039.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A396C(u8 *p, u32 v)
{
    ((struct Obj18039 *)p)->f10 = v;
}
