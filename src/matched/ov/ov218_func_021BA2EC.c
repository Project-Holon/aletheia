/*
 * function: UN_SELECT_ReleaseActors
 * address: 0x021BA2EC
 * packet: pkt_ov218_021BA2EC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj01983.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern void CLACT_ReleaseCharacter(u32);extern void CLACT_ReleasePalette(u32);extern void CLACT_ReleaseCellAnim(u32);
void UN_SELECT_ReleaseActors(char *p){if(((struct Obj01983 *)p)->f2D0!=-1)CLACT_ReleaseCharacter(((struct Obj01983 *)p)->f2D0);if(((struct Obj01983 *)p)->f2D4!=-1)CLACT_ReleasePalette(((struct Obj01983 *)p)->f2D4);if(((struct Obj01983 *)p)->f2D8!=-1)CLACT_ReleaseCellAnim(((struct Obj01983 *)p)->f2D8);}
