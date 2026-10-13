/*
 * function: PMS_INPUT_VIEW_GetMenuResult
 * address: 0x021BAC0C
 * packet: pkt_ov110_021BAC0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 */
#include "../include/Obj13776.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
typedef unsigned int   u32;
extern u32 PMSIV_MENU_IsEntryFinished(char *p, u32 index);
int PMS_INPUT_VIEW_GetMenuResult(u8 *p) { if((int)PMSIV_MENU_IsEntryFinished((char *)(*(u8 * *)&((struct Obj13776 *)p)->f64),(u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj13776 *)p)->f18))) return 1; return -1; }
