/*
 * function: ITEMMENU_DestroyMovingCursor
 * address: 0x021B9DE8
 * packet: pkt_ov070_021B9DE8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj01041.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
void ITEMMENU_DestroyMovingCursor(char *p) { if (((struct Obj01041 *)p)->f6A0) { CLACT_DeleteActor(((struct Obj01041 *)p)->f6A0); CLACT_ReleaseCharacter(*(unsigned *)&((struct Obj01041 *)p)->f54C); CLACT_ReleasePalette(*(unsigned *)&((struct Obj01041 *)p)->f548); ((struct Obj01041 *)p)->f6A0 = 0; } }
