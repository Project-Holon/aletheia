/*
 * function: MAILSYS_StepIncompleteNotice
 * address: 0x021C483C
 * packet: pkt_ov136_021C483C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C48FA..0x021C48FC is a zero alignment halfword.
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   MAILSYS_PrintMessageText 0x021C47C4 thumb ov136
 *   MAILSYS_ResetCursorBlend 0x021C44FC thumb ov136
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
#include "../include/Obj01413.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
struct Rec3;
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void MAILSYS_PrintMessageText(u8 *, int);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern void MAILSYS_ResetCursorBlend(u8 *);
int MAILSYS_StepIncompleteNotice(u8 *p)
{
    void *q;
    switch (((struct Obj01413 *)p)->f8) {
    case 0:
        APP_TASKMENU_WIN_SetDecide(((struct Obj01413 *)p)->f128, 1);
        APP_TASKMENU_WIN_SetActive(((struct Obj01413 *)p)->f12C, 0);
        ((struct Obj01413 *)p)->f8 = 1;
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish(((struct Obj01413 *)p)->f128) != 0) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj01413 *)p)->f128);
            APP_TASKMENU_WIN_SetActive(((struct Obj01413 *)p)->f128, 1);
            MAILSYS_PrintMessageText(p, 2);
            ((struct Obj01413 *)p)->f8 = 2;
        }
        break;
    case 2:
        if (PRINTSYS_PrintStreamGetState(((struct Obj01413 *)p)->f9C) == 2) {
            if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
                PRINTSYS_PrintStreamDelete(((struct Obj01413 *)p)->f9C);
                ((struct Obj01413 *)p)->f8 = 3;
            }
        }
        break;
    case 3:
        BMP_MENUWORK_DrawWindowBorder(((struct Obj01413 *)p)->f5C, 2);
        q = ((struct Obj01413 *)p)->f5C;
        BMP_WIN_ClearScreen(q);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
        MAILSYS_ResetCursorBlend(p);
        ((struct Obj01413 *)p)->f8 = 0;
        p[0xB] = p[0xC];
        break;
    }
    return 0;
}
