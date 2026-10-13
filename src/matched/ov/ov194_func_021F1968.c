/*
 * function: func_021F1968
 * address: 0x021F1968
 * packet: pkt_ov194_021F1968
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj10805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021F1968(u8 *p) { int i; for(i=0;i<21;i++) { void *q=*(void **)((u32)p+(u32)i*4+12); if(q)CLACT_DeleteActor(q); } CLACT_ReleasePalette(((struct Obj10805 *)p)->f0);CLACT_ReleaseCharacter((u32)(((struct Obj10805 *)p)->f4));CLACT_ReleaseCellAnim(((struct Obj10805 *)p)->f8); }
