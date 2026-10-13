/*
 * function: PLIST_PLATE_Delete
 * address: 0x021BA890
 * packet: pkt_ov091_021BA890
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03678.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
struct Descriptor;
struct Obj;
extern u32 func_020452E8(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_DeleteRenderer(void *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ReleaseCharacter(u32);
extern u32 func_020307B0(void *p);
void PLIST_PLATE_Delete(void *ignored,u8 *p) { if (!((struct Obj03678 *)p)->f14) { func_020452E8(((struct Obj03678 *)p)->f20); CLACT_DeleteActor(((struct Obj03678 *)p)->f30); CLACT_DeleteActor(((struct Obj03678 *)p)->f34); CLACT_DeleteActor(((struct Obj03678 *)p)->f38); CLACT_DeleteRenderer(((struct Obj03678 *)p)->f24); CLACT_DeleteUnit(((struct Obj03678 *)p)->f28); CLACT_ReleaseCharacter(((struct Obj03678 *)p)->f2C); } func_020307B0(p); }
