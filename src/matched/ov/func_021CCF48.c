/*
 * function: func_021CCF48
 * address:  0x021CCF48
 * packet:   pkt_021CCF48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0xac.
 *
 * symbols:
 *   func_021909BC  0x021909BC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18357.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021909BC(void *a);

void func_021CCF48(u8 *p)
{
    func_021909BC((void *)(((struct Obj18357 *)p)->fAC));
}
