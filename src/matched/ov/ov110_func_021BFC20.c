/*
 * function: func_021BFC20
 * address: 0x021BFC20
 * packet: pkt_ov110_021BFC20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF734 0x021BF734 thumb ov110
 */
#include "../include/Obj04452.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern unsigned func_021BF734(u8 *);
void func_021BFC20(u8 *p, unsigned visible) {
    if (visible) {
        if (**(unsigned * *)&((struct Obj04452 *)p)->f9C==0) func_0204B3DC(((struct Obj04452 *)p)->f14,1);
        else func_0204B3DC(((struct Obj04452 *)p)->f14,0);
        func_0204B3DC(((struct Obj04452 *)p)->f1C, func_021BF734(*(u8 * *)&((struct Obj04452 *)p)->f4)>14 ? 1 : 0);
    } else {
        func_0204B3DC(((struct Obj04452 *)p)->f14,visible);
        func_0204B3DC(((struct Obj04452 *)p)->f1C,0);
    }
}
