/*
 * function: MB_SEQ_CancelDetail
 * address:  0x021C7110
 * packet:   pkt_ov136_021C7110
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   MB_SEQ_HideMessageWindow 0x021C62F4 thumb
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 *   MB_SEQ_SetButtonsEnabled 0x021C7298 thumb
 *   MB_SEQ_MoveCursorToPosition 0x021C76D0 thumb
 */
#include "../include/Obj01066.h"
#include "../include/Obj23635.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void MB_SEQ_HideMessageWindow(u8 *);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void MB_SEQ_MoveCursorToPosition(u8 *p, u32 v);
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
extern void MB_SEQ_SetButtonsEnabled(void *p, int v);
int MB_SEQ_CancelDetail(u8 *p)
{
    MB_SEQ_HideMessageWindow(p);
    BGWINFRM_HideFrame(**(void ** *)&((struct Obj01066 *)p)->f8, 10);
    MB_SEQ_MoveCursorToPosition(p, CURSOR_MOVE_GetCurrent(((struct Obj23635 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294));
    MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 1);
    MB_SEQ_SetButtonsEnabled(*(u8 * *)&((struct Obj01066 *)p)->f8, 0);
    return 9;
}
