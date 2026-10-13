/*
 * function: PMS_INPUT_VIEW_TaskRefreshCategoryMenu
 * address: 0x021BAA8C
 * packet: pkt_ov110_021BAA8C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_MENU_UpdateEntryPalettes 0x021BCD80 thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj06386.h"
#include "../include/Obj07998.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetInitialCount(u8 *p);
extern void PMSIV_MENU_UpdateEntryPalettes(u8 *);
extern void PMSIV_CATEGORY_DrawTitle(char *p);
extern void PMSIV_CATEGORY_ShowWordList(u8 *,int);
extern int PMSIV_CATEGORY_IsListReady(u8 *,int);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskRefreshCategoryMenu(void *unused,u8 *p) {
    u8 *q;
    u32 x;
    q=*(u8 * *)&((struct Obj06386 *)p)->f0;
    x=PMS_INPUT_GetInitialCount(*(u8 * *)&((struct Obj06386 *)p)->f4);
    switch(((struct Obj06386 *)p)->f14) {
    case 0:
        PMSIV_MENU_UpdateEntryPalettes(*(u8 * *)&((struct Obj07998 *)q)->f64);
        PMSIV_CATEGORY_DrawTitle((char *)(*(u8 * *)&((struct Obj07998 *)q)->f58));
        PMSIV_CATEGORY_ShowWordList(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0);
        ++((struct Obj06386 *)p)->f14;
        break;
    case 1:
        if(PMSIV_CATEGORY_IsListReady(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0)) ++((struct Obj06386 *)p)->f14;
        break;
    case 2: PMS_INPUT_VIEW_EndTask(p); break;
    }
}
