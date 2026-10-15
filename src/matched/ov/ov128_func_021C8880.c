/*
 * function: Wf2dmapFriend_HideEntryActor
 * address: 0x021C8880
 * packet: pkt_ov128_021C8880
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display control MMIO 0x04000000 read/write at 021C888A and 021C8892.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
void Wf2dmapFriend_HideEntryActor(u8 *p) {*(volatile u32 *)0x04000000 &= ~0xe000u;CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);}
