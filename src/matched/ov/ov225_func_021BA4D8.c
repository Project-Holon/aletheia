/*
 * function: MANUAL_COMMON_DeleteTouchbarActors
 * address: 0x021BA4D8
 * packet: pkt_ov225_021BA4D8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj10984.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
void MANUAL_COMMON_DeleteTouchbarActors(char *p) { u8 i; for(i=0;i<2;i++) CLACT_DeleteActor(*(struct Obj **)(p+i*4+0x38)); CLACT_ReleaseCellAnim(((struct Obj10984 *)p)->f34); CLACT_ReleaseCharacter(((struct Obj10984 *)p)->f2C); CLACT_ReleasePalette(((struct Obj10984 *)p)->f30); }
