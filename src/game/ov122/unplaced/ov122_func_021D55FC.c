/*
 * function: func_021D55FC
 * address: 0x021D55FC
 * packet: pkt_ov122_021D55FC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: intended code ends 021D5704; remaining handed extent is rodata.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   NET_WHPIPE_SetNotifyCallback 0x02178118 thumb ov014
 *   func_021D4AD4 0x021D4AD4 thumb ov122
 *   TCBL_Destroy 0x02031140 arm
 *   func_020403F4 0x020403F4 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../../matched/include/Obj00911.h"
#include "../../../matched/include/Obj22936.h"
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_GetRunState(void);
extern void NET_WHPIPE_SetNotifyCallback(u32, u32);
extern void func_021D4AD4(char *);
struct Bank;
struct Descriptor;
struct Node;
struct Obj;
struct PrintSys;
struct Rec3;
struct S02031140;
struct S020315D4;
struct TaskMenu;
struct TaskMenuState;
struct WordSet;
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_020403F4(u32 i);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021D55FC(void *a, void *b, char *out, char *p)
{
    int i;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback(0, 0);
    func_021D4AD4(p);
    ((struct Obj22936 *)out)->f20 = ((struct Obj00911 *)p)->f8;
    TCBL_Destroy(((struct Obj00911 *)p)->f31C);
    func_020403F4(5);
    PRINTSYS_QUE_Clear(((struct Obj00911 *)p)->f320);
    PRINTSYS_QUE_Delete(((struct Obj00911 *)p)->f320);
    for (i = 0; i < 3; i++) CLACT_DeleteActor(*(void **)(p + i * 4 + 0x390));
    CLACT_DeleteActor(((struct Obj00911 *)p)->f39C);
    CLACT_DeleteActor(((struct Obj00911 *)p)->f3A0);
    CLACT_DeleteActor(((struct Obj00911 *)p)->f3A4);
    CLACT_ReleasePalette((u32)(((struct Obj00911 *)p)->f378));
    CLACT_ReleaseCharacter((u32)(((struct Obj00911 *)p)->f37C));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00911 *)p)->f380));
    func_02030EAC(((struct Obj00911 *)p)->f310);
    CLACT_DeleteUnit(((struct Obj00911 *)p)->f30C);
    CLACT_ExitSystem();
    if (((struct Obj00911 *)p)->f318) PRINTSYS_PrintStreamDelete(((struct Obj00911 *)p)->f318);
    func_0201ED04(((struct Obj00911 *)p)->f48);
    if (((struct Obj00911 *)p)->f324) {
        APP_TASKMENU_CloseMenu(((struct Obj00911 *)p)->f324);
        ((struct Obj00911 *)p)->f324 = 0;
    }
    if (((struct Obj00911 *)p)->f314) BMP_WIN_Delete(((struct Obj00911 *)p)->f314);
    APP_TASKMENU_RES_Delete(((struct Obj00911 *)p)->f340);
    BMP_WIN_Exit();
    func_0203F9B4();
    func_020315D4(a);
    func_020306F0(31);
    return 1;
}
