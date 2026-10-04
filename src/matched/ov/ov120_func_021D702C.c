/*
 * function: func_021D702C
 * address: 0x021D702C
 * packet: pkt_ov120_021D702C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 * symbols:
 *   func_021D71E8 0x021D71E8 thumb ov120
 */
#include "../include/Obj01541.h"
typedef unsigned char u8;
extern void func_021D71E8(u8 *, int, int);
int func_021D702C(u8 *p, int *out)
{
    int i;
    int state;
    state=((struct Obj01541 *)p)->f108;
    if (state==2) {
        ((struct Obj01541 *)p)->f104+=8;
        if (((struct Obj01541 *)p)->f10C==((struct Obj01541 *)p)->f104) {
            *out=state;
            ((struct Obj01541 *)p)->f108=0;
            ((struct Obj01541 *)p)->f104-=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,-8);
        ((struct Obj01541 *)p)->f100=1;
    }
    state=((struct Obj01541 *)p)->f108;
    if (state==1) {
        ((struct Obj01541 *)p)->f104-=8;
        if (((struct Obj01541 *)p)->f10C==((struct Obj01541 *)p)->f104) {
            *out=state;
            ((struct Obj01541 *)p)->f108=0;
            ((struct Obj01541 *)p)->f104+=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,8);
        ((struct Obj01541 *)p)->f100=1;
    }
    return ((struct Obj01541 *)p)->f108;
}
