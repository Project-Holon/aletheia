/*
 * function: MYSTERY_DeleteCardView
 * address: 0x021D8CA8
 * packet: pkt_ov121_021D8CA8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware access at 021D8CB2
 * symbols:
 *   MYSTERY_IsParticleCreated 0x021D6D7C thumb ov121
 *   MYSTERY_DeleteParticle 0x021D6D38 thumb ov121
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
extern void *MYSTERY_IsParticleCreated(u8 *p);
extern void MYSTERY_DeleteParticle(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void MI_CpuFill8(void *,int,int);
void MYSTERY_DeleteCardView(u8 *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(MYSTERY_IsParticleCreated(p+280)) MYSTERY_DeleteParticle(p+280);
    func_02040588(2,0);
    CLACT_DeleteActor(((struct Obj08088 *)p)->f4);
    CLACT_ReleasePalette((u32)(((struct Obj08088 *)p)->fC));
    CLACT_ReleaseCharacter((u32)(((struct Obj08088 *)p)->f10));
    CLACT_ReleaseCellAnim((u32)(((struct Obj08088 *)p)->f14));
    MI_CpuFill8(p,0,300);
}
