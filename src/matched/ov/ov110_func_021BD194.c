/*
 * function: PMSIV_MENU_CreateBackButton
 * address: 0x021BD194
 * packet: pkt_ov110_021BD194
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PMS_INPUT_VIEW_GetClactUnit 0x021BAC40 thumb ov110
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj02462.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y,z; u8 a,b; } Params;
extern unsigned int func_020275E4(void);
typedef unsigned int   u32;
struct Obj;
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PMS_INPUT_VIEW_GetClactUnit(u8 *p);
extern struct Obj *CLACT_CreateActor(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void PMSIV_MENU_CreateBackButton(u8 *p) {
    void *h;
    int a;
    Params t;
    h=func_020490F4(func_020275E4(),42);
    ((struct Obj02462 *)p)->f1C=(void *)CLACT_RegisterPaletteEx(h,func_02027614(),0,384,0,3,42);
    ((struct Obj02462 *)p)->f20=(void *)CLACT_RegisterCharacter(h,func_02027618(),0,0,42);
    a=func_0202761C(1);
    ((struct Obj02462 *)p)->f24=(void *)CLACT_RegisterCellAnim(h,a,func_02027620(1),42);
    ARC_TOOL_DeleteHandle(h);
    MI_CpuFill8(&t,0,8);
    t.x=232; t.y=168; t.z=1; t.a=0; t.b=3;
    ((struct Obj02462 *)p)->f28=CLACT_CreateActor((void *)PMS_INPUT_VIEW_GetClactUnit(((struct Obj02462 *)p)->f0),(u32)((struct Obj02462 *)p)->f20,(u32)((struct Obj02462 *)p)->f1C,(u32)((struct Obj02462 *)p)->f24,&t,0,42);
    CLACT_SetActorAutoAnim(((struct Obj02462 *)p)->f28,1);
    CLACT_SetActorDrawEnable(((struct Obj02462 *)p)->f28,0);
    ((struct Obj02462 *)p)->f2C=0;
}
