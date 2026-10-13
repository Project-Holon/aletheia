/*
 * function: func_021DD5AC
 * address: 0x021DD5AC
 * packet: pkt_ov137_021DD5AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * CLACT_CreateActor 0x0204B294 arm
 * CLACT_SetActorAutoAnim 0x0204B92C arm
 * CLACT_SetActorAnimSeq 0x0204B878 arm
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * BG_SYS_SetMainPlaneVisible 0x020434DC arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * d_021E1B08 0x021E1B08 data a2
 */
#include "../include/Obj14208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021E1B08[];
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
void func_021DD5AC(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=d_021E1B08[i*2+2]; s.b=d_021E1B08[i*2+3];
        *(u32 *)(p+i*4+156)=(u32)CLACT_CreateActor((void *)((struct Obj14208 *)p)->f68,*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),((struct Obj14208 *)p)->f94,&s,0,114);
        CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p+i*4+156),1);
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p+i*4+156)),0);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p+i*4+156),0);
    }
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,0);
}
