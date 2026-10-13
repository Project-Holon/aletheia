/*
 * function: POKELIST_EndMessageToEvolve
 * address: 0x021BA4E4
 * packet: pkt_ov091_021BA4E4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 */
#include "../include/Obj13246.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
void POKELIST_EndMessageToEvolve(u8 *p) { PLIST_MESSAGE_CloseWindow(p, (u32 *)(((struct Obj13246 *)p)->f150)); p[12]=14; }
