/*
 * unit: no
 * function: B_PLIST_DRAW_ShowToolWindows
 * address: 0x0220E25C
 * packet: pkt_ov198_0220E25C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_APP_TOOL_ShowWindows 0x0220B094 thumb ov196
 *   B_PLIST_DRAW_ShowSubWindow 0x0220E27C thumb ov198
 */
#include "../include/Obj03351.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void B_APP_TOOL_ShowWindows(char *,u8 *);extern void B_PLIST_DRAW_ShowSubWindow(u8 *);
void B_PLIST_DRAW_ShowToolWindows(u8 *p){B_APP_TOOL_ShowWindows((char *)p+0x1f70,*(u8 * *)&((struct Obj03351 *)p)->f253C);B_PLIST_DRAW_ShowSubWindow(p);}
