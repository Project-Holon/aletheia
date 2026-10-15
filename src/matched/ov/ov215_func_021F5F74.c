/*
 * function: EGG_DEMO_MAIN_IsBgmFadeOut
 * address: 0x021F5F74
 * packet: pkt_ov215_021F5F74
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker set of concrete MATCH900 ov215021F5884; parent claim.
 * extent: 14-byte predicate then two zero alignment bytes at 021F5F82.
 */
#include "../include/Obj25740.h"
int EGG_DEMO_MAIN_IsBgmFadeOut(void *unused,char *p)
{
    if(((struct Obj25740 *)p)->f18==1)return 1;
    return 0;
}
