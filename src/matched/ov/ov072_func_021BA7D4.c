/*
 * function: TOWNMAP_MapClearHighlight
 * address: 0x021BA7D4
 * packet: pkt_ov072_021BA7D4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_TownUnhighlight 0x021BAE44 thumb ov072
 */
#include "../include/Obj13200.h"
typedef unsigned int u32;
extern void TOWNMAP_TownUnhighlight(void *p);
void TOWNMAP_MapClearHighlight(char *p) { u32 i; for(i=0;i<((struct Obj13200 *)p)->fC;i++) TOWNMAP_TownUnhighlight((void *)(((struct Obj13200 *)p)->f8+i*0x44)); }
