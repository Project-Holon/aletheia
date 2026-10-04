/*
 * function: func_021C8000
 * address:  0x021C8000
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's first word to func_021C7DFC.
 *
 * symbols:
 *   func_021C7DFC  0x021C7DFC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18331.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C7DFC(u32 v);

void func_021C8000(u8 *p)
{
    func_021C7DFC(((struct Obj18331 *)p)->f0);
}
