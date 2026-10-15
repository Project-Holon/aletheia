/*
 * unit: yes
 * function: MB_SEQ_CloseMailDetail, MB_SEQ_OpenConfirmMenuKind0
 * address: 0x021C6FD4
 * packet: pkt_ov136_021C6FD4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_SEQ_ClearMailDetailText 0x021C7360 thumb ov136
 *   MB_SEQ_MoveCursorToPosition 0x021C76D0 thumb ov136
 *   MB_SEQ_EmptyHookDetailReturn 0x021C61D0 thumb ov136
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb ov136
 *   MB_SEQ_SetButtonsEnabled 0x021C7298 thumb ov136
 *   MB_SEQ_OpenMenuKind 0x021C71BC thumb ov136
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  arm9
 */
#include "../include/Obj01066.h"
#include "../include/Obj23628.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void MB_SEQ_ClearMailDetailText(u8 *);
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void MB_SEQ_MoveCursorToPosition(u8 *p, u32 v);
extern void MB_SEQ_EmptyHookDetailReturn(void *);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void MB_SEQ_SetActorVisible(u8 *p, int i, u32 v);
extern void MB_SEQ_SetButtonsEnabled(void *, int);
extern int MB_SEQ_OpenMenuKind(u8 *p, int v);
int MB_SEQ_CloseMailDetail(u8 *p)
{
    MB_SEQ_ClearMailDetailText(p);
    MB_SEQ_MoveCursorToPosition(p, CURSOR_MOVE_GetCurrent(((struct Obj23628 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294));
    MB_SEQ_EmptyHookDetailReturn(((struct Obj01066 *)p)->f8);
    BGWINFRM_HideFrame(**(void ** *)&((struct Obj01066 *)p)->f8, 10);
    MB_SEQ_SetActorVisible(((struct Obj01066 *)p)->f8, 2, 1);
    MB_SEQ_SetButtonsEnabled(((struct Obj01066 *)p)->f8, 0);
    return 9;
}
int MB_SEQ_OpenConfirmMenuKind0(char *p)
{
    return MB_SEQ_OpenMenuKind((u8 *)p, 0);
}
