/*
 * function: func_021BCDE0
 * address: 0x021BCDE0
 * packet: pkt_ov110_021BCDE0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 */
#include "../include/Obj10278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
extern void func_021BCFBC(u8 *, int, int);
void func_021BCDE0(u8 *p)
{
    if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4) == 1) func_021BCFBC(p, 2, 1);
}
