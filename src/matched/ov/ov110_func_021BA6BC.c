/*
 * function: PMS_INPUT_VIEW_TaskWordwinToCategory
 * address: 0x021BA6BC
 * packet: pkt_ov110_021BA6BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write the BB9C0 call in both conditional arms to keep the empty-arm branch and register allocation.
 * prototype: BF7FC's live r0 is read despite its void owner declaration; full BB1C0 target is a byte getter.
 * symbols:
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_MENU_PressBackButton 0x021BD000 thumb ov110
 *   PMSIV_MENU_IsBackButtonDone 0x021BD028 thumb ov110
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMSIV_WORDWIN_StartClose 0x021BFB7C thumb ov110
 *   PMSIV_WORDWIN_FinishClose 0x021BFBA0 thumb ov110
 *   PMSIV_CATEGORY_ApplyBgOffset 0x021BB8B8 thumb ov110
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 *   PMSIV_CATEGORY_StartBlendIn 0x021BB870 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_CATEGORY_IsBlendInDone 0x021BB8AC thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01531.h"
#include "../include/Obj02164.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetInitialCount(u8 *);
extern int PMSIV_MENU_PressBackButton(char *p);
extern int PMSIV_MENU_IsBackButtonDone(u8 *);
extern void PMSIV_MENU_ShowWordEntries(u8 *);
extern void PMSIV_WORDWIN_SetVisible(u8 *, unsigned);
extern void PMSIV_WORDWIN_StartClose(u8 *p);
extern int PMSIV_WORDWIN_FinishClose(u8 *);
extern void PMSIV_CATEGORY_ApplyBgOffset(u8 *);
extern void PMS_INPUT_VIEW_LoadBgPalette(u8 *, int);
extern void PMSIV_CATEGORY_StartBlendIn(u8 *);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_CATEGORY_ShowWordList(u8 *, int);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *, int);
extern int PMSIV_CATEGORY_IsBlendInDone(u8 *);
extern int PMSIV_CATEGORY_IsListReady(u8 *, int);
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_MoveCursor(u8 *, unsigned);
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *, int);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskWordwinToCategory(void *unused, u8 *p)
{
    u8 *q;
    int a, b, flag;
    u32 enabled;
    q = *(u8 * *)&((struct Obj02164 *)p)->f0;
    enabled = PMS_INPUT_GetInitialCount(*(u8 * *)&((struct Obj02164 *)p)->f4);
    switch (((struct Obj02164 *)p)->f14) {
    case 0:
        PMSIV_MENU_PressBackButton((char *)(*(u8 * *)&((struct Obj01531 *)q)->f64));
        ++((struct Obj02164 *)p)->f14;
        break;
    case 1:
        if (PMSIV_MENU_IsBackButtonDone(*(u8 * *)&((struct Obj01531 *)q)->f64)) ++((struct Obj02164 *)p)->f14;
        break;
    case 2:
        PMSIV_MENU_ShowWordEntries(*(u8 * *)&((struct Obj01531 *)q)->f64);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 3:
        PMSIV_WORDWIN_SetVisible(*(u8 * *)&((struct Obj01531 *)q)->f5C, 0);
        PMSIV_WORDWIN_StartClose(*(u8 * *)&((struct Obj01531 *)q)->f5C);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 4:
        if (PMSIV_WORDWIN_FinishClose(*(u8 * *)&((struct Obj01531 *)q)->f5C)) {
            PMSIV_CATEGORY_ApplyBgOffset(*(u8 * *)&((struct Obj01531 *)q)->f58);
            ++((struct Obj02164 *)p)->f14;
        }
        break;
    case 5:
        PMS_INPUT_VIEW_LoadBgPalette(*(u8 * *)&((struct Obj02164 *)p)->f0, 0);
        flag = 0;
        PMSIV_CATEGORY_StartBlendIn(*(u8 * *)&((struct Obj01531 *)q)->f58);
        if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) {
            flag = 0;
            PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        } else {
            if (enabled) flag = 1;
            PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        }
        if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) PMS_INPUT_VIEW_PrintHelpMessage(p, 2);
        else PMS_INPUT_VIEW_PrintHelpMessage(p, 4);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 6:
        a = PMSIV_CATEGORY_IsBlendInDone(*(u8 * *)&((struct Obj01531 *)q)->f58);
        b = PMSIV_CATEGORY_IsListReady(*(u8 * *)&((struct Obj01531 *)q)->f58, enabled != 0);
        if (a && b) {
            PMSIV_CATEGORY_MoveCursor(*(u8 * *)&((struct Obj01531 *)q)->f58, PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj01531 *)q)->f18));
            PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01531 *)q)->f58, 1);
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
