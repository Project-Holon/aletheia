/*
 * function: PMS_INPUT_VIEW_TaskCategoryToMenu
 * address: 0x021BA4CC
 * packet: pkt_ov110_021BA4CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: F7C4 tail-forwards p[0] to ARM9 24158, whose full body returns a
 *   bit test; A570 consumes the live r0. C728 retains its visible unused r0.
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_MENU_PressBackButton 0x021BD000 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_MENU_IsBackButtonDone 0x021BD028 thumb ov110
 *   PMSIV_MENU_ShowEditEntries 0x021BCB50 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMSIV_CATEGORY_StartClose 0x021BB7A0 thumb ov110
 *   PMSIV_EDIT_StartPanelScroll 0x021BBEF4 thumb ov110
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_CATEGORY_StepClose 0x021BB7B8 thumb ov110
 *   PMSIV_EDIT_StepPanelScroll 0x021BBF54 thumb ov110
 *   PMSIV_EDIT_NoopB 0x021BC728 thumb ov110
 *   PMSIV_EDIT_PressCursor 0x021BC6F8 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01530.h"
#include "../include/Obj03237.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
struct Object;
extern void PMSIV_MENU_StartPress(char *p, u32 mode);
extern void PMSIV_CATEGORY_ShowWordList(u8 *,int);
extern int PMSIV_MENU_PressBackButton(char *p);
extern int PMSIV_CATEGORY_IsListReady(u8 *,int);
extern int PMSIV_MENU_IsPressDone(char *p, u32 mode);
extern int PMSIV_MENU_IsBackButtonDone(u8 *);
extern void PMSIV_MENU_ShowEditEntries(struct Object *p);
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *,int);
extern void PMSIV_CATEGORY_StartClose(u8 *);
extern void PMSIV_EDIT_StartPanelScroll(u8 *,u8);
extern u32 PMS_INPUT_HasInitialSentence(u8 *);
extern u32 PMS_INPUT_GetInputMode(u8 *);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *,int);
extern int PMSIV_CATEGORY_StepClose(u8 *);
extern int PMSIV_EDIT_StepPanelScroll(u8 *);
extern void PMSIV_EDIT_NoopB(u8 *);
extern void PMSIV_EDIT_PressCursor(void *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskCategoryToMenu(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03237 *)p)->f0;
    int a,b;
    switch(((struct Obj03237 *)p)->f14) {
    case 0:
        if(PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            PMSIV_MENU_StartPress((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
            PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        } else PMSIV_MENU_PressBackButton((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        ++((struct Obj03237 *)p)->f14;
        break;
    case 1:
        if(PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            a=PMSIV_CATEGORY_IsListReady(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
            b=PMSIV_MENU_IsPressDone((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
        } else {
            a=PMSIV_MENU_IsBackButtonDone(*(u8 * *)&((struct Obj01530 *)q)->f64);
            b=1;
        }
        if(a && b) ++((struct Obj03237 *)p)->f14;
        break;
    case 2:
        PMSIV_MENU_ShowEditEntries((struct Object *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        PMSIV_CATEGORY_StartClose(*(u8 * *)&((struct Obj01530 *)q)->f58);
        PMSIV_EDIT_StartPanelScroll(*(u8 * *)&((struct Obj01530 *)q)->f54,1);
        if(PMS_INPUT_HasInitialSentence(*(u8 * *)&((struct Obj03237 *)p)->f4) || PMS_INPUT_GetInputMode(*(u8 * *)&((struct Obj03237 *)p)->f4)!=2) PMS_INPUT_VIEW_PrintHelpMessage(p,1);
        else PMS_INPUT_VIEW_PrintHelpMessage(p,0);
        ++((struct Obj03237 *)p)->f14;
        break;
    case 3:
        a=PMSIV_CATEGORY_StepClose(*(u8 * *)&((struct Obj01530 *)q)->f58);
        b=PMSIV_EDIT_StepPanelScroll(*(u8 * *)&((struct Obj01530 *)q)->f54);
        if(a && b) {
            PMSIV_EDIT_NoopB(*(u8 * *)&((struct Obj01530 *)q)->f54);
            PMSIV_EDIT_PressCursor(*(u8 * *)&((struct Obj01530 *)q)->f54);
            q[0x74]=0;
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
