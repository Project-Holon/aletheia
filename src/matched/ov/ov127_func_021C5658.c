/*
 * function: WF2DMAP_OBJDRAW_DeleteSprite
 * address: 0x021C5658
 * packet: pkt_ov127_021C5658
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_ReleaseCells 0x021C4010 thumb ov127
 */
#include "../include/Obj23044.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIFI_2DCHAR_ReleaseCells(u8 *p);
void WF2DMAP_OBJDRAW_DeleteSprite(void *p) { WIFI_2DCHAR_ReleaseCells(((struct Obj23044 *)p)->f0); }
