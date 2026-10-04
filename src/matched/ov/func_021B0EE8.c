/*
 * function: func_021B0EE8
 * address:  0x021B0EE8
 * packet:   pkt_021B0EE8
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
 *   func_021B0AB0  0x021B0AB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18091.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021B0AB0(u32 v);

int func_021B0EE8(u8 *p)
{
    func_021B0AB0(((struct Obj18091 *)p)->f4);
    return 1;
}
