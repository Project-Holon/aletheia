/*
 * function: func_021B9CE4
 * address: 0x021B9CE4
 * packet: pkt_ov222_021B9CE4
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype evidence: B294 returns live r0 consumed by store/B3DC; BA028 result feeds B294; AF28 heap visibly u16.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_021BA028 0x021BA028 thumb ov222
 *   d_021BA1D8 0x021BA1D8 data a4
 */
#include "../include/Obj01593.h"

typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_021BA1D8[];
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
typedef signed int     s32;
struct Obj;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void*);
extern u32 func_021BA028(char *p);
extern struct Obj *CLACT_CreateActor(void*,u32,u32,u32,const void*,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void func_021B9CE4(char*p)
{
 u32 t;
 void *h;
 h=func_020490F4(0xca,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f4C=CLACT_RegisterPaletteEx(h,0,0,0,0,2,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f48=CLACT_RegisterCharacter(h,3,0,0,((struct Obj01593 *)p)->f0);
 *(int *)&((struct Obj01593 *)p)->f50=CLACT_RegisterCellAnim(h,8,9,((struct Obj01593 *)p)->f0);
 ARC_TOOL_DeleteHandle((void*)h);
 t=func_021BA028(*(void* *)&((struct Obj01593 *)p)->f8);
 *(void* *)&((struct Obj01593 *)p)->f54=CLACT_CreateActor((void*)t,((struct Obj01593 *)p)->f48,((struct Obj01593 *)p)->f4C,((struct Obj01593 *)p)->f50,d_021BA1D8,0,((struct Obj01593 *)p)->f0);
 CLACT_SetActorDrawEnable(*(void* *)&((struct Obj01593 *)p)->f54,1);
 CLACT_SetActorAutoAnim(*(void* *)&((struct Obj01593 *)p)->f54,1);
}
