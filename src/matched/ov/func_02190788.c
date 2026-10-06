/*
 * function: func_02190788
 * address:  0x02190788
 * packet:   pkt_02190788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   func_02190620  0x02190620  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17929.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02190620(u32 a);

void func_02190788(u8 *p)
{
    func_02190620(((struct Obj17929 *)p)->f4);
}
