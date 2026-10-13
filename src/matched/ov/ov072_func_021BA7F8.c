/*
 * function: TOWNMAP_MapFindTownById
 * address: 0x021BA7F8
 * packet: pkt_ov072_021BA7F8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   SYMBOL_MAP_ResolveZoneId 0x02166C7C thumb ov010
 *   TOWNMAP_TownGetField 0x021BA774 thumb ov072
 * call: r1 forwards the second entry parameter unchanged to ov010's callee.
 */
#include "../include/Obj09909.h"
typedef unsigned int u32;
extern u32 SYMBOL_MAP_ResolveZoneId(void *a, u32 b);
extern int TOWNMAP_TownGetField(char *p, int i);
void *TOWNMAP_MapFindTownById(char *p, u32 b, int y) { u32 i; u32 v; void *q; v=SYMBOL_MAP_ResolveZoneId(((struct Obj09909 *)p)->f0,b); for(i=0;i<((struct Obj09909 *)p)->fC;i++) { q=(void *)(((struct Obj09909 *)p)->f8+i*0x44); if(v==TOWNMAP_TownGetField(q,0)) return q; } return 0; }
