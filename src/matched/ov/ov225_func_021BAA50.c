/*
 * function: func_021BAA50
 * address: 0x021BAA50
 * packet: pkt_ov225_021BAA50
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_021BAA88 0x021BAA88 thumb ov225
 */
#include "../include/Obj08470.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void func_021BAA88(char *);
void func_021BAA50(char *p) { u8 i; func_021BAA88(p); for(i=0;i<8;i++) CLACT_DeleteActor(*(struct Obj **)(p+i*4+0x60)); CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08470 *)p)->f5C); CLACT_ReleaseCellAnim(((struct Obj08470 *)p)->f58); CLACT_ReleaseCharacter(((struct Obj08470 *)p)->f50); CLACT_ReleasePalette(((struct Obj08470 *)p)->f54); }
