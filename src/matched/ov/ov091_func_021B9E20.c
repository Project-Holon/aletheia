/*
 * unit: yes
 * function: POKELIST_CloseMessageToList, POKELIST_EndMessageToExit
 * address: 0x021B9E20
 * packet: pkt_ov091_021B9E20
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 *   POKELIST_SetupModeScreen 0x021B7B98 thumb ov091
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void POKELIST_SetupModeScreen(u8 *);
void POKELIST_CloseMessageToList(u8 *p) { PLIST_MESSAGE_CloseWindow(p,(u32 *)(*(u32 *)&((struct Obj00009 *)p)->f150)); p[12]=2; POKELIST_SetupModeScreen(p); }
void POKELIST_EndMessageToExit(u8 *p) { p[12]=19; }
