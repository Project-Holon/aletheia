/*
 * function: func_021D4698
 * address: 0x021D4698
 * packet: pkt_ov124_021D4698
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u32 func_020307B0(void *p);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
void func_021D4698(char *p) {func_020307B0(((struct Obj00991 *)p)->f44);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj00991 *)p)->f5C);CLACT_ReleasePalette(((struct Obj00991 *)p)->f50);CLACT_ReleaseCharacter(((struct Obj00991 *)p)->f54);CLACT_ReleaseCellAnim(((struct Obj00991 *)p)->f58);}
