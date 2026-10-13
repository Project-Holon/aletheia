/*
 * function: func_021B9C4C
 * address: 0x021B9C4C
 * packet: pkt_ov221_021B9C4C
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: 4B294 forwards CFDC's live r0 object result despite legacy void declaration.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021B9F90 0x021B9F90 thumb ov221
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021BA140 0x021BA140 data a2
 */
#include "../include/Obj01592.h"
#include "../include/G_Vec2.h"
typedef unsigned short u16;

struct Obj; extern struct Vec2 d_021BA140;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned func_021B9F90(char *p);
extern struct Obj *CLACT_CreateActor(void *,unsigned,unsigned,unsigned,const void *,unsigned short,unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
void func_021B9C4C(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f4C=CLACT_RegisterPaletteEx((void *)((unsigned)h),0,0,0,0,2,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f48=CLACT_RegisterCharacter((void *)((unsigned)h),3,0,0,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f50=CLACT_RegisterCellAnim((void *)((unsigned)h),8,9,((struct Obj01592 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
    *(struct Obj * *)&((struct Obj01592 *)p)->f54=CLACT_CreateActor((void *)func_021B9F90(((struct Obj01592 *)p)->f8),((struct Obj01592 *)p)->f48,((struct Obj01592 *)p)->f4C,((struct Obj01592 *)p)->f50,&d_021BA140,0,((struct Obj01592 *)p)->f0);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
}
