/*
 * function: EVENT_RESEARCH_RADAR_CloseInfoWindow
 * address:  0x021672B4
 * packet:   pkt_021672B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj00565.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_ClearMsgWin();
extern int FIELD_MSGBG_GetMsgWinBmpWin();
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern int func_020409B4();

int EVENT_RESEARCH_RADAR_CloseInfoWindow(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)t4)->f14;
    a0 = FIELD_MSGBG_ClearMsgWin(a0);
loc_021672BE:
a0 = ((struct Obj00565 *)t4)->f14;
    a0 = FIELD_MSGBG_GetMsgWinBmpWin(a0);
loc_021672C4:
    a0 = func_02045730((struct Descriptor *)a0);
loc_021672C8:
    a0 = func_020409B4(a0);
loc_021672CC:
    return a0;}
