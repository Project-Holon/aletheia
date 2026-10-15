/*
 * function: POKE_SUMMARY_ACTOR_DeleteSystem
 * address: 0x021B7694
 * packet: pkt_ov173_021B7694
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;struct Bank;
extern void CLACT_DeleteActor(struct Obj *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void ARC_TOOL_DeleteHandle(void *);
void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p) {u32 i;for(i=0;i<14;i++)CLACT_DeleteActor(*(struct Obj **)(p+i*4+260));CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj00362 *)p)->f100);CLACT_ExitSystem();ARC_TOOL_DeleteHandle(((struct Obj00362 *)p)->f13C);}
