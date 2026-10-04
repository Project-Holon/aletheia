/*
 * function: func_021BF6F0
 * address: 0x021BF6F0
 * packet: pkt_ov110_021BF6F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020244F0 0x020244F0 thumb
 */
#include "../include/Obj22387.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_020244F0(void *,u32);
u32 func_021BF6F0(u8 *p,u32 i) {
    if(((struct Obj22387 *)p)->f4==2) return func_020244F0(p+8,i);
    return *(u16 *)((u32)p+i*2+0x10);
}
