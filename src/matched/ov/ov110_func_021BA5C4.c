/*
 * function: PMS_INPUT_VIEW_TaskCategoryToWordwin
 * address: 0x021BA5C4
 * packet: pkt_ov110_021BA5C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 246 matched bytes, then two zero alignment bytes at 021BA6BA.
 * symbols:
 *   PMSIV_CATEGORY_IsSelectAnimDone 0x021BBC10 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_CATEGORY_StartBlendOut 0x021BB838 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMSIV_CATEGORY_IsBlendOutDone 0x021BB854 thumb ov110
 *   PMSIV_MENU_ShowOnlyBackButton 0x021BCC88 thumb ov110
 *   PMSIV_WORDWIN_DrawList 0x021BF9F0 thumb ov110
 *   PMSIV_WORDWIN_StartOpen 0x021BFAA0 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_WORDWIN_IsOpen 0x021BFB58 thumb ov110
 *   PMS_INPUT_GetCursorCell 0x021BF784 thumb ov110
 *   PMSIV_WORDWIN_SetCursorCell 0x021BFC64 thumb ov110
 *   PMS_INPUT_GetTopRow 0x021BF7AC thumb ov110
 *   PMS_INPUT_GetMaxTopRow 0x021BF7B8 thumb ov110
 *   PMSIV_WORDWIN_SetThumbRow 0x021BFDB0 thumb ov110
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01142.h"
#include "../include/Obj04442.h"
typedef unsigned char u8;
extern int PMSIV_CATEGORY_IsSelectAnimDone(u8 *);
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *,int);
typedef unsigned int   u32;
extern void PMSIV_MENU_StartPress(char *p, u32 mode);
extern int PMSIV_MENU_IsPressDone(char *p, u32 mode);
extern void PMSIV_CATEGORY_StartBlendOut(u8 *);
extern void PMSIV_CATEGORY_ShowWordList(u8 *,int);
extern int PMSIV_CATEGORY_IsListReady(u8 *,int);
extern int PMSIV_CATEGORY_IsBlendOutDone(u8 *);
extern void PMSIV_MENU_ShowOnlyBackButton(u8 *);
extern void PMSIV_WORDWIN_DrawList(u8 *);
extern void PMSIV_WORDWIN_StartOpen(u8 *);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *,int);
extern int PMSIV_WORDWIN_IsOpen(u8 *);
extern unsigned PMS_INPUT_GetCursorCell(u8 *);
extern void PMSIV_WORDWIN_SetCursorCell(u8 *,unsigned);
extern unsigned PMS_INPUT_GetTopRow(u8 *);
extern unsigned PMS_INPUT_GetMaxTopRow(u8 *);
extern void PMSIV_WORDWIN_SetThumbRow(u8 *,unsigned,unsigned);
extern void PMSIV_WORDWIN_SetVisible(u8 *,unsigned);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskCategoryToWordwin(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj04442 *)p)->f0;
    int a,b;
    switch(((struct Obj04442 *)p)->f14) {
    case 0:
        ++((struct Obj04442 *)p)->f14;
        break;
    case 1:
        if(PMSIV_CATEGORY_IsSelectAnimDone(*(u8 * *)&((struct Obj01142 *)q)->f58)) {
            PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            PMSIV_MENU_StartPress((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 2:
        if(PMSIV_MENU_IsPressDone((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3)) {
            PMSIV_CATEGORY_StartBlendOut(*(u8 * *)&((struct Obj01142 *)q)->f58);
            PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 3:
        a=PMSIV_CATEGORY_IsListReady(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
        b=PMSIV_CATEGORY_IsBlendOutDone(*(u8 * *)&((struct Obj01142 *)q)->f58);
        if(a && b) {
            PMSIV_MENU_ShowOnlyBackButton(*(u8 * *)&((struct Obj01142 *)q)->f64);
            PMSIV_WORDWIN_DrawList(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            PMSIV_WORDWIN_StartOpen(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            if(PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj04442 *)p)->f4)==0) PMS_INPUT_VIEW_PrintHelpMessage(p,3);
            else PMS_INPUT_VIEW_PrintHelpMessage(p,5);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 4:
        if(PMSIV_WORDWIN_IsOpen(*(u8 * *)&((struct Obj01142 *)q)->f5C)) {
            unsigned x;
            PMSIV_WORDWIN_SetCursorCell(*(u8 * *)&((struct Obj01142 *)q)->f5C,PMS_INPUT_GetCursorCell(*(u8 * *)&((struct Obj01142 *)q)->f18));
            x=PMS_INPUT_GetTopRow(*(u8 * *)&((struct Obj01142 *)q)->f18);
            PMSIV_WORDWIN_SetThumbRow(*(u8 * *)&((struct Obj01142 *)q)->f5C,x,PMS_INPUT_GetMaxTopRow(*(u8 * *)&((struct Obj01142 *)q)->f18));
            PMSIV_WORDWIN_SetVisible(*(u8 * *)&((struct Obj01142 *)q)->f5C,1);
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
