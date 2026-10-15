/*
 * unit: yes
 * function: EGG_DEMO_VIEW_SetActive,EGG_DEMO_VIEW_GetActive
 * address: 0x021F6A3C
 * packet: pkt_ov215_021F6A3C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter, two alignment bytes, four-byte getter; twelve bytes total.
 */
#include "../include/Obj25756.h"
#include "../include/Obj25757.h"
void EGG_DEMO_VIEW_SetActive(char *p){((struct Obj25756 *)p)->f10=1;}
int EGG_DEMO_VIEW_GetActive(char *p){return ((struct Obj25757 *)p)->f14;}
