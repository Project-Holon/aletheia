/*
 * function: func_021BF360
 * address: 0x021BF360
 * packet: pkt_ov110_021BF360
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BF39E.
 * symbols:
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 */
#include "../include/Obj01923.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_021BEDD0(u8 *p);
u32 func_021BF360(u8 *p) {
    if (((struct Obj01923 *)p)->f0<((struct Obj01923 *)p)->f2) {
        if (((struct Obj01923 *)p)->f0+6<=((struct Obj01923 *)p)->f2) { ((struct Obj01923 *)p)->f8=6; ((struct Obj01923 *)p)->f0+=6; }
        else { ((struct Obj01923 *)p)->f8=((struct Obj01923 *)p)->f2-((struct Obj01923 *)p)->f0; ((struct Obj01923 *)p)->f0=((struct Obj01923 *)p)->f2; }
        if((int)func_021BEDD0(p)<((struct Obj01923 *)p)->f4-2) return 2;
        p[6]=0; return 3;
    }
    return 4;
}
