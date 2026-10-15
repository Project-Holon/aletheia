/*
 * function: LOCAL_TVT_SYS_HideActor
 * address: 0x021B6754
 * packet: pkt_ov174_021B6754
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj24200.h"
struct Obj;extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
void LOCAL_TVT_SYS_HideActor(char *p) {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj24200 *)p)->f54,0);}
