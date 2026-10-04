/*
 * function: func_021736C8
 * address:  0x021736C8
 * packet:   pkt_ov012_021736C8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save) in the ov012 listing; callee of ov031
 * func_021F00D4 (a blocker of its MATCH). Same +0x2830 block as
 * func_021736A0.
 */
#include "../include/Obj09360.h"

typedef unsigned char u8;
typedef unsigned short u16;

void func_021736C8(u8 *a, int v)
{
    u8 *p = a + 0x2830;
    p[0xf] = v;
    (((struct Obj09360 *)p)->fC)++;
    p[0xe] = 1;
}
