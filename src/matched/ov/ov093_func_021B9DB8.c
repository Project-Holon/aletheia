/*
 * function: BTL_MAIN_ClearTrainerSlotsAndVoices
 * address: 0x021B9DB8
 * packet: pkt_ov093_021B9DB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj09942.h"
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_MAIN_ClearTrainerSlotsAndVoices(char *p) {
    u32 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*40;
        ((struct Obj09942 *)q)->f20=0;
        ((struct Obj09942 *)q)->f2A=0;
        ((struct Obj09942 *)q)->f2C=0;
    }
    for(i=0;i<4;i++) *(u32 *)(p+i*4+0x3e0)=0;
}
