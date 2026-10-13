/*
 * function: func_021D6D5C
 * address: 0x021D6D5C
 * packet: pkt_ov123_021D6D5C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj01544.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern u32 func_02020E60(u32 item, u32 which);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021D6D5C(u8 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f34=(void *)CLACT_RegisterPaletteEx(h,func_02020E60(1,2),0,256,0,1,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f50=(void *)CLACT_RegisterCharacter(h,func_02020E60(1,1),0,0,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f6C=(void *)CLACT_RegisterCellAnim(h,1,0,((struct Obj01544 *)p)->f43C4);
    ARC_TOOL_DeleteHandle(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    ((struct Obj01544 *)p)->fB8=CLACT_CreateActor((void *)((struct Obj01544 *)p)->fC,(unsigned int)((struct Obj01544 *)p)->f50,*(u32 *)&((struct Obj01544 *)p)->f34,*(u32 *)&((struct Obj01544 *)p)->f6C,&pt,0,((struct Obj01544 *)p)->f43C4);
    CLACT_SetActorAutoAnim(((struct Obj01544 *)p)->fB8,0);
    CLACT_SetActorDrawEnable(((struct Obj01544 *)p)->fB8,0);
}
