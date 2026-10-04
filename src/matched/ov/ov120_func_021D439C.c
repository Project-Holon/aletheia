/*
 * function: func_021D439C
 * address: 0x021D439C
 * packet: pkt_ov120_021D439C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: handed caller 021D43BC.
 */
#include "../include/Obj01150.h"
void func_021D439C(int n, char *p) {
    ((struct Obj01150 *)p)->f144+=n;
    if(((struct Obj01150 *)p)->f144>=4) ((struct Obj01150 *)p)->f144=0;
    else if(((struct Obj01150 *)p)->f144<0) ((struct Obj01150 *)p)->f144=3;
}
