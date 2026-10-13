/*
 * function: ITEMMENU_RedrawList
 * address: 0x021B6138
 * packet: pkt_ov070_021B6138
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   ITEMMENU_DrawMoveInfo 0x021B9850 thumb ov070
 *   ITEMMENU_HideMoveInfo 0x021B9AAC thumb ov070
 *   ITEMMENU_PrintItemList 0x021BA218 thumb ov070
 *   ITEMMENU_UpdatePocketSortIcon 0x021B81F4 thumb ov070
 */
#include "../include/Obj20660.h"
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void ITEMMENU_DrawMoveInfo(char *p);
extern void ITEMMENU_HideMoveInfo(char *p);
extern void ITEMMENU_PrintItemList(char *p);
extern void ITEMMENU_UpdatePocketSortIcon(u8 *p);
void ITEMMENU_RedrawList(char *p)
{
    if (func_020355C4() == 0)
        ITEMMENU_DrawMoveInfo(p);
    else
        ITEMMENU_HideMoveInfo(p);
    ITEMMENU_PrintItemList(p);
    ITEMMENU_UpdatePocketSortIcon((u8 *)p);
    ((struct Obj20660 *)p)->f83E = 1;
}
