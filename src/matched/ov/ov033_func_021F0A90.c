/*
 * function: DOWSING_DeleteCloseButton
 * address: 0x021F0A90
 * packet: pkt_ov033_021F0A90
 * region: ov033
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
 *   func_0203FB44 0x0203FB44 arm
 *   INFOWIN_Exit 0x02024DCC thumb
 */
#include "../include/Obj06143.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern int INFOWIN_Exit(void);
void DOWSING_DeleteCloseButton(char *p) { unsigned v; CLACT_DeleteActor((struct Obj *)(((struct Obj06143 *)p)->f24)); CLACT_ReleaseCellAnim(((struct Obj06143 *)p)->f20); CLACT_ReleaseCharacter(((struct Obj06143 *)p)->f1C); CLACT_ReleasePalette(((struct Obj06143 *)p)->f18); v=((struct Obj06143 *)p)->f14; func_0203FB44(4,(unsigned short)v,(unsigned short)(v>>16)); INFOWIN_Exit(); }
