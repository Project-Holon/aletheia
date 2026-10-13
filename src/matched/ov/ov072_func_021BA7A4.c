/*
 * function: TOWNMAP_MapHighlightTown
 * address: 0x021BA7A4
 * packet: pkt_ov072_021BA7A4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_TownUnhighlight 0x021BAE44 thumb ov072
 *   TOWNMAP_TownHighlight 0x021BADF4 thumb ov072
 */
#include "../include/Obj13199.h"
typedef unsigned int u32;
extern void TOWNMAP_TownUnhighlight(void *p);
extern void TOWNMAP_TownHighlight(void *p);
void TOWNMAP_MapHighlightTown(char *p, void *selected) { u32 i; void *q; for(i=0;i<((struct Obj13199 *)p)->fC;i++) { q=(void *)(((struct Obj13199 *)p)->f8+i*0x44); if(q==selected) TOWNMAP_TownHighlight(q); else TOWNMAP_TownUnhighlight(q); } }
