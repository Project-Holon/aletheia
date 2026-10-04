/*
 * function: func_021D437C
 * address: 0x021D437C
 * packet: pkt_ov120_021D437C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D439C.
 */
#include "../include/Obj06432.h"
void func_021D437C(int n, char *p) {
    ((struct Obj06432 *)p)->f140+=n;
    if(((struct Obj06432 *)p)->f140>=5) ((struct Obj06432 *)p)->f140=0;
    else if(((struct Obj06432 *)p)->f140<0) ((struct Obj06432 *)p)->f140=4;
}
