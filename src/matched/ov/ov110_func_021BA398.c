/*
 * function: PMS_INPUT_VIEW_TaskRefreshCategory
 * address: 0x021BA398
 * packet: pkt_ov110_021BA398
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMSIV_CATEGORY_RefreshScreens 0x021BB8D8 thumb ov110
 *   PMSIV_CATEGORY_ApplyBgOffset 0x021BB8B8 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMSIV_CATEGORY_IsReady 0x021BB954 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj06384.h"
#include "../include/Obj06385.h"
typedef unsigned char u8;
extern void PMSIV_MENU_ShowWordEntries(u8 *);
extern void PMSIV_CATEGORY_RefreshScreens(u8 *);
extern void PMSIV_CATEGORY_ApplyBgOffset(u8 *);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_CATEGORY_DrawTitle(char *p);
extern int PMSIV_CATEGORY_IsReady(u8 *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskRefreshCategory(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj06384 *)p)->f0;
    switch (((struct Obj06384 *)p)->f14) {
    case 0:
        ++((struct Obj06384 *)p)->f14;
    case 1:
        PMSIV_MENU_ShowWordEntries(*(u8 * *)&((struct Obj06385 *)q)->f64);
        PMSIV_CATEGORY_RefreshScreens(*(u8 * *)&((struct Obj06385 *)q)->f58);
        PMSIV_CATEGORY_ApplyBgOffset(*(u8 * *)&((struct Obj06385 *)q)->f58);
        if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj06384 *)p)->f4) == 1) PMSIV_CATEGORY_DrawTitle((char *)(*(u8 * *)&((struct Obj06385 *)q)->f58));
        ++((struct Obj06384 *)p)->f14;
        break;
    case 2:
        if (PMSIV_CATEGORY_IsReady(*(u8 * *)&((struct Obj06385 *)q)->f58)) PMS_INPUT_VIEW_EndTask(p);
        break;
    }
}
