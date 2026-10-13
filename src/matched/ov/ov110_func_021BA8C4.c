/*
 * function: PMS_INPUT_VIEW_TaskCloseWordwin
 * address: 0x021BA8C4
 * packet: pkt_ov110_021BA8C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMSIV_WORDWIN_StartClose 0x021BFB7C thumb ov110
 *   PMSIV_WORDWIN_FinishClose 0x021BFBA0 thumb ov110
 *   PMSIV_CATEGORY_ResetBgScroll 0x021BB804 thumb ov110
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 *   PMSIV_CATEGORY_StartBlendIn 0x021BB870 thumb ov110
 *   PMSIV_CATEGORY_IsBlendInDone 0x021BB8AC thumb ov110
 *   PMSIV_CATEGORY_StartFadeOut 0x021BB814 thumb ov110
 *   PMSIV_CATEGORY_IsFadeOutDone 0x021BB82C thumb ov110
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj02815.h"
#include "../include/Obj05288.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void PMSIV_WORDWIN_SetVisible(u8 *p, unsigned visible);
extern void PMSIV_WORDWIN_StartClose(u8 *p);
extern int PMSIV_WORDWIN_FinishClose(u8 *p);
extern void PMSIV_CATEGORY_ResetBgScroll(u8 *a0);
extern void PMS_INPUT_VIEW_LoadBgPalette(u8 *,int);
extern void PMSIV_CATEGORY_StartBlendIn(u8 *p);
extern int PMSIV_CATEGORY_IsBlendInDone(u8 *p);
extern void PMSIV_CATEGORY_StartFadeOut(u8 *p);
extern int PMSIV_CATEGORY_IsFadeOutDone(u8 *p);
extern void PMSIV_EDIT_Redraw(void *);
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskCloseWordwin(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj05288 *)p)->f0;
    switch(((struct Obj05288 *)p)->f14) {
    case 0:
        PMSIV_WORDWIN_SetVisible((u8 *)(*(u32 *)&((struct Obj02815 *)q)->f5C),0);
        PMSIV_WORDWIN_StartClose(((struct Obj02815 *)q)->f5C);
        ++((struct Obj05288 *)p)->f14; break;
    case 1:
        if(PMSIV_WORDWIN_FinishClose(((struct Obj02815 *)q)->f5C)) {
            PMSIV_CATEGORY_ResetBgScroll(((struct Obj02815 *)q)->f58);
            PMS_INPUT_VIEW_LoadBgPalette(*(u8 * *)&((struct Obj05288 *)p)->f0,0);
            PMSIV_CATEGORY_StartBlendIn(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 2:
        if(PMSIV_CATEGORY_IsBlendInDone(((struct Obj02815 *)q)->f58)) {
            PMSIV_CATEGORY_StartFadeOut(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 3:
        if(PMSIV_CATEGORY_IsFadeOutDone(((struct Obj02815 *)q)->f58)) {
            PMSIV_EDIT_Redraw(((struct Obj02815 *)q)->f54);
            PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj02815 *)q)->f54,0);
            PMS_INPUT_VIEW_EndTask(p);
        } break;
    }
}
