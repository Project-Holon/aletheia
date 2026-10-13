/*
 * function: func_021D8CA8
 * address: 0x021D8CA8
 * packet: pkt_ov121_021D8CA8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware access at 021D8CB2
 * symbols:
 *   func_021D6D7C 0x021D6D7C thumb ov121
 *   func_021D6D38 0x021D6D38 thumb ov121
 *   func_02040588 0x02040588 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj08088.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void *func_021D6D7C(u8 *p);
extern void func_021D6D38(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void MI_CpuFill8(void *,int,int);
void func_021D8CA8(u8 *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(func_021D6D7C(p+280)) func_021D6D38(p+280);
    func_02040588(2,0);
    CLACT_DeleteActor(((struct Obj08088 *)p)->f4);
    CLACT_ReleasePalette((u32)(((struct Obj08088 *)p)->fC));
    CLACT_ReleaseCharacter((u32)(((struct Obj08088 *)p)->f10));
    CLACT_ReleaseCellAnim((u32)(((struct Obj08088 *)p)->f14));
    MI_CpuFill8(p,0,300);
}
