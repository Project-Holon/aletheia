/*
 * function: MUSICAL_SHOT_INFO_Delete
 * address: 0x021F4300
 * packet: pkt_ov112_021F4300
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte padding at 0x021F434E.
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   MUSICAL_SHOT_INFO_DeleteWindows 0x021F4748 thumb ov112
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   func_020307B0 0x020307B0 arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 */
#include "../include/Obj04456.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Bank;
struct Obj;
struct TaskMenuState;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void MUSICAL_SHOT_INFO_DeleteWindows(u8 *);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 func_020307B0(void *p);
void MUSICAL_SHOT_INFO_Delete(u8 *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj04456 *)p)->f40));
    if (((struct Obj04456 *)p)->fC==0) {
        CLACT_ReleasePalette(((struct Obj04456 *)p)->f4C);
        CLACT_ReleaseCharacter(((struct Obj04456 *)p)->f50);
        CLACT_ReleaseCellAnim(((struct Obj04456 *)p)->f54);
        CLACT_DeleteActor((struct Obj *)(((struct Obj04456 *)p)->f58));
    }
    CLACT_DeleteUnit((struct Bank *)(((struct Obj04456 *)p)->f48));
    MUSICAL_SHOT_INFO_DeleteWindows(p);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    func_020307B0(p);
}
