/*
 * function: Wf2dmapFriend_DeleteListActors
 * address: 0x021C6DAC
 * packet: pkt_ov128_021C6DAC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void Wf2dmapFriend_DeleteListActors(u8 *p) {int i;CLACT_DeleteActor(((struct Obj00725 *)p)->f168);CLACT_DeleteActor(((struct Obj00725 *)p)->f164);for(i=0;i<2;i++) CLACT_DeleteActor(*(void **)((u32)p+i*4+0x15c));}
