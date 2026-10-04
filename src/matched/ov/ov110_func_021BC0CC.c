/*
 * function: func_021BC0CC
 * address: 0x021BC0CC
 * packet: pkt_ov110_021BC0CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BF6E4 0x021BF6E4 thumb ov110
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 */
#include "../include/Obj10276.h"
typedef unsigned char u8;
extern unsigned func_021BF6D8(u8 *);
extern unsigned func_021BF6E4(u8 *);
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
void func_021BC0CC(u8 *p)
{
    if (func_021BF6D8(*(u8 * *)&((struct Obj10276 *)p)->f4)==2 && func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)<5) {
        unsigned n=func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)+1;
        func_0207E3D0(p+0x58+n*32,0,32);
        func_0207E468(p+0x58+n*32,0,32);
    } else {
        func_0207E3D0(p+0x58,0,32);
        func_0207E468(p+0x58,0,32);
    }
}
