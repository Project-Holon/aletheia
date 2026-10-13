/*
 * function: PMS_INPUT_VIEW_TaskMenuToCategory
 * address: 0x021BA3F0
 * packet: pkt_ov110_021BA3F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: CF70 forwards its legacy third argument only to CE48, whose full
 *   body ignores it and calls D0F8(p,7,0); original A448 sets only r0/r1.
 * symbols:
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_MENU_FinishPress 0x021BCF70 thumb ov110
 *   PMS_INPUT_ResetSearch 0x021BF7E0 thumb ov110
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMSIV_CATEGORY_RefreshScreens 0x021BB8D8 thumb ov110
 *   PMSIV_CATEGORY_ApplyBgOffset 0x021BB8B8 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMSIV_CATEGORY_IsReady 0x021BB954 thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj01711.h"
#include "../include/Obj03749.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void PMSIV_MENU_StartPress(char *p, u32 mode);
extern void PMSIV_CATEGORY_ShowWordList(u8 *,int);
extern int PMSIV_CATEGORY_IsListReady(u8 *,int);
extern int PMSIV_MENU_IsPressDone(char *p, u32 mode);
extern void PMSIV_MENU_FinishPress(u8 *,int);
extern void PMS_INPUT_ResetSearch(u8 *);
extern void PMSIV_MENU_ShowWordEntries(u8 *);
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *,int);
extern void PMSIV_CATEGORY_RefreshScreens(u8 *);
extern void PMSIV_CATEGORY_ApplyBgOffset(u8 *);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_CATEGORY_DrawTitle(char *p);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *,int);
extern int PMSIV_CATEGORY_IsReady(u8 *);
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_MoveCursor(u8 *,unsigned);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskMenuToCategory(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03749 *)p)->f0;
    int a,b;
    switch(((struct Obj03749 *)p)->f14) {
    case 0:
        PMSIV_MENU_StartPress((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        ++((struct Obj03749 *)p)->f14;
        break;
    case 1:
        a=PMSIV_CATEGORY_IsListReady(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        b=PMSIV_MENU_IsPressDone((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        if(a && b) {
            PMSIV_MENU_FinishPress(*(u8 * *)&((struct Obj01711 *)q)->f64,1);
            PMS_INPUT_ResetSearch(*(u8 * *)&((struct Obj03749 *)p)->f4);
            PMSIV_MENU_ShowWordEntries(*(u8 * *)&((struct Obj01711 *)q)->f64);
            PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
            PMSIV_CATEGORY_RefreshScreens(*(u8 * *)&((struct Obj01711 *)q)->f58);
            PMSIV_CATEGORY_ApplyBgOffset(*(u8 * *)&((struct Obj01711 *)q)->f58);
            if(PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03749 *)p)->f4)==1) PMSIV_CATEGORY_DrawTitle((char *)(*(u8 * *)&((struct Obj01711 *)q)->f58));
            if(PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj03749 *)p)->f4)==0) PMS_INPUT_VIEW_PrintHelpMessage(p,2);
            else PMS_INPUT_VIEW_PrintHelpMessage(p,4);
            ++((struct Obj03749 *)p)->f14;
        }
        break;
    case 2:
        if(PMSIV_CATEGORY_IsReady(*(u8 * *)&((struct Obj01711 *)q)->f58)) ++((struct Obj03749 *)p)->f14;
        break;
    case 3:
        PMSIV_CATEGORY_MoveCursor(*(u8 * *)&((struct Obj01711 *)q)->f58,PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj01711 *)q)->f18));
        PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj01711 *)q)->f58,1);
        PMS_INPUT_VIEW_EndTask(p);
        break;
    }
}
