/*
 * function: func_021C00FC
 * address: 0x021C00FC
 * packet: pkt_ov110_021C00FC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj05298.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
int func_021C00FC(u8 *p) { if(CLACT_GetActorAnimSeq(((struct Obj05298 *)p)->f14)!=28) return 1; if(!CLACT_IsActorAnimActive(((struct Obj05298 *)p)->f14)) { CLACT_SetActorDrawEnable(((struct Obj05298 *)p)->f14,((struct Obj05298 *)p)->f18); CLACT_SetActorAnimSeq(((struct Obj05298 *)p)->f14,8); ((struct Obj05298 *)p)->f18=0; return 1; } return 0; }
