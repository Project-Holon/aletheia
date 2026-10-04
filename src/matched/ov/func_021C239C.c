/*
 * function: func_021C239C
 * address:  0x021C239C
 * packet:   pkt_021C239C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC518 0x021BC518  thumb  ov208
 *
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls func_021BC518 on the word at +0x418.
 */
#include "../include/Obj18288.h"

extern void func_021BC518(int *p);

void func_021C239C(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021BC518((int *)(((struct Obj18288 *)p)->f418));
}
