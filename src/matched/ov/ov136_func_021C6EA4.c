/*
 * function: MB_SEQ_StateActionMenu
 * address:  0x021C6EA4
 * packet:   pkt_ov136_021C6EA4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008FA4 0x02008FA4 thumb
 *   func_020213AC 0x020213AC thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   MB_SEQ_CloseMenu 0x021C5B30 thumb
 *   MB_SEQ_EmptyHookDetailClose 0x021C61CC thumb
 *   MB_SEQ_HideMessageWindow 0x021C62F4 thumb
 *   MB_SEQ_PrintMenuMessage 0x021C630C thumb
 *   MB_SEQ_SetActorAnim 0x021C66A0 thumb
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 *   MB_SEQ_ShowCursorActor 0x021C6884 thumb
 *   MB_SEQ_StartFadeOut 0x021C7178 thumb
 *   MB_SEQ_SetMessageWait 0x021C71A8 thumb
 *   MB_SEQ_SetButtonsEnabled 0x021C7298 thumb
 *   MB_SEQ_SetDetailButtons 0x021C730C thumb
 *   MB_SEQ_LoadMailDetail 0x021C7350 thumb
 *   MB_SEQ_CreatePartyListArgs 0x021C7430 thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23624.h"
#include "../include/Obj23625.h"
#include "../include/Obj23626.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void APP_TASKMENU_UpdateMenu(void *);
struct Sub02008F80Obj;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void MB_SEQ_CloseMenu(u8 *);
extern void MB_SEQ_HideMessageWindow(u8 *);
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
extern void MB_SEQ_EmptyHookDetailClose(u8 *);
extern void MB_SEQ_ShowCursorActor(u8 *);
extern void MB_SEQ_LoadMailDetail(u8 *);
extern void MB_SEQ_SetActorAnim(u8 *p, int i, u32 v);
extern void MB_SEQ_SetDetailButtons(void *p);
extern void MB_SEQ_PrintMenuMessage(u8 *p, unsigned int i);
extern int MB_SEQ_SetMessageWait(char *p, int v, int w);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u16 func_020213AC(u32);
extern void MB_SEQ_CreatePartyListArgs(u8 *, int, u16, u16);
extern int MB_SEQ_StartFadeOut(u8 *, u32);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void MB_SEQ_SetButtonsEnabled(void *p, int v);
int MB_SEQ_StateActionMenu(u8 *p)
{
    APP_TASKMENU_UpdateMenu(((struct Obj23624 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310);
    if (APP_TASKMENU_IsFinish(((struct Obj23625 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310) == 0) {
        return 0xE;
    }
    switch (APP_TASKMENU_GetCursorPos(((struct Obj23626 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310)) {
    case 0:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_HideMessageWindow(p);
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
        MB_SEQ_EmptyHookDetailClose(*(u8 * *)&((struct Obj00127 *)p)->f8);
        MB_SEQ_ShowCursorActor(*(u8 * *)&((struct Obj00127 *)p)->f8);
        MB_SEQ_LoadMailDetail(p);
        MB_SEQ_SetActorAnim(*(u8 * *)&((struct Obj00127 *)p)->f8, 7, 0xE);
        MB_SEQ_SetDetailButtons(*(u8 * *)&((struct Obj00127 *)p)->f8);
        return 0xF;
    case 1:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_PrintMenuMessage(p, 0);
        return MB_SEQ_SetMessageWait((char *)p, 0, 0x11);
    case 2: {
        u8 k;
        MB_SEQ_CloseMenu(p);
        k = p[0x1F];
        MB_SEQ_CreatePartyListArgs(p, 0xE, func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct Obj00127 *)p)->f8 + k * 4 + 0x298))), k);
        ((struct Obj00127 *)p)->f14 = 0;
        ((struct Obj00127 *)p)->f28 = 6;
        return MB_SEQ_StartFadeOut(p, 1);
    }
    case -2:
    case 3:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_HideMessageWindow(p);
        BGWINFRM_HideFrame(**(void ** *)&((struct Obj00127 *)p)->f8, 10);
        MB_SEQ_SetButtonsEnabled(*(u8 * *)&((struct Obj00127 *)p)->f8, 0);
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 1);
        return 9;
    default:
        return 0xE;
    }
}
