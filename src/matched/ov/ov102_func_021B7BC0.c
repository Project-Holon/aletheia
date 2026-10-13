/*
 * function: func_021B7BC0
 * address: 0x021B7BC0
 * packet: pkt_ov102_021B7BC0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * CLACT_DeleteActor 0x0204B3B4 arm
 * CLACT_ReleasePalette 0x0204ADA4 arm
 * CLACT_ReleaseCharacter 0x0204A8D4 arm
 * CLACT_ReleaseCellAnim 0x0204AFD8 arm
 * CLACT_DeleteUnit 0x0204B1CC arm
 * CLACT_ExitSystem 0x0204A5AC arm
 * MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07973.h"
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,unsigned);
void func_021B7BC0(void *p) {
 int i;
 for(i=0;i<32;i++) {
  if(*(void **)((char *)p+16+i*4)) CLACT_DeleteActor(*(void **)((char *)p+16+i*4));
 }
 CLACT_ReleasePalette(((struct Obj07973 *)p)->f4);
 CLACT_ReleaseCharacter(((struct Obj07973 *)p)->f8);
 CLACT_ReleaseCellAnim(((struct Obj07973 *)p)->fC);
 CLACT_DeleteUnit(((struct Obj07973 *)p)->f0);
 CLACT_ExitSystem();
 MI_CpuFill8(p,0,0x90);
}
