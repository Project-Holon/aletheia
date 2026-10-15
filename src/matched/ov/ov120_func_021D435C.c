/*
 * function: GTSNEGO_DISP_CycleRowB
 * address: 0x021D435C
 * packet: pkt_ov120_021D435C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: separately filed 021D437C.
 */
#include "../include/Obj06431.h"
void GTSNEGO_DISP_CycleRowB(int n, char *p) {
    ((struct Obj06431 *)p)->f13C+=n;
    if(((struct Obj06431 *)p)->f13C>=5) ((struct Obj06431 *)p)->f13C=0;
    else if(((struct Obj06431 *)p)->f13C<0) ((struct Obj06431 *)p)->f13C=4;
}
