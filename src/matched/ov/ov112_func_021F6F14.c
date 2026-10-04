/*
 * function: func_021F6F14
 * address: 0x021F6F14
 * packet: pkt_ov112_021F6F14
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj08025.h"
typedef unsigned char u8;
typedef unsigned short u16;
void func_021F6F14(void *a,char *p,u16 b,u8 c)
{
    ((struct Obj08025 *)p)->f4=b;
    ((struct Obj08025 *)p)->f6=c;
}
