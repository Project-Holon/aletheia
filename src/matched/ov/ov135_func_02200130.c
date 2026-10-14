/*
 * function: WORLDTRADE_TITLE_SetBgVisible
 * address: 0x02200130
 * packet: pkt_ov135_02200130
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj23440.h"
struct Obj;
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
void WORLDTRADE_TITLE_SetBgVisible(char *p) {BG_SYS_SetMainPlaneVisible(1,0);BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetMainPlaneVisible(4,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj23440 *)p)->fBF4,0);}
