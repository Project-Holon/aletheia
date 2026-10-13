/*
 * unit: yes
 * function: PMSIV_MENU_IsEntry2Done, PMSIV_MENU_PressBackItem
 * address: 0x021BCDFC
 * packet: pkt_ov110_021BCDFC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 *   PMSIV_MENU_SetItemAnim 0x021BD0F8 thumb ov110
 */
#include "../include/Obj06390.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern u32 PMSIV_MENU_IsEntryFinished(char *,u32);
extern void PMSIV_MENU_SetItemAnim(u8 *p, int i, int flag);
int PMSIV_MENU_IsEntry2Done(char *p) { if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { if (PMSIV_MENU_IsEntryFinished(p,2)) return 1; return 0; } return 1; }
void PMSIV_MENU_PressBackItem(void *p) { PMSIV_MENU_SetItemAnim(p,7,1); }
