/*
 * function: PMSIV_MENU_IsEntry1Done
 * address: 0x021BCE70
 * packet: pkt_ov110_021BCE70
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCE9E.
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 */
#include "../include/Obj06390.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern u32 PMSIV_MENU_IsEntryFinished(char *,u32);
struct Obj;
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
int PMSIV_MENU_IsEntry1Done(char *p) { int result; if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { result=1; if (PMSIV_MENU_IsEntryFinished(p,1)) { APP_TASKMENU_WIN_ResetDecide(((struct Obj06390 *)p)->f68); return result; } } else { return 1; } return 0; }
