/*
 * function: func_021D3D9C
 * address: 0x021D3D9C
 * packet: pkt_ov093_021D3D9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Byte narrowing before call proves u8 third argument despite wide callee definition.
 * symbols:
 *   func_021B9F84 0x021B9F84 thumb ov093
 */
#include "../include/Obj13429.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B9F84(char *p, int i, unsigned int j);
void func_021D3D9C(u8 *p) {
    u32 i;
    for(i=0;i<4;i++) *(u16 *)(p+i*2+0xe8)=func_021B9F84(*(char * *)&((struct Obj13429 *)p)->f0,p[0x1a6],(u8)i);
}
