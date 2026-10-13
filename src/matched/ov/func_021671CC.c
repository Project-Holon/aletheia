/*
 * function: EVENT_RESEARCH_RADAR_DeleteInfoWindow
 * address:  0x021671CC
 * packet:   pkt_021671CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb
 */
#include "../include/Obj00565.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_DeleteMsgWin();

int EVENT_RESEARCH_RADAR_DeleteInfoWindow(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)t4)->f14;
    a0 = FIELD_MSGBG_DeleteMsgWin(a0);
loc_021671D6:
a0 = 0;
((struct Obj00565 *)t4)->f14 = a0;
    return a0;}
