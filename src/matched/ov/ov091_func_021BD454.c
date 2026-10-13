/*
 * function: PLIST_BATTLE_DeleteMiniCell
 * address: 0x021BD454
 * packet: pkt_ov091_021BD454
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06214.h"
struct Descriptor;
struct Obj;
extern unsigned int func_020452E8(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCharacter(unsigned int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PLIST_BATTLE_DeleteMiniCell(char *unused,char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f4); func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f8); CLACT_DeleteActor(*(struct Obj * *)&((struct Obj06214 *)p)->f14); CLACT_DeleteActor(*(struct Obj * *)&((struct Obj06214 *)p)->f10); CLACT_ReleaseCharacter(((struct Obj06214 *)p)->fC); func_020307B0(p); }
