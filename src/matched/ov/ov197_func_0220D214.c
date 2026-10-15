/*
 * function: B_BAG_MAIN_StateShowPocket0
 * address: 0x0220D214
 * packet: pkt_ov197_0220D214
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_DrawPage 0x0220B1B0 thumb ov197
 */
#include "../include/Obj14548.h"
extern void B_BAG_MAIN_DrawPage(char *,int);
int B_BAG_MAIN_StateShowPocket0(char *p){B_BAG_MAIN_DrawPage(p,0);((struct Obj14548 *)p)->f532=0;((struct Obj14548 *)p)->f531=4;return 10;}
