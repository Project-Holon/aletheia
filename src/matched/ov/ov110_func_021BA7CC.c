/*
 * function: PMS_INPUT_VIEW_TaskWordwinToEdit
 * address: 0x021BA7CC
 * packet: pkt_ov110_021BA7CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021BA8C2, followed by existing 021BA8C4.
 * prototype: retain visibly loaded unused r0 arguments to BB804 and BC728; BF7C4's live return is read through its 02024158 forwarder.
 * symbols:
 *   PMSIV_WORDWIN_IsPickAnimDone 0x021C00FC thumb ov110
 *   PMSIV_MENU_ShowEditEntries 0x021BCB50 thumb ov110
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMSIV_WORDWIN_StartClose 0x021BFB7C thumb ov110
 *   PMSIV_EDIT_StartPanelScroll 0x021BBEF4 thumb ov110
 *   PMSIV_WORDWIN_FinishClose 0x021BFBA0 thumb ov110
 *   PMSIV_EDIT_StepPanelScroll 0x021BBF54 thumb ov110
 *   PMSIV_CATEGORY_ResetBgScroll 0x021BB804 thumb ov110
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 *   PMSIV_CATEGORY_StartBlendIn 0x021BB870 thumb ov110
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_CATEGORY_IsBlendInDone 0x021BB8AC thumb ov110
 *   PMSIV_CATEGORY_StartFadeOut 0x021BB814 thumb ov110
 *   PMSIV_CATEGORY_IsFadeOutDone 0x021BB82C thumb ov110
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMSIV_EDIT_NoopB 0x021BC728 thumb ov110
 *   PMSIV_EDIT_PressCursor 0x021BC6F8 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01247.h"
#include "../include/Obj03238.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int PMSIV_WORDWIN_IsPickAnimDone(u8 *);
struct Object;
extern void PMSIV_MENU_ShowEditEntries(struct Object *p);
extern void PMSIV_WORDWIN_SetVisible(u8 *, unsigned);
extern void PMSIV_WORDWIN_StartClose(u8 *p);
extern void PMSIV_EDIT_StartPanelScroll(u8 *, u8);
extern int PMSIV_WORDWIN_FinishClose(u8 *);
extern int PMSIV_EDIT_StepPanelScroll(u8 *);
extern void PMSIV_CATEGORY_ResetBgScroll(u8 *);
extern void PMS_INPUT_VIEW_LoadBgPalette(u8 *, int);
extern void PMSIV_CATEGORY_StartBlendIn(u8 *);
extern u32 PMS_INPUT_HasInitialSentence(u8 *);
extern u32 PMS_INPUT_GetInputMode(u8 *);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *, int);
extern int PMSIV_CATEGORY_IsBlendInDone(u8 *);
extern void PMSIV_CATEGORY_StartFadeOut(u8 *p);
extern int PMSIV_CATEGORY_IsFadeOutDone(u8 *);
extern void PMSIV_EDIT_Redraw(void *);
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern void PMSIV_EDIT_NoopB(u8 *);
extern void PMSIV_EDIT_PressCursor(void *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskWordwinToEdit(void *unused, u8 *p)
{
    u8 *q;
    int a, b;
    q = *(u8 * *)&((struct Obj03238 *)p)->f0;
    switch (((struct Obj03238 *)p)->f14) {
    case 0:
        ++((struct Obj03238 *)p)->f14;
        break;
    case 1:
        if (PMSIV_WORDWIN_IsPickAnimDone(*(u8 * *)&((struct Obj01247 *)q)->f5C)) {
            PMSIV_MENU_ShowEditEntries((struct Object *)(*(u8 * *)&((struct Obj01247 *)q)->f64));
            PMSIV_WORDWIN_SetVisible(*(u8 * *)&((struct Obj01247 *)q)->f5C, 0);
            PMSIV_WORDWIN_StartClose(*(u8 * *)&((struct Obj01247 *)q)->f5C);
            PMSIV_EDIT_StartPanelScroll(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 2:
        a = PMSIV_WORDWIN_FinishClose(*(u8 * *)&((struct Obj01247 *)q)->f5C);
        b = PMSIV_EDIT_StepPanelScroll(*(u8 * *)&((struct Obj01247 *)q)->f54);
        if (a && b) {
            PMSIV_CATEGORY_ResetBgScroll(*(u8 * *)&((struct Obj01247 *)q)->f58);
            PMS_INPUT_VIEW_LoadBgPalette(*(u8 * *)&((struct Obj03238 *)p)->f0, 0);
            PMSIV_CATEGORY_StartBlendIn(*(u8 * *)&((struct Obj01247 *)q)->f58);
            if (PMS_INPUT_HasInitialSentence(*(u8 * *)&((struct Obj03238 *)p)->f4) || PMS_INPUT_GetInputMode(*(u8 * *)&((struct Obj03238 *)p)->f4) != 2) PMS_INPUT_VIEW_PrintHelpMessage(p, 1);
            else PMS_INPUT_VIEW_PrintHelpMessage(p, 0);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 3:
        if (PMSIV_CATEGORY_IsBlendInDone(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            PMSIV_CATEGORY_StartFadeOut(*(u8 * *)&((struct Obj01247 *)q)->f58);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 4:
        if (PMSIV_CATEGORY_IsFadeOutDone(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            PMSIV_EDIT_Redraw(*(u8 * *)&((struct Obj01247 *)q)->f54);
            PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            PMSIV_EDIT_NoopB(*(u8 * *)&((struct Obj01247 *)q)->f54);
            PMSIV_EDIT_PressCursor(*(u8 * *)&((struct Obj01247 *)q)->f54);
            q[0x74] = 0;
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
