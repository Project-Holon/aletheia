/*
 * function: func_021D7484
 * address: 0x021D7484
 * packet: pkt_ov120_021D7484
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
void func_021D7484(char *p) { CLACT_SetActorDrawEnable(((struct Obj00199 *)p)->f12C,0); CLACT_DeleteActor(((struct Obj00199 *)p)->f12C); CLACT_SetActorDrawEnable(((struct Obj00199 *)p)->f130,0); CLACT_DeleteActor(((struct Obj00199 *)p)->f130); }
