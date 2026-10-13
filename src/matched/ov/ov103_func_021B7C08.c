/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExitSprites
 * address: 0x021B7C08
 * packet: pkt_ov103_021B7C08
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07981.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p); extern void CLACT_ReleasePalette(int); extern void CLACT_ReleaseCharacter(int); extern void CLACT_ReleaseCellAnim(int); extern int CLACT_DeleteUnit(int); extern void CLACT_ExitSystem(int); extern void MI_CpuFill8(void *,int,int);
void IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(u8 *p) { int i; for(i=0;i<33;i++) { if(*(int *)(p+16+i*4)) CLACT_DeleteActor((struct Obj *)(*(int *)(p+16+i*4))); } CLACT_ReleasePalette(((struct Obj07981 *)p)->f4); CLACT_ReleaseCharacter(((struct Obj07981 *)p)->f8); CLACT_ReleaseCellAnim(((struct Obj07981 *)p)->fC); CLACT_ExitSystem(CLACT_DeleteUnit(((struct Obj07981 *)p)->f0)); MI_CpuFill8(p,0,0x94); }
