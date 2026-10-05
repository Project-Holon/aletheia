/*
 * function: func_0218ED34
 * address:  0x0218ED34
 * packet:   pkt_0218ED34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter at +0x78 through a displaced pointer.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17910.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0218ED34(u8 *p, u16 v)
{
    ((struct Obj17910 *)p)->f78 = v;
}
