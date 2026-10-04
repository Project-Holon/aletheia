/*
 * function: func_021B1234
 * address:  0x021B1234
 * packet:   pkt_021B1234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021B120C  0x021B120C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021B120C(u32 v);

int func_021B1234(u8 *p)
{
    func_021B120C(((struct Obj18093 *)p)->f4);
    return 1;
}
