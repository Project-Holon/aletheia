/*
 * function: func_021BEB78
 * address: 0x021BEB78
 * packet: pkt_ov110_021BEB78
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3978 0x021C3978 data a1
 */
#include "../include/Obj01532.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021C3978[][4];
int func_021BEB78(u8 *p) {
    u16 v=((struct Obj01532 *)p)->f4C;
    u16 n=v;
    if(v==254) n=12;
    if(v!=254) {
        ((struct Obj01532 *)p)->f4E=v;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][0]; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][1]; return 1; }
        if(((struct Obj01532 *)p)->f38&32) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][2]; return 1; }
        if(((struct Obj01532 *)p)->f38&16) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][3]; return 1; }
    } else {
        ((struct Obj01532 *)p)->f4E=254;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=11; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=2; return 1; }
    }
    return 0;
}
