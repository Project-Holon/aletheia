/*
 * function: func_021CF110
 * address:  0x021CF110
 * packet:   pkt_ov021_021CF110
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008494  0x02008494  thumb
 */
#include "../include/Obj20269.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02008494(void *a, void *b);

void func_021CF110(u8 *p, u32 v, void *a)
{
    ((struct Obj20269 *)p)->f52C = v;
    func_02008494(a, p + 0x530);
}
