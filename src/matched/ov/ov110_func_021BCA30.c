/*
 * function: PMSIV_MENU_Delete
 * address: 0x021BCA30
 * packet: pkt_ov110_021BCA30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * symbols:
 *   PMSIV_MENU_HideAll 0x021BCAD8 thumb ov110
 *   PMSIV_MENU_Reserved 0x021BD344 thumb ov110
 *   PMSIV_MENU_DeleteExtraItems 0x021BD174 thumb ov110
 *   PMSIV_MENU_DeleteItems 0x021BD0D4 thumb ov110
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 */
#include "../include/Obj00295.h"
typedef unsigned char u8;
extern void PMSIV_MENU_HideAll(u8 *);
extern void PMSIV_MENU_Reserved(u8 *);
extern void PMSIV_MENU_DeleteExtraItems(u8 *);
extern void PMSIV_MENU_DeleteItems(u8 *);
struct Obj;
struct Rec;
struct TaskMenuState;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);
void PMSIV_MENU_Delete(u8 *p)
{
    int i;
    PMSIV_MENU_HideAll(p);
    CLACT_DeleteActor(((struct Obj00295 *)p)->f28);
    CLACT_ReleasePalette((u32)(((struct Obj00295 *)p)->f1C));
    CLACT_ReleaseCharacter((u32)(((struct Obj00295 *)p)->f20));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00295 *)p)->f24));
    for (i=0;i<3;i++) APP_TASKMENU_RES_Delete(*(void **)(p+0x34+i*4));
    PMSIV_MENU_Reserved(p); PMSIV_MENU_DeleteExtraItems(p); PMSIV_MENU_DeleteItems(p);
    MSGDATA_Delete(((struct Obj00295 *)p)->f30);
    func_020307B0(p);
}
