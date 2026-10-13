/*
 * function: TOWNMAP_TownIsRevealed
 * address: 0x021BA834
 * packet: pkt_ov072_021BA834
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
#include "../include/Obj03179.h"
typedef unsigned short u16;
extern unsigned short TOWNMAP_GRH_GetTownInfoValue(char *p, int a, int b);
int TOWNMAP_TownIsRevealed(char *p) { int v; v=TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),15); if((v!=65535 && ((struct Obj03179 *)p)->f38!=0 && ((struct Obj03179 *)p)->f40==0) || v==65535) return 1; return 0; }
