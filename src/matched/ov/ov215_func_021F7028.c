/*
 * function: EGG_DEMO_VIEW_RemoveModel
 * address: 0x021F7028
 * packet: pkt_ov215_021F7028
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   EGG_DEMO_VIEW_FreeRecords 0x021F6718 thumb ov215
 */
#include "../include/Obj04636.h"
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *,unsigned),EGG_DEMO_VIEW_FreeRecords(void *);
void EGG_DEMO_VIEW_RemoveModel(char *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj04636 *)p)->f48,((struct Obj04636 *)p)->f4C);EGG_DEMO_VIEW_FreeRecords(((struct Obj04636 *)p)->f54);((struct Obj04636 *)p)->f50=0;}
