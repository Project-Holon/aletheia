/*
 * function: PMS_INPUT_VIEW_TaskShowCategory
 * address: 0x021BA2D8
 * packet: pkt_ov110_021BA2D8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMS_INPUT_ResetSearch 0x021BF7E0 thumb ov110
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMSIV_EDIT_ReleaseCursor 0x021BC6EC thumb ov110
 *   PMSIV_EDIT_NoopA 0x021BC724 thumb ov110
 *   PMSIV_CATEGORY_StartFadeIn 0x021BB76C thumb ov110
 *   PMSIV_EDIT_StartPanelScroll 0x021BBEF4 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_CATEGORY_IsFadeInDone 0x021BB784 thumb ov110
 *   PMSIV_EDIT_StepPanelScroll 0x021BBF54 thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01921.h"
#include "../include/Obj03748.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern u16 PMS_INPUT_GetWordSlot(u8 *);
extern void PMSIV_EDIT_PlaceCursorAtSlot(char *p, int i);
extern void PMS_INPUT_ResetSearch(u8 *);
extern void PMSIV_MENU_ShowWordEntries(u8 *);
extern void PMSIV_EDIT_ReleaseCursor(void *p);
extern void PMSIV_EDIT_NoopA(u8 *);
extern void PMSIV_CATEGORY_StartFadeIn(u8 *);
extern void PMSIV_EDIT_StartPanelScroll(u8 *p, u8 value);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_CATEGORY_DrawTitle(char *p);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *, int);
extern int PMSIV_CATEGORY_IsFadeInDone(u8 *);
extern int PMSIV_EDIT_StepPanelScroll(u8 *);
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_MoveCursor(u8 *, unsigned int);
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *, int);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskShowCategory(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj03748 *)p)->f0;
    int a, b;
    switch (((struct Obj03748 *)p)->f14) {
    case 0:
        PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj01921 *)q)->f54, 1);
        PMSIV_EDIT_PlaceCursorAtSlot((char *)(*(u8 * *)&((struct Obj01921 *)q)->f54), PMS_INPUT_GetWordSlot(*(u8 * *)&((struct Obj03748 *)p)->f4));
        ++((struct Obj03748 *)p)->f14;
        break;
    case 1:
        PMS_INPUT_ResetSearch(*(u8 * *)&((struct Obj03748 *)p)->f4);
        PMSIV_MENU_ShowWordEntries(*(u8 * *)&((struct Obj01921 *)q)->f64);
        PMSIV_EDIT_ReleaseCursor(*(u8 * *)&((struct Obj01921 *)q)->f54);
        PMSIV_EDIT_NoopA(*(u8 * *)&((struct Obj01921 *)q)->f54);
        PMSIV_CATEGORY_StartFadeIn(*(u8 * *)&((struct Obj01921 *)q)->f58);
        PMSIV_EDIT_StartPanelScroll(*(u8 * *)&((struct Obj01921 *)q)->f54, 0);
        if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03748 *)p)->f4) == 1) PMSIV_CATEGORY_DrawTitle((char *)(*(u8 * *)&((struct Obj01921 *)q)->f58));
        if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03748 *)p)->f4) == 0) PMS_INPUT_VIEW_PrintHelpMessage(p, 2);
        else PMS_INPUT_VIEW_PrintHelpMessage(p, 4);
        ++((struct Obj03748 *)p)->f14;
        break;
    case 2:
        a = PMSIV_CATEGORY_IsFadeInDone(*(u8 * *)&((struct Obj01921 *)q)->f58);
        b = PMSIV_EDIT_StepPanelScroll(*(u8 * *)&((struct Obj01921 *)q)->f54);
        if (a && b) {
            PMSIV_CATEGORY_MoveCursor(*(u8 * *)&((struct Obj01921 *)q)->f58, PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj01921 *)q)->f18));
            PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01921 *)q)->f58, 1);
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
